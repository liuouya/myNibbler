#include "Callback.hpp"

Callback::Callback(Env& env, Snake& snake)
  : env_(env), snake_(snake)
{
}

void	Callback::move_forward() 
{
  (snake_.*(snake_._moves)[snake_.getDirection()])();
  snake_.seek_eat();
  snake_.death();
}

void	Callback::turn_left() 
{
  snake_.setDirection(snake_.getDirection() + 1);
  (snake_.*(snake_._moves)[snake_.getDirection()])();
  snake_.seek_eat();
  snake_.death();
}

void	Callback::turn_right() 
{
  snake_.setDirection(snake_.getDirection() - 1);
  (snake_.*(snake_._moves)[snake_.getDirection()])();
  snake_.seek_eat();
  snake_.death();
}

Callback*		getCallback(Callback* update)
{
  static Callback*	cb;

  if (!cb)
    return cb = update;
  return cb;
}

void	move_forward()
{
  getCallback(NULL)->move_forward();
}

void	turn_left()
{
  getCallback(NULL)->turn_left();
}

void	turn_right()
{
  getCallback(NULL)->turn_right();
}
