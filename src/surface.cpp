#include "surface.h"

#include <SDL/SDL.h>

#include "output.h"
#include "rgb.h"

cSurface::cSurface()
{
}

SDL_Surface *cSurface::load(std::string file)
{
  SDL_Surface *temp = NULL;
  SDL_Surface *ret = NULL;

  temp = SDL_LoadBMP(file.c_str());
  if(temp == NULL)
  {
    cOutput::emit_error("Could not load file: %s\n", file.c_str());
    return NULL;
  }

  ret = SDL_DisplayFormat(temp);
  if(!ret)
  {
    cOutput::emit_error("Ran out of memory loading at %s:%d!\n", __FILE__, __LINE__);
  }
  SDL_FreeSurface(temp);
  return ret;
}

SDL_Surface *cSurface::load(const std::string file, const sRGB &transparency)
{
  SDL_Surface *temp = NULL;
  SDL_Surface *ret = NULL;

  temp = SDL_LoadBMP(file.c_str());
  if(temp == NULL)
  {
    cOutput::emit_error("Could not load file: %s\n", file.c_str());
    return NULL;
  }

  SDL_SetColorKey(temp, SDL_SRCCOLORKEY, SDL_MapRGB(temp->format, transparency.r, transparency.g,
                                                    transparency.b));
  ret = SDL_DisplayFormat(temp);
  if(!ret)
  {
    cOutput::emit_error("Ran out of memory loading at %s:%d!\n", __FILE__, __LINE__);
  }
  SDL_FreeSurface(temp);
  return ret;
}

void cSurface::free(SDL_Surface *surface)
{
  SDL_FreeSurface(surface);
}

