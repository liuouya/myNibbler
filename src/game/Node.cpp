#include "Node.hpp"

Node::Node(int x, int y, int color[3], int type)
  :_posX(x), _posY(y), _type(type)
{
  _color[0] = color[0];
  _color[1] = color[1];
  _color[2] = color[2];
}

Node::Node(const Node &other)
{
  _posX = other.getPosX();
  _posY = other.getPosY();
  _type = 0;
}


Node	&Node::operator=(const Node &other)
{
  _posX = other.getPosX();
  _posY = other.getPosY();
  _type = 0;
  return (*this);
}


int	Node::getType() const
{
  return (_type);
}

int	Node::getPosX() const
{
  return (_posX);
}

int	Node::getPosY() const
{
  return (_posY);
}

int	const *Node::getColor() const
{
  return (_color);
}

void	Node::setType(int type)
{
  _type = type;
}

void	Node::setPosX(int x)
{
  _posX = x;
}

void	Node::setPosY(int y)
{
  _posY = y;
}
