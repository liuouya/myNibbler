#ifndef DPixel_HPP_
# define DPixel_HPP_

# include <gtkmm.h>
# include "IGraphics.hpp"

class		DPixel : public Gtk::DrawingArea
{
  int		x_;
  int		y_;
  int		r_;
  int		g_;
  int		b_;
protected:
  virtual bool	on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
public:
  DPixel(const Node& node);
  virtual ~DPixel() {}
};

#endif	// !DPixel_HPP_
