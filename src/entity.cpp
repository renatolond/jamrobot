#include "entity.h"

cEntity::cEntity()
{
}

void cEntity::get_center(int &x, int &y) const
{
  int w, h;
  get_radius(w, h);

  x = m_x - w;
  y = m_y - h;
}

void cEntity::get_old_center(int &old_x, int &old_y) const
{
  int w, h;
  get_radius(w, h);

  old_x = m_old_x - w;
  old_y = m_old_y - h;
}

void cEntity::get_radius(int &w, int &h) const
{
  w = m_w / 2;
  h = m_h / 2;
}

void cEntity::set_center(int x, int y)
{
  int w, h;
  get_radius(w, h);

  m_x = x + w;
  m_y = y + h;
}

void cEntity::set_old_center(int old_x, int old_y)
{
  int w, h;
  get_radius(w, h);

  m_old_x = old_x + w;
  m_old_y = old_y + h;
}
