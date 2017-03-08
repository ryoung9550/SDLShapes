#ifndef _SDLSHAPES_HPP
#define _SDLSHAPES_HPP

#include <SDL2/SDL.h>

namespace sp {

struct RGB8 { char R /*Red*/, G /*Green*/, B /*Blue*/; }; // simple RGB color structure
struct point { float x, y; }; // simple point structure containing x and y values
struct line { point p1, p2; }; // simple line structure containing two point structures
struct rect { point p1, p2, p3, p4; }; // simple quadrilateral structure containing four points
struct circle { point p1; float radius; }; // simple circle structure containing a point and radius

/* Preset Colors for shapes */
const extern RGB8 Red;
const extern RGB8 Green;
const extern RGB8 Blue;
const extern RGB8 Yellow;
const extern RGB8 Magenta;
const extern RGB8 Teal;
const extern RGB8 White;
const extern RGB8 Black;

/* Draws a pixel at a specified point on a surface. The pixel cannot be drawn
 * beyond the bounds of the surface. */
void DrawPixel(SDL_Surface* drawSurface, const int &Xpos, const int &Ypos, const RGB8 &color = White);

/* Swaps two integers. SwapInt is a requisite for DrawLine() */
void SwapInt(int &a, int&b);

/* Draws line with given points, point componants, or line struct to a passed SDL screen.
 * Colors of the lines can be changed to presets or custom colors. The default
 * color is white. */
void DrawLine(SDL_Surface* drawSurface, int x1, int y1, int x2, int y2, const RGB8 &color = White);
void DrawLine(SDL_Surface* drawSurface, const point &p1, const point &p2, const RGB8 &color = White);
void DrawLine(SDL_Surface* drawSurface, const line &src, const RGB8 &color = White);

/* Draws hollow circle with a passed point and radius, or circle struct. Function draws
 * circle onto a passed SDL screen. Can be given different colors. The default
 * is white. */
void DrawCircle(SDL_Surface* drawSurface, const int &x, const int &y, const int &r, const RGB8 &color = White);
void DrawCircle(SDL_Surface* drawSurface, const point &src, const float &radius, const RGB8 &color = White);
void DrawCircle(SDL_Surface* drawSurface, const circle &src, const RGB8 &color = White);

/* Draws a filled circle with a passed point and radius, or circle struct. Function 
 * draws circle onto a passed SDL Screen. Can be given different colors. The
 * default is white. */
void DrawFillCircle(SDL_Surface* drawSurface, const int &x, const int &y, const int &r, const RGB8 &color = White);

void DrawTriangle(SDL_Surface* drawSurface, const point &p1, const point &p2, const point &p3, const RGB8 &color);

}; // namespace sp


#endif // _SDLSHAPES_HPP
