#pragma once
#include "Board.h"
#include "BaseCase.h"
#include "BasePieces.h"

class Tour :
	public BasePieces
{
public:
	Tour(bool i_Black);
	~Tour();


	void LightPossibleMoves(Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable);
	bool IsKingVulnerableAtPos(Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX);
	/*
	bool Bouger = false;

	void Mouvement() override;
	//bool VerifMouvLegal() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

