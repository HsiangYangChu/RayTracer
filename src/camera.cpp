#include <camera.h>
#include <texture.h>
#include <viewplane.h>
#include <world.h>

Camera::Prototypes &Camera::getPrototypes()
{
    static Prototypes prototypes;

    return prototypes;
}

Camera::Camera(const std::string &name):
  world(World::getInstance()), d(1), eye(0, 0, 0), look_at(0, 0, -1), up(0, 1, 0),
  is_built(false)
{
    getPrototypes().insert(std::make_pair(name, this));
}

Camera::Camera():
  world(World::getInstance()), d(1), eye(0, 0, 0), look_at(0, 0, -1), up(0, 1, 0),
  is_built(false)
{
}

Camera::Texture_ptr Camera::renderScene()
{
    if (!is_built)
    {
        build();
        is_built = true;
    }

    const ViewPlane &vp = world.vp;

    auto texture = Texture::create(vp.hres, vp.vres, 32);

    //printf("0.00\%\r");
    //fflush(stdout);

    for (uint r = 0; r < vp.vres; r++)
    {
        for (uint c = 0; c < vp.hres; c++)
        {
            world.displayPixel(c, r, renderPixel(c, r), texture);
        }

        //printf("%.2f\%\r", (r + 1) * 100.0 / vp.vres);
        //fflush(stdout);
    }

    return texture;
}

void Camera::setEye(const vec3 &l_eye)
{
    eye = l_eye;
}

void Camera::setLookAt(const vec3 &l_look_at)
{
    look_at = l_look_at;
}

void Camera::computeUVW()
{
    w = glm::normalize(eye - look_at);
    u = glm::normalize(glm::cross(up, w));
    v = glm::cross(w, u);
}

void Camera::setUp(const vec3 &l_up)
{
    up = l_up;
}

void Camera::setDistance(FLOAT l_d)
{
    d = l_d;
}

vec3 Camera::rayDirection(const vec3 &dir) const
{
    return u * dir.x + v * dir.y + w * dir.z;
}

void Camera::build()
{
    computeUVW();
}

Camera::Camera_ptr Camera::create(TiXmlElement *element)
{
    if (!element)
    {
        return Camera_ptr();
    }

    Prototypes &prototypes = getPrototypes();

    std::string name(element->Value());
    auto it = prototypes.find(name);

    if (it == prototypes.end())
    {
        return Camera_ptr();
    }

    Camera_ptr camera = Camera_ptr(it->second->clone());

    if (camera)
    {
        camera->deserialize(element);
    }

    return camera;
}
