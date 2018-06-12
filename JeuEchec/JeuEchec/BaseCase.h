#pragma once
#include <SDL.h>
#include "BasePieces.h"
#include <SDL_image.h>
#include <string>

class BaseCase
{


public:
	SDL_Rect m_CaseRect;

	BaseCase(int i_PosX = -50, int i_PosY = -50, BasePieces* i_Piece = nullptr);
	~BaseCase();

	int PosX;
	int PosY;
	BasePieces* m_Piece;

	SDL_Surface* m_ImageBase = NULL;
	SDL_Surface* m_ImageIlluminer = NULL;
	SDL_Surface* m_ImageCurrent = NULL;
	SDL_Surface* loadSurface(std::string path);

	//La bool determine si l'on veut que la case soit illuminer
	virtual bool Illuminer(bool i_Voulue);
	void Render(SDL_Surface* gScreenSurface);
};

