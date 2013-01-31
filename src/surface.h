#ifndef SURFACE_H
#define SURFACE_H

#include <string>

struct SDL_Surface;
struct sRGB;

class cSurface
{
public:
  cSurface();

  static SDL_Surface* load(const std::string file);
  static SDL_Surface* load(const std::string file, const sRGB& transparency);
  static void free(SDL_Surface *surface);
};

#endif // SURFACE_H
