#include "scroll_engine.h"

#include <SDL/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 256

cScrollEngine::cScrollEngine()
{
  m_game_running = true;
}

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
  m_robo1 = SDL_LoadBMP( "Robo-1.bmp" );
  SDL_SetColorKey( m_robo1, SDL_SRCCOLORKEY, SDL_MapRGB(m_robo1->format, 255, 0, 255) );

  m_robo2 = SDL_LoadBMP( "Robo-2.bmp" );
  SDL_SetColorKey( m_robo2, SDL_SRCCOLORKEY, SDL_MapRGB(m_robo2->format, 255, 0, 255) );

  m_bg = SDL_LoadBMP("MarioLevel.bmp");

  m_destination = new SDL_Rect;
  m_destination->x = 0;
  m_destination->y = 0;
  //m_destination->w = 32;
  //m_destination->h = 32;
  m_char = m_robo1;
}


void cScrollEngine::cleanup()
{
  delete m_destination;

  //Free the loaded image
  SDL_FreeSurface( m_robo1 );
  SDL_FreeSurface( m_robo2 );

  //Quit SDL
  SDL_Quit();
}


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
//    if((m_destination->x+m_destination->w) > SCREEN_SIZE)
//      m_destination->x = SCREEN_SIZE-m_destination->w;
    m_char = m_robo2;
  }

  printf("%d %d\n", m_destination->x, m_destination->y);
  //Apply image to screen
  SDL_BlitSurface(m_bg, m_destination, m_screen, NULL);
  SDL_BlitSurface( m_char, NULL, m_screen, NULL );

  //Update Screen
  SDL_Flip( m_screen );

  return m_game_running;
}


void cScrollEngine::render()
{
}
