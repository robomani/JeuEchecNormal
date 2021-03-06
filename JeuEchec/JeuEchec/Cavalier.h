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

	void LightPossibleMoves(Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable);
	bool IsKingVulnerableAtPos(Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX);
	/*
	void Mouvement() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

