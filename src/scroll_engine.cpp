#include "scroll_engine.h"

#include <SDL/SDL.h>

#include "rgb.h"
#include "player_controller.h"
#include "surface.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 256

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
cScrollEngine::cScrollEngine()
{
  m_game_running = true;
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void cScrollEngine::run()
{
  // Call the init function
  init();

  for(;;){
    // Render at each VBlank
    //PA_WaitForVBlank();
    render();

    // Update the program
    if(!update())
      break;
  }

  // Call the cleanup function
  cleanup();
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void cScrollEngine::init()
{
  //Start SDL
  SDL_Init( SDL_INIT_EVERYTHING );

  for(int i = 0; i < NUM_SDLK_DOWN_EVENTS; i++) { // init them all to false
    KEYS[i] = false;
  }

  SDL_EnableKeyRepeat(0,0); // you can configure this how you want, but it makes it nice for when you want to register a key continuously being held down

  //Set up screen
  m_screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE );

  //Load image
  m_robo1 = cSurface::load("Robo-1.bmp", sRGB(255, 0, 255));
  m_robo2 = cSurface::load("Robo-2.bmp", sRGB(255, 0, 255));
  m_bg = cSurface::load("MarioLevel.bmp");

  m_player = new cPlayerController();

  m_destination = new SDL_Rect;
  m_destination->x = 0;
  m_destination->y = 0;
  m_destination->w = SCREEN_WIDTH;
  m_destination->h = SCREEN_HEIGHT;
  m_char = m_robo1;

  m_screen_scrolled = 0;
}


//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void cScrollEngine::cleanup()
{
  delete m_destination;

  //Free the loaded image
  cSurface::free(m_robo1);
  cSurface::free(m_robo2);
  cSurface::free(m_bg);

  //Quit SDL
  SDL_Quit();
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void cScrollEngine::check_for_player_movement()
{
  if(KEYS[SDLK_LEFT])
  {
    m_destination->x--;
    if(m_destination->x < 0)
      m_destination->x = 0;
    m_char = m_robo1;
  }
  if(KEYS[SDLK_RIGHT])
  {
    m_destination->x++;
    if((m_destination->x+m_destination->w) > SCREEN_WIDTH)
      m_destination->x = SCREEN_WIDTH-m_destination->w;
    m_char = m_robo2;
  }

  double max_speed = 2;
  int side_player_speed = KEYS[SDLK_RIGHT] - KEYS[SDLK_LEFT];
  double vel_x = side_player_speed * max_speed;
  m_destination->x += vel_x;
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void cScrollEngine::check_for_screen_scrolling()
{
  int half_screen_x = SCREEN_WIDTH / 2;
  int quarter_screen_x = SCREEN_WIDTH / 4;
  int max_world_x = 2048 - 128;
  int screen_x = 256;
  int object_x = 16;

  // If player is reached half screen
  if(((m_destination->x - m_screen_scrolled) > half_screen_x) && (m_destination->x < max_world_x))
  {
    // Screen starts scrolling.
    m_screen_scrolled = m_destination->x - half_screen_x;
  }
  // But if player came before quarter screen
  else if(((m_destination->x - m_screen_scrolled) < quarter_screen_x) &&
          (m_destination->x > quarter_screen_x))
  {
    // screen starts unrolling.
    m_screen_scrolled = m_destination->x - quarter_screen_x;
  }

  //printf("%d\n", m_screen_scrolled);

//  sLevelData *current_level_data = m_level_data_vector[m_current_level];
//  std::vector<sObject *>& objects = current_level_data->m_objects;
//  for(unsigned int i(0); i < objects.size(); ++i)
//  {
//    sObject *object = objects[i];

//    // if object is on screen.
//    if((object->m_x <= m_screen_scrolled + screen_x) &&
//       (object->m_x >= m_screen_scrolled - object_x))
//    {
//      if(!object->exists())
//        object->create(get_unoccupied_sprite_id());
//      object->move(m_screen_scrolled);
//    }
//    // object is off screen, make sure it is destroyed.
//    else
//    {
//      if(object->exists())
//      {
//        int sprite_id = object->get_sprite_id();
//        object->destroy();
//        m_occupied_sprites[sprite_id] = 0;
//      }
//    }
//  }
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
bool cScrollEngine::update()
{
  SDL_FillRect(m_screen,NULL,0x000000);
  SDL_Event event;

  if(SDL_PollEvent(&event))
  {
    if(event.type == SDL_QUIT)
    {
      m_game_running = false;
    }
    if(event.type == SDL_KEYDOWN)
    {
      KEYS[event.key.keysym.sym] = true;
    }
    else if(event.type == SDL_KEYUP)
    {
      KEYS[event.key.keysym.sym] = false;
    }
  }

  check_for_player_movement();
//  check_for_collisions();
  check_for_screen_scrolling();

  //printf("%d %d\n", m_destination->x, m_destination->y);
  //Apply image to screen
  SDL_BlitSurface(m_bg, m_destination, m_screen, NULL);
  SDL_BlitSurface( m_char, NULL, m_screen, NULL );

  //Update Screen
  SDL_Flip( m_screen );

  return m_game_running;
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
void cScrollEngine::render()
{
}
