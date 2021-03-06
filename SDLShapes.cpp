#include <SDL2/SDL.h>
#include "SDLShapes.hpp"
#include <cmath>
#include <vector>

#ifndef PI
#define PI 3.14159265
#endif

#define max(x, y) ((x > y) ? (x) : (y))
#define min(x, y) ((x < y) ? (x) : (y))

namespace sp {

// Color Presets 
const RGB8 Red = {(char) 255, 0, 0};
const RGB8 Green = {0, (char) 255, 0};
const RGB8 Blue = {0, 0, (char) 255};
const RGB8 Yellow = {(char) 255, (char) 255, 0};
const RGB8 Magenta = {(char) 255, 0, (char) 255};
const RGB8 Teal = {0, (char) 255, (char) 255};
const RGB8 White = {(char) 255, (char) 255, (char) 255};
const RGB8 Black = {0, 0, 0};

/* Draws a pixel at a specified point on a surface. The pixel cannot be drawn
 * beyond the bounds of the surface. */
void DrawPixel(SDL_Surface* drawSurface, const int &Xpos, const int &Ypos, const RGB8 &color) {
	if( Xpos >= 0 && Xpos < drawSurface->w && Ypos >= 0 && Ypos < drawSurface->h)
		((Uint32*)drawSurface->pixels)[Ypos * drawSurface->pitch/4 + Xpos] = SDL_MapRGB(drawSurface->format, color.R, color.G, color.B);
}

/* Swaps two integers. SwapInt is a requisite for DrawLine() */
void SwapInt(int &a, int &b) {
	int aBuffer = a;
	a = b;
	b = aBuffer;
}

/* Draws line with given points, point componants, or line struct to a passed SDL screen.
 * Colors of the lines can be changed to presets or custom colors. The default
  * color is white. */
void DrawLine(SDL_Surface* drawSurface, int x1, int y1, int x2, int y2, const RGB8 &color) {
	bool step = abs(x1 - x2) < abs(y1 - y2);
	if(step) { SwapInt(x1, y1); SwapInt(x2, y2); }
	if(x2 < x1) { SwapInt(x1, x2); SwapInt(y1, y2); }
	float error = 0.0;
	float slope = ((float) abs(y2 - y1)) / ((float) (x2 - x1));
	int y = y1;
	int ystep = (y2 > y1 ? 1 : -1);
	for( int pixel = x1; pixel < x2; ++pixel) {
		if(step)
			DrawPixel(drawSurface, y, pixel, color);
		else
			DrawPixel(drawSurface, pixel, y, color);
		error += slope;
		if(error >= 0.5) {
			y += ystep;
			error -= 1.0;
		}
	}
}

void DrawLine(SDL_Surface* drawSurface, const point &p1, const point &p2, const RGB8 &color) {
	DrawLine(drawSurface, p1.x, p1.y, p2.x, p2.y, color);
}
void DrawLine(SDL_Surface* drawSurface, const line &src, const RGB8 &color) {
	DrawLine(drawSurface, src.p1.x, src.p1.y, src.p2.x, src.p2.y, color);
}
/* Draws hollow circle with a passed point and radius, or circle struct. Function draws
 * circle onto a passed SDL screen. Can be given different colors. The default
  * is white. */
void DrawCircle(SDL_Surface* drawSurface, const int &x, const int &y, const int &r, const RGB8 &color) {
	int x1, x2, y1, y2;
	int precision = 2;
	for( int deg = precision; deg <= 360; deg = deg + precision) {
		x1 = cos((deg - precision) * PI / 180.0) * r + x;
		y1 = sin((deg - precision) * PI / 180.0) * r + y;
		x2 = cos(deg * PI / 180.0) * r + x;
		y2 = sin(deg * PI / 180.0) * r + y;
		DrawLine(drawSurface, x1, y1, x2, y2, color);
	}
}
void DrawCircle(SDL_Surface* drawSurface, const point &src, const float &radius, const RGB8 &color) {
	DrawCircle(drawSurface, src.x, src.y, radius, color);
}
void DrawCircle(SDL_Surface* drawSurface, const circle &src, const RGB8 &color) {
	DrawCircle(drawSurface, src.p1.x, src.p1.y, src.radius, color);
}
void DrawFillCircle(SDL_Surface* drawSurface, const int &x, const int &y, const int &r, const RGB8 &color) {
	int x1, y1, y2;
	float precision = 50;
	DrawCircle(drawSurface, x, y, r, color);
	for( int deg = 1; deg < 180 * r / precision; ++deg) {
		x1 = cos(((float) deg / r * precision) * PI / 180.0) * r + x;
		y1 = sin(((float) deg / r * precision) * PI / 180.0) * r + y + 0.5;
		y2 = -(sin(((float) deg / r * precision) * PI / 180.0)) * r + y;
		DrawLine(drawSurface, x1, y1, x1, y2, color);
	}
}
void DrawRect(SDL_Surface* drawSurface, const int &x1, const int &y1, const int &x2, const int &y2, const int &x3, const int &y3, const int &x4, const int &y4, const RGB8 &color) {
	DrawLine(drawSurface, x1, y1, x2, y2, color);
	DrawLine(drawSurface, x3, y3, x2, y2, color);
	DrawLine(drawSurface, x3, y3, x4, y4, color);
	DrawLine(drawSurface, x1, y1, x4, y4, color);
}

void DrawTriangle(SDL_Surface* drawSurface, const point &p1, const point &p2, const point &p3, const RGB8 &color = White) {
	DrawLine(drawSurface, p1, p2, color);
	DrawLine(drawSurface, p2, p3, color);
	DrawLine(drawSurface, p3, p1, color);
}

};
