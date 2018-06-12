#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Vector2.h"
#include <vector>
//#include "Board.h"

class Board;

class BasePieces
{
public:
	BasePieces(int i_PosX, int i_PosY);
	~BasePieces();

	
	bool Selected;

	virtual std::vector<Vector2> VerifMouvLegal(const Board& i_Board) { return std::vector<Vector2>(); }
	virtual void Mouvement();
	//La bool determine si l'on veut que la case soit illuminer
	virtual bool Illuminer();
	virtual void Detruire();
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

