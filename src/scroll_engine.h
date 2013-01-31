#ifndef SCROLL_ENGINE_H
#define SCROLL_ENGINE_H

class cPlayerController;
struct SDL_Surface;
struct SDL_Rect;

#define NUM_SDLK_DOWN_EVENTS 322

class cScrollEngine
{
  bool m_game_running;
  bool KEYS[NUM_SDLK_DOWN_EVENTS];

  SDL_Surface *m_screen, *m_robo1, *m_robo2, *m_char, *m_bg;
  SDL_Rect *m_destination;

  cPlayerController *m_player;

  int m_screen_scrolled;
public:
  cScrollEngine();
  void run(void);
  void init(void);
  void render(void);
  bool update(void);
  void cleanup(void);
  void check_for_player_movement(void);
  void check_for_screen_scrolling(void);
};

#endif // SCROLL_ENGINE_H
