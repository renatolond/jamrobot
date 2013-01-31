#ifndef COLLIDABLE_H
#define COLLIDABLE_H

class cCell;
class cEntity;

class cCollidable
{
protected:
  cEntity *m_entity;
public:
  cCollidable();
  void integrate_verlet();
  void report_collision_vs_world(int px, int py, double dx, double dy);
  virtual void collide_vs_world_bounds()=0;
  virtual void collide_vs_tile(cCell tile)=0;
};

void integrate_verlet_generic(cCollidable &c);

#endif // COLLIDABLE_H
