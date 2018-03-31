#include <background.h>

Background::Prototypes &Background::getPrototypes()
{
    static Prototypes prototypes;

    return prototypes;
}

Background::Background_ptr Background::create(TiXmlElement *element)
{
    if (!element)
    {
        return Background_ptr();
    }

    Prototypes &prototypes = getPrototypes();

    std::string name(element->Value());
    auto it = prototypes.find(name);

    if (it == prototypes.end())
    {
        return Background_ptr();
    }

    Background_ptr background = Background_ptr(it->second->clone());

    if (background)
    {
        background->deserialize(element);
    }

    return background;
}
