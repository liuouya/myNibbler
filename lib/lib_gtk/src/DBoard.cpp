#include <sstream>
#include <iostream>
#include "DBoard.hpp"

DBoard::DBoard(const Env& env)
  : Gtk::DrawingArea(),
    w_(env._width * PIX_SZ),
    h_(env._height * PIX_SZ),
    snake_(env._snake),
    food_(env._food),
    in_game_(env._in_game),
    score_(env._score)
{
}

void	DBoard::draw_gameover(const cairo_context& cr)
{
  std::stringstream line;

  line << "      GAME OVER\n\n(press 'ESC' to quit)\n\n"
			 " Your Score -----> "
       << score_ << std::endl;
  draw_grid(cr);
  cr->set_source_rgb(1.0, 1.0, 1.0);
  Pango::FontDescription font;
  font.set_family("Monospace");
  font.set_weight(Pango::WEIGHT_BOLD);
  Glib::RefPtr<Pango::Layout> layout =
    create_pango_layout(line.str());
  layout->set_font_description(font);
  int text_width;
  int text_height;
  layout->get_pixel_size(text_width, text_height);
  cr->move_to(w_ / 2 - 85 , h_/2 - 50);
  layout->show_in_cairo_context(cr);
}

void	DBoard::draw_grid(const cairo_context& cr)
{
  cr->save();
  cr->set_line_width(1.0);
  cr->move_to(0, 0);
  cr->line_to(w_, 0);
  cr->line_to(w_, h_);
  cr->line_to(0, h_);
  cr->close_path();
  cr->set_source_rgb(0.0, 0.0, 0.0);
  cr->fill_preserve();
  cr->restore();
  cr->stroke();
}

void	DBoard::draw_food(const cairo_context& cr, int x, int y)
{
  cr->save();
  cr->set_line_width(2.0);
  cr->move_to(x, y);
  cr->line_to(x + PIX_SZ, y);
  cr->line_to(x + PIX_SZ, y + PIX_SZ);
  cr->line_to(x, y + PIX_SZ);
  cr->close_path();
  cr->set_source_rgb(0.0, 1.0, 0.0);
  cr->fill_preserve();
  cr->restore();
  cr->stroke();
}

void	DBoard::draw_dot(const cairo_context& cr, int x, int y)
{
  cr->save();
  cr->set_line_width(1.0);
  cr->arc(x + PIX_SZ / 2, y + PIX_SZ / 2, PIX_SZ / 2 + 1, 0.0, 2 * M_PI);
  cr->set_source_rgba(colour_[0], colour_[1], colour_[2], 1.0);
  cr->fill_preserve();
  cr->restore();
  cr->stroke();
}

void	DBoard::draw_snake(const cairo_context& cr)
{
  for (List::const_iterator it = snake_.begin(), it_end = snake_.end();
       it != it_end; ++it)
    {
      colour_[0] = it->_color[0] / 255.0;
      colour_[1] = it->_color[1] / 255.0;
      colour_[2] = it->_color[2] / 255.0;
      draw_dot(cr, it->_posX * PIX_SZ, it->_posY * PIX_SZ);
    }
}

bool	DBoard::on_draw(const cairo_context& cr)
{
  if (!in_game_)
    draw_gameover(cr);
  else
    {
      draw_grid(cr);
      draw_snake(cr);
      draw_food(cr, food_._posX * PIX_SZ, food_._posY * PIX_SZ);
    }
  return true;
}
