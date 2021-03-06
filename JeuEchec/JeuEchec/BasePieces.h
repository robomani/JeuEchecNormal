#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Vector2.h"
#include <vector>
#include <memory>

class Board;

class BasePieces
{
public:
	BasePieces(bool i_Black);
	~BasePieces();

	bool hasMoved = false;
	bool Selected;
	bool isKing = false;
	bool check = false;

	virtual void LightPossibleMoves(Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable);
	virtual bool IsKingVulnerableAtPos(Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX);
	virtual void Mouvement();
	virtual void Destroy();
	void Render(SDL_Surface* gScreenSurface, SDL_Rect* a_CaseRect);
	virtual bool IsBlack();
	SDL_Surface* loadSurface(std::string path);

protected:
	bool m_Black;
	SDL_Surface* m_ImageBase = NULL;
};