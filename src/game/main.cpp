#include <iostream>
#include <sstream>
#include <dlfcn.h>
#include <stdlib.h>
#include <time.h>
#include "Snake.hpp"
#include "IGraphics.hpp"
#include "Callback.hpp"

static const char* lib_name[] =
  {
    "./lib_nibbler_sfml.so",
    "./lib_nibbler_gtk.so",
    "./lib_nibbler_opengl.so"
  };

void	init_game(Snake& snake, IGraphics& g)
{
  int	ret_event = 0;
  int	frame = 0;

  g.init();
  while (snake._env._in_game)
    {
      if (!(ret_event = g.event()))
	{
	  snake.quit();
	  return ;
	}
      if (ret_event == Skip)
	return ;
      // if (ret_event == Right)
      // 	snake.setDirection(snake.getDirection() - 1);
      // else if (ret_event == Left)
      // 	snake.setDirection(snake.getDirection() + 1);
      // else if (ret_event == Key_Q)
      // 	return ;
      else if (ret_event >= Left && ret_event <= Minus)
	(snake.*(snake._events)[ret_event])();
      if (!snake.getPause())
	{
	  frame += 5;
	  if (!(frame % snake.getSpeed()))
	    {
	      snake.seek_eat();
	      (snake.*(snake._moves)[snake.getDirection()])();
	      snake._env._have_moved = 0;
	    }
	  snake.death();
	  g.update(snake._env);
	}
    }
}

void		run_lib(const char* lib, Snake& snake, Env& env)
{
  void*		dlhandle;
  IGraphics*	(*g_creator)(Env& e);

  std::cout << "loading lib : " << lib << std::endl;
  if (!(dlhandle = dlopen(lib, RTLD_LAZY)))
    {
      std::cerr << "cannot load " << lib << std::endl;
      return ;
    }
  g_creator = reinterpret_cast<IGraphics* (*)(Env& e)>(dlsym(dlhandle, "create"));
  if (!g_creator)
    {
      std::cerr << "cannot load symbol 'create'" << std::endl;
      return ;
    }
  IGraphics* g = g_creator(env);
  init_game(snake, *g);
  dlclose(dlhandle);
}

void	env_init(Env& env, int argc, char** argv)
{
  srand(time(NULL));
  env._in_game = true;
  env._argc = argc;
  env._argv = argv;
  int av1, av2;
  std::stringstream(argv[1]) >> av1;
  std::stringstream(argv[2]) >> av2;
  env._width = av1;
  env._height = av2;
  env._callback_left = turn_left;
  env._callback_right = turn_right;
  env._callback_forward = move_forward;
  env._have_moved = 0;
  env._score = 0;
}

int	main(int argc, char **argv)
{
  if (argc != 4 && argc != 3)
    {
      std::cerr << "usage : " << argv[0] 
		<< " Width Height [./lib_nibbler_xxx.so]"
		<< std::endl;
      return 1;
    }
  Env env;
  env_init(env, argc, argv);
  Grid	grid(env._width, env._height);
  Snake	snake(&grid, env);
  Callback callback(env, snake);
  getCallback(&callback);
  if (argc == 4)
    run_lib(argv[3], snake, env);
  else
    for (int run = 0; env._in_game && run < 3; ++run)
      run_lib(lib_name[run], snake, env);
  return 0;
}
