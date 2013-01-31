#ifndef ENTITY_H
#define ENTITY_H

class cEntity
{
  int m_x, m_y;
  int m_old_x, m_old_y;

  int m_h, m_w;
public:
  cEntity();

  void get_center(int &x, int &y) const;
  void get_old_center(int &old_x, int &old_y) const;
  void get_radius(int &w, int &h) const;

  void set_center(int x, int y);
  void set_old_center(int old_x, int old_y);
};

#endif // ENTITY_H
