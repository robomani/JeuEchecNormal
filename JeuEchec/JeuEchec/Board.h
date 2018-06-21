#pragma once
#include "Board.h"
#include <vector>
#include "BaseCase.h"
#include "BasePieces.h"
#include <memory>

//class BaseCase;


class Board
{
	SDL_Surface* m_BoardSurface = nullptr;

public:
	Board();
	~Board();

	int m_Height;
	int m_Width;

	std::vector<std::vector<std::shared_ptr<BaseCase>>> m_Cases;
	//BasePieces* m_PiecesInGame[2][16];

	void initialisation();
	void Render(SDL_Surface* gScreenSurface);
};

