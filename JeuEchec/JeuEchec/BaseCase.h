#pragma once
#include <SDL.h>
#include "BasePieces.h"

class BaseCase
{
public:
	BaseCase(int i_PosX, int i_PosY, BasePieces* i_Piece = nullptr);
	~BaseCase();

	int PosX;
	int PosY;
	BasePieces* m_Piece;

	SDL_Surface* m_ImageBase = NULL;
	SDL_Surface* m_ImageIlluminer = NULL;
	SDL_Surface* m_ImageCurrent = NULL;

	//La bool determine si l'on veut que la case soit illuminer
	virtual bool Illuminer(bool i_Voulue);
};

