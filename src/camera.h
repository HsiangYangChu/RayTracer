#ifndef CAMERA_H
#define CAMERA_H

#include <serializable.h>
#include <memory>
#include <map>

class World;
class Texture;

struct Camera: public Serializable
{
    typedef std::shared_ptr<Texture> Texture_ptr;
    typedef std::shared_ptr<Camera> Camera_ptr;
    typedef std::map<std::string, Camera *> Prototypes;

    Camera(const std::string &);
    Camera();

    ~Camera() {}

    void setEye(const vec3 &);
    void setLookAt(const vec3 &);
    void setUp(const vec3 &);
    void computeUVW();
    void setDistance(FLOAT);
    vec3 rayDirection(const vec3 &) const;
    Texture_ptr renderScene();
    virtual Color renderPixel(uint, uint) const = 0;
    virtual void build();

    virtual Camera *clone() const = 0;

    static Camera_ptr create(TiXmlElement *);

    const World &world;
    FLOAT d;
    vec3 eye;
    vec3 look_at;
    vec3 up;
    vec3 u;
    vec3 v;
    vec3 w;
    bool is_built;

private:
    static Prototypes &getPrototypes();
};

#endif // CAMERA_H
