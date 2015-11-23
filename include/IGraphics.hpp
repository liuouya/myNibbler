#ifndef IGRAPHICS_HPP_
# define IGRAPHICS_HPP_

# include <list>

# define SCREEN_W	1024
# define SCREEN_H	768
# define SCREEN_DEPTH	27
# define PIX_SZ		15

typedef void	(*fptr)();

enum EventType
  {
    Escape,
    Left,
    Right,
    Space,
    Key_Q,
    Plus,
    Minus,
    Skip,
    Nothing
  };

struct	Node
{
  int	_posX;
  int	_posY;
  int	_color[3];
  int	_type;
};

struct		Env
{
  int		_width;
  int		_height;
  std::list<Node> _snake;
  bool		_in_game;
  int		_score;
  int		_argc;
  Node		_food;
  char**	_argv;
  int		_have_moved;
  fptr		_callback_left;
  fptr		_callback_right;
  fptr		_callback_forward;
};

class	IGraphics
{
public:
  virtual ~IGraphics() {}
  virtual int			init() = 0;
  virtual void			update(Env &env) = 0;
  virtual enum EventType	event() = 0;
};

extern "C"
{
  IGraphics*	create(Env& env);
}

#endif	// !IGRAPHICS_HPP_
