#include <objects/instance.h>
#include <ray.h>
#include <intersection.h>
#include <material.h>
#include <scene_parser.h>

Instance Instance::prototype("Instance");

Instance::Instance(const std::string &name): Object(name)
{
}

bool Instance::hit(const Ray &ray, Intersection &is) const
{
    is.hit_an_object = false;

    Ray inv_ray(ray);
    inv_ray.transform(local);

    if (object->hit(inv_ray, is))
    {
        is.normal = glm::normalize(transform_normal(local, is.normal));

        Material_ptr obj_material = object->getMaterial();

        if (obj_material)
        {
            material = obj_material;
        }

        return true;
    }

    return false;
}

bool Instance::shadowHit(const Ray &ray, FLOAT &tmin) const
{
    Ray inv_ray(ray);
    inv_ray.transform(local);

    return object->shadowHit(inv_ray, tmin);
}

void Instance::translate(FLOAT dx, FLOAT dy, FLOAT dz)
{
    local *= glm::translate(mat4(1), vec3(-dx, -dy, -dz));
    setupBBox();
}

void Instance::scale(FLOAT sx, FLOAT sy, FLOAT sz)
{
    local *= glm::scale(mat4(1), vec3(1 / sx, 1 / sy, 1 / sz));
    setupBBox();
}

void Instance::rotateX(FLOAT theta)
{
    local *= glm::rotate(mat4(1), glm::radians(-theta), vec3(1, 0, 0));
    setupBBox();
}

void Instance::rotateY(FLOAT theta)
{
    local *= glm::rotate(mat4(1), glm::radians(-theta), vec3(0, 1, 0));
    setupBBox();
}

void Instance::rotateZ(FLOAT theta)
{
    local *= glm::rotate(mat4(1), glm::radians(-theta), vec3(0, 0, 1));
    setupBBox();
}

void Instance::sample(vec3 &point, vec3 &normal) const
{
    object->sample(point, normal);

    point = transform_point(glm::inverse(local), point);
    normal = glm::normalize(transform_normal(local, normal));
}

float Instance::pdf(const Intersection &is) const
{
    return object->pdf(is);
}

BBox Instance::getBBox() const
{
    return bbox;
}

void Instance::setupBBox()
{
    BBox obj_box = object->getBBox();

    mat4 world(glm::inverse(local));

    vec3 dv = obj_box.p1 - obj_box.p0;
    vec3 min(INFINITY), max(-INFINITY);

    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            for (int k = 0; k <= 1; k++)
            {
                vec3 p = transform_point(world, obj_box.p0 + dv * vec3(i, j, k));

                min = glm::min(min, p);
                max = glm::max(max, p);

            }
        }
    }

    bbox = BBox(min - vec3(EPSILON), max + vec3(EPSILON));
}

void Instance::deserialize(TiXmlElement *element)
{
    element = element->FirstChildElement();

    while (element)
    {
        std::string name(element->Value());

        if (name == "object")
        {
            object = Object::create(element);
        }
        else if (name == "material")
        {
            material = Material::create(element);
        }
        else if (name == "scale")
        {
            FLOAT x = 1, y = 1, z = 1;

            parseDoubleAttr(element, "x", x);
            parseDoubleAttr(element, "y", y);
            parseDoubleAttr(element, "z", z);

            scale(x, y, z);
        }
        else if (name == "translate")
        {
            FLOAT x = 0, y = 0, z = 0;

            parseDoubleAttr(element, "x", x);
            parseDoubleAttr(element, "y", y);
            parseDoubleAttr(element, "z", z);

            translate(x, y, z);
        }
        else if (name == "rotate_x")
        {
            FLOAT angle = 0;

            parseDoubleAttr(element, "angle", angle);
            rotateX(angle);
        }
        else if (name == "rotate_y")
        {
            FLOAT angle = 0;

            parseDoubleAttr(element, "angle", angle);
            rotateY(angle);
        }
        else if (name == "rotate_z")
        {
            FLOAT angle = 0;

            parseDoubleAttr(element, "angle", angle);
            rotateZ(angle);
        }

        assert(object);

        element = element->NextSiblingElement();
    }
}

