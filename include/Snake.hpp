#ifndef SNAKE_HPP_
# define SNAKE_HPP_

# define SCREEN_W 1024
# define SCREEN_H 768
# define SCREEN_DEPTH 27

# include <iostream>
# include <list>
# include "Grid.hpp"
# include "IGraphics.hpp"

class	Snake;

typedef  void(Snake::*Movement)();
typedef  void(Snake::*Events)();

class	Snake
{
  int			_size;
  int			_direction;
  Grid			*_grid;
  bool			_have_eaten;
  int			_pause;
  int			_speed;
public:
  Env			&_env;
  Movement		_moves[4];
  Events		_events[Skip];
  Snake(Grid *grid, Env &_env);
  ~Snake(){}
  void			moveRight();
  void			moveLeft();
  void			moveDown();
  void			moveUp();
  void			death();
  void			switch_right();
  void			switch_left();
  void			speed_minus();
  void			speed_plus();
  void			pause();
  int			getSize() const;
  int			getDirection() const;
  Grid			*getGrid() const;
  void			setDirection(int direction);
  void			belly_state(bool state);
  void			pop_food();
  void			seek_eat();
  int			getPause();
  int			getSpeed();
  void			quit();
};

#endif // !SNAKE_HPP_
