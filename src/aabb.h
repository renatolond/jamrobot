#ifndef AABB_H
#define AABB_H

#include <vector>

#include "collidable.h" // base class

class cAABB : public cCollidable
{
public:
  void collide_vs_world_bounds();
  void collide_vs_tile(cCell tile);
  cAABB();
};

#endif // AABB_H
