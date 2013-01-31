#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "aabb.h"
#include "sprite.h"

class cPlayerController : public cAABB, public cSprite
{
public:
  double m_vel_x;
  double m_vel_y;
  bool m_touching_ground;
  bool m_jumping;

  cPlayerController();
};

#endif // PLAYER_CONTROLLER_H
