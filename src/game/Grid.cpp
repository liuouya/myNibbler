#include "Grid.hpp"

Grid::Grid(int width, int height)
  : _width(width), _height(height)
{

}

int	Grid::getWidth() const
{
  return (_width);
}

int	Grid::getHeight() const
{
  return (_height);
}
