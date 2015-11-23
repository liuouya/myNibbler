#ifndef OPENGL_HPP_
# define OPENGL_HPP_

# include <iostream>
# include <string>
# include <GL/gl.h>
# include <GL/glu.h>
# include <SDL/SDL.h>
# include "IGraphics.hpp"

class			OpenGL : public IGraphics
{
  SDL_Surface		*_window;
  std::string		_song;
public:
  virtual ~OpenGL() {}
  virtual int		init();
  virtual void		update(Env &env);
  virtual enum EventType		event();
  void			draw_grid(int width, int height);
  void			draw_snake(Node const &node);
  void			draw_lines(int x, int y);
  void			draw_wall_x(int x, int z, int y);
  void			draw_wall_y(int x, int z, int y);
  void			draw_food(Node const &food);
  void			cam(int x, int y);
void			game_over(int x, int z);
};
void	sound();
#endif	// !OPENGL_HPP_
