#ifndef TEXTURE_H
#define TEXTURE_H

#include <FreeImage.h>
#include <memory>
#include <mymath.h>

class Texture
{
public:
    typedef std::shared_ptr<Texture> TexturePtr;

    ~Texture();

    static TexturePtr create(uint w, uint h, uint bpp = 32);
    static TexturePtr load(const char *);
    static Color maxToOne (const Color &);
    static RGBQUAD toRgbQuad(const Color &);

    Color get(uint i, uint j) const;
    Color getPixelByUV(float, float) const;
    void set(uint i, uint j, const Color &);
    BYTE *getBits();

    void save(const char *filename, FREE_IMAGE_FORMAT format = FIF_BMP) const;


private:
    Texture(FIBITMAP *l_bitmap = NULL, uint l_w = 1, uint l_h = 1, uint l_bpp = 32):
      bitmap(l_bitmap), w(l_w), h(l_h), bpp(l_bpp)
    {
    }

    FIBITMAP *bitmap;
    uint w, h, bpp;

    uint clamp(uint, uint, uint) const;
};

#endif // TEXTURE_H
