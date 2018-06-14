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
	BasePieces(bool i_Black, int i_PosX, int i_PosY);
	~BasePieces();

	bool hasMoved = false;
	bool Selected;

	virtual void LightPossibleMoves(const Board& i_Board);
	virtual void Mouvement();
	virtual void Destroy();
	void Render(SDL_Surface* gScreenSurface, SDL_Rect* a_CaseRect);
	virtual bool IsBlack();
	SDL_Surface* loadSurface(std::string path);

protected:
	bool m_Black;
	int m_PosX;
	int m_PosY;
	SDL_Surface* m_ImageBase = NULL;
};

