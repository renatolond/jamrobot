#ifndef SPRITE_H
#define SPRITE_H

#include "entity.h"

#include <vector>

struct sAnimation
{
  int m_start_frame;
  int m_end_frame;
  int m_base_velocity;
  sAnimation(int start_frame, int end_frame, int base_velocity);
};

class cSprite : public cEntity
{
protected:
  int m_sprite_id;

  /** TODO */
  std::vector<sAnimation> m_animations;

  /** TODO */
  unsigned int m_current_animation;

public:
  double m_x;
  double m_y;
  double m_h;
  double m_w;

  /**
   * @brief TODO
   *
   * @param start_frame TODO
   * @param end_frame TODO
   * @param base_velocity TODO
   */
  void add_animation(int start_frame, int end_frame, int base_velocity);

  /**
   * @brief TODO
   *
   * @param index TODO
   */
  void begin_animation(unsigned int index);

  /**
   * @brief TODO
   */
  void stop_animation();

  cSprite();
};

#endif // SPRITE_H
