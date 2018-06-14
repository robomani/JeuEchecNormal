#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Vector2.h"
#include <vector>

class Board;

class BasePieces
{
public:
	BasePieces(int i_PosX, int i_PosY);
	~BasePieces();

	
	bool Selected;

	virtual void LightPossibleMoves(const Board& i_Board);
	virtual void Mouvement();
	//La bool determine si l'on veut que la case soit illuminer
	virtual void Destroy();
	void Render(SDL_Surface* gScreenSurface, SDL_Rect* a_CaseRect);
	bool IsBlack();
	SDL_Surface* loadSurface(std::string path);

protected:
	bool isBlack;
	int m_PosX;
	int m_PosY;
	SDL_Surface* m_ImageBase = NULL;
	SDL_Rect m_Rect;
};

