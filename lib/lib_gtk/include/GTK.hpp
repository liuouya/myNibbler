#ifndef GTK_HPP_
# define GTK_HPP_

# include <list>
# include <gtkmm.h>
# include "IGraphics.hpp"
# include "myWindow.hpp"
# include "DBoard.hpp"

class			GTK : public IGraphics
{
  typedef Glib::RefPtr<Gtk::Application> app_ptr;
  const Env&		env_;
  app_ptr		app_;
  myWindow		window_;
  DBoard		board_;
public:
  GTK(Env& env);
  virtual ~GTK();
  virtual void		draw_grid(int width, int height);
  virtual int		init();
  virtual void		update(Env &env);
  virtual enum EventType event();
};

#endif	// !GTK_HPP_
