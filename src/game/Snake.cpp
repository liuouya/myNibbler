#include <stdlib.h>
#include "Snake.hpp"

static int    color[4][3] =
  {
    {
      0, 150, 255
    },
    {
      255, 0, 165
    },
    {
      0, 0, 255
    },
    {
      255, 153, 255
    }
  };

Snake::Snake(Grid *grid, Env& env)
  : _size(4), _direction(0), _grid(grid), _env(env)
{
  Node	node;

  _pause = 0;
  _speed = 80;
  for (int i = 0; i < _size; ++i)
    {
      if (i == 0)
	{
	  node._posX = i + (grid->getWidth() / 2) - 1;
	  node._posY = (grid->getHeight() / 2) - 1;
	  node._color[0] = color[1][0];
	  node._color[1] = color[1][1];
	  node._color[2] = color[1][2];
	  node._type = 1;
	}
      else
	{
	  node._posX = i + (grid->getWidth() / 2) - 1;
	  node._posY = (grid->getHeight() / 2) - 1;
	  node._color[0] = color[2][0];
	  node._color[1] = color[2][1];
	  node._color[2] = color[2][2];
	  node._type = 0;
	}
      _env._snake.push_back(node);
    }
  _moves[0] = &Snake::moveRight;
  _moves[1] = &Snake::moveDown;
  _moves[2] = &Snake::moveLeft;
  _moves[3] = &Snake::moveUp;
  _events[Right] = &Snake::switch_right;
  _events[Left] = &Snake::switch_left;
  _events[Minus] = &Snake::speed_minus;
  _events[Plus] = &Snake::speed_plus;
  _events[Space] = &Snake::pause;
  _have_eaten = false;
  pop_food();
}

void	Snake::pause()
{
  std::cout << "PAUSE\n";
  if (!_pause)
    _pause = 1;
  else
    _pause = 0;
}

int	Snake::getPause()
{
  return (_pause);
}

int	Snake::getSpeed()
{
  return (_speed);
}

void	Snake::speed_minus()
{
  if (_speed <= 60)
    _speed += 10;
}


void	Snake::speed_plus()
{
  if (_speed >= 20)
    _speed -= 10;
}

void	Snake::switch_right()
{
  if (!_env._have_moved)
    {
      setDirection(getDirection() - 1);
      _env._have_moved = 1;
    }
}

void	Snake::switch_left()
{
  if (!_env._have_moved)
    {
      setDirection(getDirection() + 1);
      _env._have_moved = 1;
    }
}

void	Snake::moveRight()
{
  std::list<Node>::iterator	head = (_env._snake.begin());
  Node  node;

  if ((*head)._posX - 1< 0)
    {
      std::cout << "GameOver Right" << std::endl;
      _env._in_game = 0;
      return ;
    }
  node._posX = (*head)._posX - 1;
  node._posY = (*head)._posY;
  node._color[0] = (*head)._color[0];
  node._color[1] = (*head)._color[1];
  node._color[2] = (*head)._color[2];
  node._type = 1;
  _env._snake.push_front(node);
  if (!_have_eaten)
    _env._snake.pop_back();
  (*head)._color[0] = color[2][0];
  (*head)._color[1] = color[2][1];
  (*head)._color[2] = color[2][2];
  (*head)._type = 0;
}

void	Snake::moveLeft()
{
  std::list<Node>::iterator	head = (_env._snake.begin());
  Node  node;

  if ((*head)._posX + 1 > _env._width - 1)
    {
      std::cout << "GameOver Left" << std::endl;
      _env._in_game = 0;
      return ;
    }
  node._posX = (*head)._posX + 1;
  node._posY = (*head)._posY;
  node._color[0] = (*head)._color[0];
  node._color[1] = (*head)._color[1];
  node._color[2] = (*head)._color[2];
  node._type = 1;
  _env._snake.push_front(node);
  if (!_have_eaten)
    _env._snake.pop_back();
  (*head)._color[0] = color[2][0];
  (*head)._color[1] = color[2][1];
  (*head)._color[2] = color[2][2];
  (*head)._type = 0;
}

void    Snake::moveDown()
{
  std::list<Node>::iterator	head = (_env._snake.begin());
  Node  node;

  if ((*head)._posY + 1 > _env._height - 1)
    {
      std::cout << "GameOver Down" << std::endl;
      _env._in_game = 0;
      return ;
    }
  node._posX = (*head)._posX;
  node._posY = (*head)._posY + 1;
  node._color[0] = (*head)._color[0];
  node._color[1] = (*head)._color[1];
  node._color[2] = (*head)._color[2];
  node._type = 1;
  _env._snake.push_front(node);
  if (!_have_eaten)
    _env._snake.pop_back();
  (*head)._color[0] = color[2][0];
  (*head)._color[1] = color[2][1];
  (*head)._color[2] = color[2][2];
  (*head)._type = 0;
}

void	Snake::moveUp()
{
  std::list<Node>::iterator	head = (_env._snake.begin());
  Node  node;


  if ((*head)._posY - 1 < 0)
    {
      std::cout << "GameOver Up" << std::endl;
      _env._in_game = 0;
      return ;
    }
  node._posX = (*head)._posX;
  node._posY = (*head)._posY - 1;
  node._color[0] = (*head)._color[0];
  node._color[1] = (*head)._color[1];
  node._color[2] = (*head)._color[2];
  node._type = 1;
  _env._snake.push_front(node);
  if (!_have_eaten)
    _env._snake.pop_back();
  (*head)._color[0] = color[2][0];
  (*head)._color[1] = color[2][1];
  (*head)._color[2] = color[2][2];
  (*head)._type = 0;
}

void	Snake::death()
{
  std::list<Node>::iterator	head = (_env._snake.begin());
  
  for (std::list<Node>::iterator it = _env._snake.begin(); it != _env._snake.end(); ++it)
    {
      if (it != head)
	{
	  if ((*head)._posX == (*it)._posX && (*head)._posY == (*it)._posY)
	    {
	      std::cout  << "Don't eat yourself damn" << std::endl;
	      _env._in_game = 0;
	      return ;
	    }
	}
    }
}

int	Snake::getSize() const
{
  return (_size);
}

int	Snake::getDirection() const
{
  return (_direction);
}

Grid	*Snake::getGrid() const
{
      return (_grid);
}
 
void	Snake::setDirection(int direction)
{
  _direction = direction;
  if (_direction >= 4)
    _direction = 0;
  else if (_direction < 0)
    _direction = 3;
}

void	Snake::belly_state(bool state)
{
  _have_eaten = state;
}

void	Snake::pop_food()
{
  int	x, y;

  x = rand() % _env._width;
  y = rand() % _env._height;
  for (std::list<Node>::iterator it = _env._snake.begin(); it == _env._snake.end(); ++it)
    if (x == it->_posX && y == it->_posY)
      {
	pop_food();
	return ;
      }
  _env._food._posX = x;
  _env._food._posY = y;
  _env._food._color[0] = 0;
  _env._food._color[1] = 0;
  _env._food._color[2] = 0;
  _env._food._type = 3;
}

void	Snake::seek_eat()
{
  Node	head = *(_env._snake.begin());

  _have_eaten = false;
  if (head._posX == _env._food._posX && head._posY == _env._food._posY)
    {
      _have_eaten = true;
      pop_food();
      ++_env._score;
    }
}

void	Snake::quit()
{
  _env._in_game = false;
}
