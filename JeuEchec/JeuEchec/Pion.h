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
	Pion(bool i_Black);
	~Pion();

	bool IsBlack();
	void Promotion();
	void Mouvement();
	void LightPossibleMoves(const Board& i_Board,const int& i_PosY,const int& i_PosX);
	void Destroy();
};

