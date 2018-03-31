#include <objects/compound.h>
#include <intersection.h>

Compound::Compound(const std::string &name): Object(name), is_bbox_set(false)
{
}

Compound::Compound(): is_bbox_set(false)
{
}

bool Compound::hit(const Ray &ray, Intersection &is) const
{
    is.t = INFINITY;
    float is_hit = false;

    Intersection is_obj(is.w);

    for (uint i = 0; i < objects.size(); i++)
    {
        if (objects[i]->hit(ray, is_obj) && is_obj < is)
        {
            is_hit = true;
            material = objects[i]->getMaterial();
            is = is_obj;
        }
    }

    return is_hit;
}

bool Compound::shadowHit(const Ray &ray, FLOAT &tmin) const
{
    tmin = INFINITY;

    FLOAT t;
    bool is_hit = false;

    for (uint i = 0; i < objects.size(); i++)
    {
        if (objects[i]->shadowHit(ray, t) && t < tmin)
        {
            tmin = t;
            is_hit = true;
        }
    }

    return is_hit;
}

void Compound::addObject(Object *object)
{
    objects.push_back(Object_ptr(object));

    recalcBBox(object);
}

void Compound::recalcBBox(Object *object)
{
    if (!is_bbox_set)
    {
        bbox = object->getBBox();
        is_bbox_set = true;
    }
    else
    {
        BBox obj_bbox = object->getBBox();

        bbox.p0 = glm::min(bbox.p0, obj_bbox.p0);
        bbox.p1 = glm::max(bbox.p1, obj_bbox.p1);
    }
}

void Compound::setMaterial(const Material_ptr &l_material)
{
    for (uint i = 0; i < objects.size(); i++)
    {
        objects[i]->setMaterial(l_material);
    }
}

BBox Compound::getBBox() const
{
    return BBox(bbox.p0 - vec3(EPSILON), bbox.p1 + vec3(EPSILON));
}

void Compound::addObject(const Object_ptr &object)
{
    objects.push_back(object);
}
