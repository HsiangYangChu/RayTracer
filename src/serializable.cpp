#include <serializable.h>

void Serializable::parseInt(TiXmlAttribute *attr, int &i)
{
    i = attr->IntValue();
}

void Serializable::parseUint(TiXmlAttribute *attr, uint &ui)
{
    ui = attr->IntValue();
}

void Serializable::parseDouble(TiXmlAttribute *attr, double &d)
{
    d = attr->DoubleValue();
}

void Serializable::parseFloat(TiXmlAttribute *attr, float &f)
{
    f = attr->DoubleValue();
}

void Serializable::parseVec3(TiXmlAttribute *attr, vec3 &v)
{
    sscanf(attr->Value(), "(%lf,%lf,%lf)", &v.x, &v.y, &v.z);
}

void Serializable::parseColor(TiXmlAttribute *attr, Color &c)
{
    sscanf(attr->Value(), "(%f,%f,%f)", &c.r, &c.g, &c.b);
    c /= Color(255);
}

void Serializable::parseString(TiXmlAttribute *attr, const char *&s)
{
    s = attr->Value();
}

void Serializable::parseBool(TiXmlAttribute *attr, bool &b)
{
    b = attr->IntValue();
}

void Serializable::parseDoubleAttr(TiXmlElement *element, const char *name, double &d)
{
    double d_tmp;

    if (element->Attribute(name, &d_tmp))
    {
        d = d_tmp;
    }
}
