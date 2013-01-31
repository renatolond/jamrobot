#include "aabb.h"

#include "cell.h"
#include "entity.h"

#include "math.h"

cAABB::cAABB()
{
}


void cAABB::collide_vs_world_bounds()
{
  int x, y;

  int pos_x, pos_y;
  int h, w;

  m_entity->get_center(pos_x, pos_y);
  m_entity->get_radius(w, h);

  x = screen_min_x - (pos_x - w);

  // collision against left side
  if ( x > 0 )
  {
    report_collision_vs_world(x, 0, 1, 0);
  }
  else
  {
    x = pos_x + w - screen_max_x;

    // collision against right side
    if ( x > 0 )
    {
      report_collision_vs_world(-x, 0, -1, 0);
    }
  }

  y = screen_min_y - (pos_y - h);
  // collision against upper bounds
  if ( y > 0 )
  {
    report_collision_vs_world(0, y, 0, 1);
  }
  else
  {
    y = pos_y + h - screen_max_y;
    if ( y > 0 )
    {
      report_collision_vs_world(0, -y, 0, -1);
    }
  }
}

void cAABB::collide_vs_tile(cCell tile)
{
  double dx, dy;
  int x, y;

  int pos_x, pos_y;
  int h, w;

  m_entity->get_center(pos_x, pos_y);
  m_entity->get_radius(w, h);

  dx = pos_x - tile.pos_x;
  x = tile.w + w - fabs(dx);

  if ( x > 0 )
  {
    dy = pos_y - tile.pos_y;
    y = tile.h + h - fabs(dy);

    if ( y > 0 )
    {
      if ( x < y )
      {
        if ( dx < 0 )
        {
          x *= -1;
          y = 0;
        }
        else
          y = 0;
      }
      else
      {
        if ( dy < 0 )
        {
          x = 0;
          y *= -1;
        }
        else
          x = 0;
      }

      tile.proj_AABB(x, y, this);
      //ResolveBoxTile(x, y, *this, tile);
    }
  }
}
