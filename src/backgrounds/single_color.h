#ifndef SINGLE_COLOR_H
#define SINGLE_COLOR_H

#include <background.h>

class SingleColor: public Background
{
public:
    SingleColor(const std::string &name): Background(name), color(0)
    {
    }

    SingleColor(): color(0)
    {
    }

    ~SingleColor() {}

    virtual Color getL(const Ray &) const
    {
        return color;
    }

    virtual void deserialize(TiXmlElement *element)
    {
        TiXmlAttribute *attr = element->FirstAttribute();

        while (attr)
        {
            std::string name(attr->Name());

            if (name == "color")
            {
                parseColor(attr, color);
            }

            attr = attr->Next();
        }
    }

    virtual Background *clone() const
    {
        return new SingleColor(*this);
    }

private:
    static SingleColor prototype;

    Color color;
};

#endif
