#include <iostream>
#include "Moves.hpp"

static int    color[4][3] =
  {
    {
      255, 150, 255
    },
    {
      102, 255, 178
    },
    {
      255, 255, 100
    },
    {
      51, 153, 255
    }
  };

void	Moves::moveRight(std::list<Node*>  &_snake)
{
  Node	*head = *(_snake.begin());

  std::cout << head->getPosX() << std::endl;
  _snake.push_front(new Node(head->getPosX() + 1, head->getPosY(), head->getColor(), 1));
  _snake.pop_back();
  head->setColor(color[2]);
}

void	Moves::moveLeft(std::list<Node*> &_snake)
{
  Node	*head = *(_snake.begin());

  _snake.push_front(new Node(head->getPosX() - 1, head->getPosY(), head->getColor(), 1));
  _snake.pop_back();
  head->setColor(color[2]);
}

void    Moves::moveDown(std::list<Node*> &_snake)
{
  Node	*head = *(_snake.begin());

  _snake.push_front(new Node(head->getPosX(), head->getPosY() + 1, head->getColor(), 1));
  _snake.pop_back();
  head->setColor(color[2]);
}

void	Moves::moveUp(std::list<Node*> &_snake)
{
  Node	*head = *(_snake.begin());

  _snake.push_front(new Node(head->getPosX(), head->getPosY() - 1, head->getColor(), 1));
  _snake.pop_back();
  head->setColor(color[2]);
}
