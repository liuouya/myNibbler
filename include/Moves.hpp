#ifndef MOV_HPP_
# define MOV_HPP_
# include <string>
# include <list>
# include "Node.hpp"

class	Moves
{
public:
  void			moveRight(std::list<Node*> &_snake);
  void			moveLeft(std::list<Node*> &_snake);
  void			moveDown(std::list<Node*> &_snake);
  void			moveUp(std::list<Node*> &_snake);
};

#endif
