#include "sdlglutils.hpp"
#include "OpenGL.hpp"

static GLuint	texture1;
static GLuint	texture2;
static GLuint	texture3;
static GLuint	texture4;

extern "C"
{
  IGraphics*	create(Env& env)
  {
    (void)env;
    std::cout << "usign graphics lib OpenGL" << std::endl;
    return new OpenGL;
  }
}

void            OpenGL::cam(int x, int y)
{
  int		range = (x > y) ? x : y;
  gluLookAt((x / 2), y + range / 2, range - range / 2, x / 2, 0, 0, 0, 0, 1);
}

void		OpenGL::game_over(int x, int z)
{
  // int		range = (x > z) ? x : z;
  int		y = z + 1;
  int		i = -3;

  (void) x;
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture3);
  glBegin(GL_QUADS);
  glTexCoord2d(i, y);
  glVertex3d(i, y, -3);
  glTexCoord2d(i, y);
  glVertex3d(i, y, -4);
  glTexCoord2d(i - 1, y);
  glVertex3d(i - 1, y, -2);
  glTexCoord2d(i - 1, y);
  glVertex3d(i - 1, y, -4);
  glEnd();
  glPopMatrix();
}

void		OpenGL::draw_wall_x(int x, int z, int y)
{
  (void)z;
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture2);
  glBegin(GL_QUADS);
  for (int i = -1; i < x; i++)
    {      
      glTexCoord2d(i, y);
      glVertex3d(i, y, 1.5);
      glTexCoord2d(i, y);
      glVertex3d(i, y, 0.5);
      glTexCoord2d(i - 1, y);
      glVertex3d(i - 1, y, 0.5);
      glTexCoord2d(i - 1, y);
      glVertex3d(i - 1, y, 1.5);
      glTexCoord2d(i, y);
      glVertex3d(i, y, 1.5);
      glTexCoord2d(i, y);
      glVertex3d(i, y, 0.5);
      glTexCoord2d(i, y - 1);
      glVertex3d(i, y - 1, 0.5);
      glTexCoord2d(i, y - 1);
      glVertex3d(i, y - 1, 1.5);
      glTexCoord2d(i - 1, y);
      glVertex3d(i - 1, y, 1.5);
      glTexCoord2d(i - 1, y);
      glVertex3d(i - 1, y, 0.5);
      glTexCoord2d(i - 1, y - 1);
      glVertex3d(i - 1, y - 1, 0.5);
      glTexCoord2d(i - 1, y - 1);
      glVertex3d(i - 1, y - 1, 1.5);
      glTexCoord2d(i, y);
      glVertex3d(i, y, 0.5);
      glTexCoord2d(i, y - 1);
      glVertex3d(i, y - 1, 0.5);
      glTexCoord2d(i - 1, y - 1);
      glVertex3d(i - 1, y - 1, 0.5);
      glTexCoord2d(i - 1, y);
      glVertex3d(i - 1, y, 0.5);
      glTexCoord2d(i, y - 1);
      glVertex3d(i, y - 1, 1.5);
      glTexCoord2d(i, y - 1);
      glVertex3d(i, y - 1, 0.5);
      glTexCoord2d(i - 1, y - 1);
      glVertex3d(i - 1, y - 1, 0.5);
      glTexCoord2d(i - 1, y - 1);
      glVertex3d(i - 1, y - 1, 1.5);
      glTexCoord2d(i, y - 1);
      glVertex3d(i, y - 1, 1.5);
      glTexCoord2d(i, y);
      glVertex3d(i, y, 1.5);
      glTexCoord2d(i - 1, y);
      glVertex3d(i - 1, y, 1.5);
      glTexCoord2d(i - 1, y - 1);
      glVertex3d(i - 1, y - 1, 1.5);
    }
  glEnd();
  glPopMatrix();
}

void		OpenGL::draw_wall_y(int x, int z, int y)
{
  (void) x;
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture2);
  glBegin(GL_QUADS);
  for (int i = -1; i < z; i++)
    {
      glTexCoord2d(y, i);
      glVertex3d(y, i, 1.5);
      glTexCoord2d(y, i);
      glVertex3d(y, i, 0.5);
      glTexCoord2d(y - 1, i);
      glVertex3d(y - 1, i, 0.5);
      glTexCoord2d(y - 1, i);
      glVertex3d(y - 1, i, 1.5);
      glTexCoord2d(y, i);
      glVertex3d(y, i, 1.5);
      glTexCoord2d(y, i);
      glVertex3d(y, i, 0.5);
      glTexCoord2d(y, i - 1);
      glVertex3d(y, i - 1, 0.5);
      glTexCoord2d(y, i - 1);
      glVertex3d(y, i - 1, 1.5);
      glTexCoord2d(y - 1, i);
      glVertex3d(y - 1, i, 1.5);
      glTexCoord2d(y - 1, i);
      glVertex3d(y - 1, i, 0.5);
      glTexCoord2d(y - 1, i - 1);
      glVertex3d(y - 1, i - 1, 0.5);
      glTexCoord2d(y - 1, i - 1);
      glVertex3d(y - 1, i - 1, 1.5);
      glTexCoord2d(y, i);
      glVertex3d(y, i, 0.5);
      glTexCoord2d(y, i - 1);
      glVertex3d(y, i - 1, 0.5);
      glTexCoord2d(y - 1, i - 1);
      glVertex3d(y - 1, i - 1, 0.5);
      glTexCoord2d(y - 1, i);
      glVertex3d(y - 1, i, 0.5);
      glTexCoord2d(y, i - 1);
      glVertex3d(y, i - 1, 1.5);
      glTexCoord2d(y, i - 1);
      glVertex3d(y, i - 1, 0.5);
      glTexCoord2d(y - 1, i - 1);
      glVertex3d(y - 1, i - 1, 0.5);
      glTexCoord2d(y - 1, i - 1);
      glVertex3d(y - 1, i - 1, 1.5);
      glTexCoord2d(y, i - 1);
      glVertex3d(y, i - 1, 1.5);
      glTexCoord2d(y, i);
      glVertex3d(y, i, 1.5);
      glTexCoord2d(y - 1, i);
      glVertex3d(y - 1, i, 1.5);
      glTexCoord2d(y - 1, i - 1);
      glVertex3d(y - 1, i - 1, 1.5);
    }
  glEnd();
  glPopMatrix();
}

