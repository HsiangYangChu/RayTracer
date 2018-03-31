#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <mymath.h>
#include <tinyxml/tinyxml.h>
#include <string>

class Serializable
{
public:
    virtual ~Serializable() {};
    virtual void deserialize(TiXmlElement *) = 0;

protected:
    void parseInt(TiXmlAttribute *, int &);
    void parseUint(TiXmlAttribute *, uint &);
    void parseDouble(TiXmlAttribute *, double &);
    void parseFloat(TiXmlAttribute *, float &);
    void parseVec3(TiXmlAttribute *, vec3 &);
    void parseColor(TiXmlAttribute *, Color &);
    void parseString(TiXmlAttribute *, const char *&);
    void parseBool(TiXmlAttribute *, bool &);
    void parseDoubleAttr(TiXmlElement *, const char *, double &);
};

#endif
