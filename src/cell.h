#ifndef CELL_H
#define CELL_H

class cAABB;

class cCell
{
public:
  int pos_x, pos_y;
  int h, w;
  cCell();

  void proj_AABB(int x, int y, cAABB *aabb);
};

#endif // CELL_H
