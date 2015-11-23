//
// SFML.hpp for nibbler in /home/menu_x/rendu/cpp_nibbler
// 
// Made by xavier menu
// Login   <menu_x@epitech.net>
// 
// Started on  Sat Apr  4 11:56:49 2015 xavier menu
// Last update Sun Apr  5 23:27:56 2015 xavier menu
//

#ifndef		SMFL_HPP
# define	SMFL_HPP

# include	<SFML/Graphics.hpp>
# include	<SFML/System.hpp>
# include	<iostream>
# include	<sstream>
# include	"IGraphics.hpp"

class		SFML: public IGraphics
{
  sf::RenderWindow		_app;
  sf::Shape			_square;
  sf::Color			_white, _red, _green;
  sf::Event			_event;
  bool				_game_over;

public:
  SFML(Env &env);
  virtual ~SFML()	{};
  virtual int	init();
  virtual void	update(Env &env);
  virtual enum EventType	event();
  void	draw_grid(const int width, const int height);
  void	draw_snake(Env &env);
  void	draw_food(const Env &env);
  void	draw_square(const Node &it);
  void	game_over(const Env &env);
  void  close();
};

#endif		/*SMFL_HPP*/
