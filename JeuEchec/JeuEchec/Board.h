#pragma once
#include "Board.h"
#include <vector>
#include "BasePieces.h"

class BaseCase;


class Board
{
	SDL_Surface* m_BoardSurface = nullptr;

public:
	Board();
	~Board();

	int m_Hauteur;
	int m_Largeur;

	std::vector<std::vector<BaseCase*>> m_Cases;
	BasePieces* m_PiecesEnJeu[2][16];

	void initialisation();
	void Render(SDL_Surface* gScreenSurface);
};

