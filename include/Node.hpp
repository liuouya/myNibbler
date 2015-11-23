#ifndef ANODE_HPP_
# define ANODE_HPP_

class	Node
{
protected:
  int	_posX;
  int	_posY;
  int	_color[3];
  int	_type;
public:
  ~Node(){}
  Node(int x, int y, int color[3], int type = 0);
  Node(const Node &other);
  int	getType() const;
  int	getPosX() const;
  int	getPosY() const;
  int	const *getColor() const;
  void	setType(int);
  void	setPosX(int);
  void	setPosY(int);
  Node	&operator=(const Node &other);
};

#endif
