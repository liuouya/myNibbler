//
// SFML.cpp for nibbler in /home/menu_x/rendu/cpp_nibbler
// 
// Made by xavier menu
// Login   <menu_x@epitech.net>
// 
// Started on  Sat Apr  4 11:53:35 2015 xavier menu
// Last update Sun Apr  5 23:29:59 2015 xavier menu
//

#include	"SFML.hpp"

extern "C"
{
  IGraphics*	create(Env& env)
  {
    (void) env;
    std::cout << "using graphic lib SFML" << std::endl;
    env._argc = 1;
    env._argv[1] = NULL;
    return new SFML(env);
  }
}

SFML::SFML(Env &env): _app(sf::VideoMode(env._width * 20, env._height * 20, 32), "nibbler"), _white(255,255,255)
{
  _game_over = false;
}

int	SFML::init()
{
  _square = sf::Shape::Rectangle(0,0,20,20, _white, 1, sf::Color(0, 0, 0));
  _square.SetPosition(sf::Vector2f(0,0));
  return (0);
}

void	SFML::game_over(const Env &env)
{
  _game_over = true;
  sf::Font	font;

  if (font.LoadFromFile("ressources/Something in the way.ttf"))
    {
      std::string	text = "GAME OVER\nPress escape\nscore = ";
      std::stringstream	convert;

      convert << env._score;
      text += convert.str();
      text += "\n";
      sf::String	to_text(text.c_str(), font, (env._width * env._width)/100*5);
      to_text.Move(sf::Vector2f(env._width/2*17, env._height/2*10));
      _app.Draw(to_text);
    }
}

void	SFML::update(Env &env)
{
  _app.Clear();
  if (!env._in_game)
    game_over(env);
  else
    {
      draw_grid(env._width, env._height);
      draw_snake(env);
      draw_food(env);
    }
  _app.Display();
  if (!env._in_game)
    while (event());
}

enum EventType	SFML::event()
{
  while(_app.GetEvent(_event))
    {
      if (_event.Type == sf::Event::Closed)
	{
	  _app.Close();
	  return (Escape);
	}
      else if (_event.Type == sf::Event::KeyReleased)
	{
	  switch (_event.Key.Code)
	    {
	    case sf::Key::Escape:
	      _app.Close();
	      return (Escape);
	      break;
	      
	    case sf::Key::Left:
	      return (Left);
	      break;

	    case sf::Key::Right:
	      return (Right);
	      break;

	    case sf::Key::Space:
	      return (Space);
	      break;

	    case sf::Key::Up:
	      return (Plus);
	      break;

	    case sf::Key::Down:
	      return (Minus);
	      break;

	    case sf::Key::Q:
	      _app.Close();
	      return (Key_Q);
	      break;

	    default:
	      break;
	    }
	}
    }
  return (Nothing);
}

void	SFML::draw_grid(const int w, const int h)
{
  int	x = 0, y = 0;

  _square.SetColor(_white);
  for (x = 0; x < w; ++x)
    {
      for (y = 0; y < h; ++y)
	{
	  _square.SetPosition(sf::Vector2f(x * 20, y * 20));
	  _app.Draw(_square);
	}
    }
}

void	SFML::draw_square(const Node &it)
{
  _square.SetPosition(sf::Vector2f(it._posX * 20, it._posY * 20));
  _square.SetColor(sf::Color(it._color[0],it._color[1],it._color[2]));
  _app.Draw(_square);
}

void	SFML::draw_snake(Env &env)
{
  for (std::list<Node>::iterator	it = env._snake.begin(); it != env._snake.end(); ++it)
    draw_square(*it);
}

void	SFML::draw_food(const Env &env)
{
  draw_square(env._food);
}
