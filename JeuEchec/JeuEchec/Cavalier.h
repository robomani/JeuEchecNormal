#pragma once
#include "Board.h"
#include "BaseCase.h"
#include "BasePieces.h"

class Board;
class BaseCase;

class Cavalier :
	public BasePieces
{
public:
	Cavalier(bool i_Black);
	~Cavalier();

	void LightPossibleMoves(const Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable);
	/*
	void Mouvement() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

