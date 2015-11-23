#include <iostream>
#include "myWindow.hpp"

myWindow::myWindow(Env& env, app_ptr app)
  : Gtk::Window(),
    app_(app),
    win_w_(env._width * PIX_SZ),
    win_h_(env._height * PIX_SZ),
    callback_left_(env._callback_left),
    callback_right_(env._callback_right),
    callback_forward_(env._callback_forward),
    in_game_(env._in_game),
    my_slot_(sigc::bind(sigc::mem_fun(*this, &myWindow::on_timeout), 0)),
    conn_(Glib::signal_timeout().connect(my_slot_, 100))
{
  set_title("Best Snake Ever !!!");
  set_size_request(win_w_, win_h_);
  set_resizable(false);
  set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  add_events(Gdk::KEY_RELEASE_MASK);
}

myWindow::~myWindow()
{
}

bool	myWindow::on_timeout(int val)
{
  (void)val;
  if (in_game_)
    callback_forward_();
  board_->queue_draw();
  return true;
}

bool	myWindow::on_key_release_event(GdkEventKey* event)
{
  if (event->keyval == GDK_KEY_Left)
    callback_left_();
  else if (event->keyval == GDK_KEY_Right)
    callback_right_();
  else if (event->keyval == GDK_KEY_Escape)
    {
      in_game_ = false;
      app_->quit();
    }
  else
    return true;
  board_->queue_draw();
  return true;
}

void	myWindow::store(DBoard* board)
{
  board_ = board;
}
