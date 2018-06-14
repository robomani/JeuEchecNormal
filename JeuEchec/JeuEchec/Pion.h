#pragma once
#include "Board.h"
#include "BaseCase.h"
#include "BasePieces.h"

class Board;
class BaseCase;

class Pion :
	public BasePieces
{
public:
	Pion(bool i_Black, int i_PosX, int i_PosY);
	~Pion();

	bool hasMoved = false;

	void Promotion();
	void Mouvement();
	void LightPossibleMoves(const Board& i_Board);
	void Destroy();
};