void		OpenGL::draw_grid(int x, int z)
{
  int		x2, z2;
  x2 = 0;
  z2 = 0;

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture1);
  glBegin(GL_QUADS);
  for (int i = 0; i < (x * z) ; ++i)
    {
      if ((i % x) == 0 && i != 0)
	{
	  x2 = 0;
	  ++z2;
	}
      glTexCoord2d(x2, z2);
      glVertex3d(x2, z2, 0.5);
      glTexCoord2d(x2, z2 - 1);
      glVertex3d(x2, z2 - 1, 0.5);
      glTexCoord2d(x2 - 1, z2 - 1);
      glVertex3d(x2 - 1, z2 - 1, 0.5);
      glTexCoord2d(x2 - 1, z2);
      glVertex3d(x2 - 1, z2, 0.5);
      ++x2;
    }
  glEnd();
  draw_wall_x(x, z, -1);
  draw_wall_x(x, z, z);
  draw_wall_y(x, z, - 1);
  draw_wall_y(x, z, x);
  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}

void	OpenGL::draw_food(Node const &node)
{
  int		x = node._posX;
  int		y = node._posY;

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture4);
  glBegin(GL_QUADS);
  // glColor3ub(node._color[0], node._color[1], node._color[2]);
  glVertex3d(x, y, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x, y, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x, y, 1.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glEnd();
  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

void    OpenGL::draw_lines(int x, int y)
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glBegin(GL_LINES);
  glColor3ub(0, 0, 0);
  glVertex3d(x, y, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x, y, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x, y, 1.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glEnd();
}

void		OpenGL::draw_snake(Node const &node)
{
  int		x = node._posX;
  int		y = node._posY;

  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  draw_lines(x, y);
  glBegin(GL_QUADS);
  glColor3ub(node._color[0], node._color[1], node._color[2]);
  glVertex3d(x, y, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x, y, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glVertex3d(x, y, 0.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y, 0.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 0.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glVertex3d(x, y - 1, 1.5);
  glVertex3d(x, y, 1.5);
  glVertex3d(x - 1, y, 1.5);
  glVertex3d(x - 1, y - 1, 1.5);
  glEnd();
  glPopMatrix();
}

void	        OpenGL::update(Env &env)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (!env._in_game)
    {
      game_over(env._width, env._height);
      return ;
    }
  cam(env._width, env._height);
  draw_grid(env._width, env._height);
  draw_food(env._food);
  for (std::list<Node>::iterator it = env._snake.begin(); it != env._snake.end(); ++it)
    draw_snake(*it);
  glColor3ub(255, 255, 255);
  glFlush();
  SDL_GL_SwapBuffers();
}

enum EventType		OpenGL::event()
{
  SDL_Event	event;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	return (Escape);
      else if (event.key.keysym.sym == SDLK_ESCAPE)
	return (Escape);
      else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT)
        return (Left);
      else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
	return (Right);
      else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q)
	return (Key_Q);
      else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_UP)
	return (Plus);
      else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN)
	return (Minus);
      else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
	return (Space);
    }
  return (Nothing);
}

int	        OpenGL::init()
{
  SDL_Init(SDL_INIT_VIDEO);
  glEnable(GL_DEPTH_TEST);
  SDL_WM_SetCaption("Nibbler For PRO!", NULL);
  _window =  SDL_SetVideoMode(SCREEN_W, SCREEN_H, SCREEN_DEPTH, SDL_OPENGL);
  glMatrixMode(GL_PROJECTION);
  glEnable(GL_DEPTH_TEST);
  gluPerspective(70, (double)SCREEN_W / SCREEN_H, 1, 1000);
  sound();
  texture1 = loadTexture("./ressources/grass.bmp");
  texture2 = loadTexture("./ressources/wall.bmp");
  texture3 = loadTexture("./ressources/gameover.bmp");
  texture4 = loadTexture("./ressources/apple.bmp");
  return (0);
}
