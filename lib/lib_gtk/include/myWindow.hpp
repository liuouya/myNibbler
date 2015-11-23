#ifndef myWindow_HPP_
# define myWindow_HPP_

# include <gtkmm.h>
# include "IGraphics.hpp"
# include "DBoard.hpp"

class			myWindow : public Gtk::Window
{
  typedef Glib::RefPtr<Gtk::Application> app_ptr;
  app_ptr		app_;
  DBoard*		board_;
  int			win_w_;
  int			win_h_;
  fptr			callback_left_;
  fptr			callback_right_;
  fptr			callback_forward_;
  bool&			in_game_;
  sigc::slot<bool>	my_slot_;
  sigc::connection	conn_;
public:
  myWindow(Env& env, app_ptr app);
  virtual ~myWindow();
  virtual bool		on_key_release_event(GdkEventKey* event);
  virtual bool		on_timeout(int val);
  void			store(DBoard* board);
};

#endif	// !myWindow_HPP_
