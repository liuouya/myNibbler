#include <iostream>
#include "GTK.hpp"
#include "DBoard.hpp"

extern "C"
{
  IGraphics*    create(Env& env)
  {
    std::cout << "using graphics lib GTK" << std::endl;
    env._argc = 1;
    env._argv[1] = NULL;
    return new GTK(env);
  }
}

GTK::GTK(Env& env)
  : env_(env),
    app_(Gtk::Application::create(env._argc, env._argv, "org.gtkmm.examples.base")),
    window_(env, app_),
    board_(env)
{
}

GTK::~GTK()
{
}

void	GTK::draw_grid(int width, int height)
{
  (void)width;
  (void)height;
  window_.add(board_);
  window_.store(&board_);
  board_.show();
}

int	GTK::init()
{
  draw_grid(env_._width, env_._height);
  app_->run(window_);
  return 0;
}
void	GTK::update(Env &env)
{
  (void)env;
}

enum EventType	GTK::event()
{
  return Skip;
}
