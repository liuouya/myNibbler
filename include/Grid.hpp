#ifndef GRID_HPP_
# define GRID_HPP_

# include <iostream>

class	Grid
{
  int		_width;
  int		_height;
 public:
  Grid(int width, int height);
  ~Grid(){}
  void		draw();
  int		getWidth() const;
  int		getHeight() const;
};

#endif /* GRID_HPP_ */
