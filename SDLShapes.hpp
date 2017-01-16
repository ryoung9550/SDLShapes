#ifndef _SDLSHAPES_HPP
#define _SDLSHAPES_HPP

#include <SDL2/SDL.h>

namespace sp {

struct RGB8 { char R, G, B; };

RGB8 Red = {(char) 255, 0, 0};
RGB8 Green = {0, (char) 255, 0};
RGB8 Blue = {0, 0, (char) 255};
RGB8 Yellow = {(char) 255, (char) 255, 0};
RGB8 Magenta = {(char) 255, 0, (char) 255};
RGB8 Teal = {0, (char) 255, (char) 255};
RGB8 White = {(char) 255, (char) 255, (char) 255};
RGB8 Black = {0, 0, 0};

/* Draws a pixel at a specified point on a surface. The pixel cannot be drawn
 * beyond the bounds of the surface. */
void DrawPixel(SDL_Surface* drawSurface, const int &Xpos, const int &Ypos, const RGB8 &color);

void SwapInt(int &a, int&b);
void DrawLine(SDL_Surface* drawSurface, int x1, int y1, int x2, int y2, const RGB8 &color = White);
void DrawCircle(SDL_Surface* drawSurface, const int &x, const int &y, const int &r, const RGB8 &color = White);
void DrawFillCircle(SDL_Surface* drawSurface, const int &x, const int &y, const int &r, const RGB8 &color = White);

}; // namespace sp


#endif // _SDLSHAPES_HPP
