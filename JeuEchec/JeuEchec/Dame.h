#pragma once
#include "Board.h"
#include "BaseCase.h"
#include "BasePieces.h"

class BaseCase;
class Board;

class Dame :
	public BasePieces
{
public:
	Dame(bool i_Black);
	~Dame();

	void LightPossibleMoves(const Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable);
	bool IsKingVulnerableAtPos(const Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX);
	/*
	void Mouvement() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

