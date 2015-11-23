#ifndef CALLBACK_HPP_
# define CALLBACK_HPP_

# include "IGraphics.hpp"
# include "Snake.hpp"

class		Callback
{
  Env&		env_;
  Snake&	snake_;
public:
  Callback( Env& env,  Snake& snake);
  ~Callback() {}
  void		move_forward() ;
  void		turn_left() ;
  void		turn_right() ;
};

Callback*	getCallback(Callback* update);
void		move_forward();
void		turn_left();
void		turn_right();

#endif	// !CALLBACK_HPP_
