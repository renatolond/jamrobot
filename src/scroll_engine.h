#ifndef SCROLL_ENGINE_H
#define SCROLL_ENGINE_H

struct SDL_Surface;
struct SDL_Rect;

#define NUM_SDLK_DOWN_EVENTS 322

class cScrollEngine
{
  bool m_game_running;
  bool KEYS[NUM_SDLK_DOWN_EVENTS];

  SDL_Surface *m_screen, *m_robo1, *m_robo2, *m_char, *m_bg;
  SDL_Rect *m_destination;
public:
  cScrollEngine();
  void run(void);
  void init(void);
  void render(void);
  bool update(void);
  void cleanup(void);
};

#endif // SCROLL_ENGINE_H
