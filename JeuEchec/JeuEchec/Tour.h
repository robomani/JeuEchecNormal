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


	void LightPossibleMoves(const Board& i_Board, const int& i_PosY, const int& i_PosX);
	/*
	bool Bouger = false;

	void Mouvement() override;
	//bool VerifMouvLegal() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

