#ifndef DBoard_HPP_
# define DBoard_HPP_

# include <gtkmm.h>
# include "IGraphics.hpp"

class		DBoard : public Gtk::DrawingArea
{
  typedef Cairo::RefPtr<Cairo::Context> cairo_context;
  typedef std::list<Node> List;
  int		w_;
  int		h_;
  const List&	snake_;
  const Node&	food_;
  const bool&	in_game_;
  const int&	score_;
  float		colour_[3];
protected:
  virtual bool	on_draw(const cairo_context& cr);
  void		draw_gameover(const cairo_context& cr);
  void		draw_grid(const cairo_context& cr);
  void		draw_snake(const cairo_context& cr);
  void		draw_dot(const cairo_context& cr, int x, int y);
  void		draw_food(const cairo_context& cr, int x, int y);
public:
  DBoard(const Env& env);
  virtual ~DBoard() {}
};

#endif	// !DBoard_HPP_
