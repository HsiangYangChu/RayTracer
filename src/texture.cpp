#include <texture.h>

Texture::~Texture()
{
    FreeImage_Unload(bitmap);
}

Texture::TexturePtr Texture::create(uint w, uint h, uint bpp)
{
    Texture *texture = new Texture(FreeImage_Allocate(w, h, bpp), w, h, bpp);
    return TexturePtr(texture);
}

Texture::TexturePtr Texture::load(const char *filename)
{
    FREE_IMAGE_FORMAT format = FreeImage_GetFileType(filename);

    if (format == FIF_UNKNOWN)
    {
        return TexturePtr();
    }

    Texture *texture = new Texture;
    texture->bitmap = FreeImage_Load(format, filename);
    texture->w = FreeImage_GetWidth(texture->bitmap);
    texture->h = FreeImage_GetHeight(texture->bitmap);
    texture->bpp = FreeImage_GetBPP(texture->bitmap);

    return TexturePtr(texture);
}

void Texture::save(const char *filename, FREE_IMAGE_FORMAT format) const
{
    FreeImage_Save(format, bitmap, filename);
}

Color Texture::get(uint i, uint j) const
{
    RGBQUAD rgb;

    FreeImage_GetPixelColor(bitmap, i, j, &rgb);

    return 1.f / 255 * Color(rgb.rgbRed, rgb.rgbGreen, rgb.rgbBlue);
}

void Texture::set(uint i, uint j, const Color &color)
{
    RGBQUAD rgb = toRgbQuad(color);

    FreeImage_SetPixelColor(bitmap, i, j, &rgb);
}

uint Texture::clamp(uint min, uint max, uint value) const
{
    return std::min(max, std::max(min, value));
}

Color Texture::getPixelByUV(float u, float v) const
{
    uint x = clamp(0, w - 1, u * w);
    uint y = clamp(0, h - 1, v * h);

    return get(x, y);
}

Color Texture::maxToOne(const Color &c)
{
    float max_c = glm::max(c[0], glm::max(c[1], c[2]));

    if (max_c > 1.0)
    {
        return 1.0f / max_c * c;
    }

    return c;
}

RGBQUAD Texture::toRgbQuad(const Color &color)
{
    RGBQUAD rgb;

    Color c = maxToOne(color) * 255.f;

    rgb.rgbRed = c[0];
    rgb.rgbGreen = c[1];
    rgb.rgbBlue = c[2];

    return rgb;
}

BYTE *Texture::getBits()
{
    return FreeImage_GetBits(bitmap);
}
