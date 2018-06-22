#pragma once
#include "Board.h"
#include "BaseCase.h"
#include "BasePieces.h"

class BaseCase;
class Board;

class Roi :
	public BasePieces
{
public:
	Roi(bool i_Black);
	~Roi();

	void LightPossibleMoves(Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable);
	bool IsKingVulnerableAtPos(Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX);

	/*
	bool Bouger = false;
	bool Echec = false;


	void Roque();
	void Mouvement() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

