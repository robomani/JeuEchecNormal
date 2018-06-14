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
	BasePieces(bool i_Black);
	~BasePieces();

	bool hasMoved = false;
	bool Selected;

	virtual void LightPossibleMoves(const Board& i_Board, const int& i_PosY, const int& i_PosX);
	virtual void Mouvement();
	virtual void Destroy();
	void Render(SDL_Surface* gScreenSurface, SDL_Rect* a_CaseRect);
	virtual bool IsBlack();
	SDL_Surface* loadSurface(std::string path);

protected:
	bool m_Black;
	SDL_Surface* m_ImageBase = NULL;
};

