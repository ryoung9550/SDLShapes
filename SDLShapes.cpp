#include <SDL2/SDL.h>
#include "SDLShapes.hpp"
#include <cmath>

#ifndef PI
#define PI 3.14159265
#endif

namespace sp {
	
	void DrawPixel(SDL_Surface* drawSurface, const int &Xpos, const int &Ypos, const RGB8 &color = White) {
		if( Xpos >= 0 && Xpos < drawSurface->w && Ypos >= 0 && Ypos < drawSurface->h)
			((Uint32*)drawSurface->pixels)[Ypos * drawSurface->pitch/4 + Xpos] = SDL_MapRGB(drawSurface->format, color.R, color.G, color.B);
	}

	void SwapInt(int &a, int &b) {
		int aBuffer = a;
		a = b;
		b = aBuffer;
	}

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

	void DrawFillCircle(SDL_Surface* drawSurface, const int &x, const int &y, const int &r, RGB8 color) {
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

	


};
