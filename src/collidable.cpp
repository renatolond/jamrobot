#include "collidable.h"

#include "entity.h"

double friction = 0.05;
double bounce =  0.3;
double drag = 0.99;
double gravity = 0.2;

cCollidable::cCollidable()
{
}

void cCollidable::integrate_verlet()
{
  int pos_x, pos_y;
  int old_pos_x, old_pos_y;

  m_entity->get_center(pos_x, pos_y);
  m_entity->get_old_center(old_pos_x, old_pos_y);

//  int dx, dy;
//  dx = pos_x * drag - old_pos_x * drag;
//  dy = pos_y * drag - old_pos_y * drag + gravity;

  int new_pos_x, new_pos_y;
  new_pos_x = pos_x + (pos_x * drag - old_pos_x * drag);
  new_pos_y = pos_y + (pos_y * drag - old_pos_y * drag + gravity);

  m_entity->set_center(new_pos_x, new_pos_y);
  m_entity->set_old_center(pos_x, pos_y);
}

void cCollidable::report_collision_vs_world(int px, int py, double dx, double dy)
{
  int pos_x, pos_y;
  int old_pos_x, old_pos_y;

  m_entity->get_center(pos_x, pos_y);
  m_entity->get_old_center(old_pos_x, old_pos_y);

  int xw, yw;
  double vx, vy;
  double temp, nx, ny, tx, ty;
  double fx, fy, bx, by;

  m_entity->get_radius(xw, yw);

  vx = pos_x - old_pos_x;
  vy = pos_y - old_pos_y;

  temp = vx*dx + vy*dy;
  nx = temp*dx;
  ny = temp*dy;

  tx = vx - nx;
  ty = vy - ny;

  if ( temp < 0 )
  {
      fx = tx * friction;
      fy = ty * friction;

      bx = nx * (bounce+1.0);
      by = ny * (bounce+1.0);
  }
  else
  {
      fx = fy = bx = by = 0;
  }

  pos_x += px;
  pos_y += py;
  old_pos_x += px + bx + fx;
  old_pos_y += py + by + fy;

  m_entity->set_center(pos_x, pos_y);
  m_entity->set_old_center(old_pos_x, old_pos_y);
}
