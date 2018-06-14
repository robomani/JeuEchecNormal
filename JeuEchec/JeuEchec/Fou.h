#pragma once
#include "BasePieces.h"
class Fou :
	public BasePieces
{
public:
	Fou(bool i_Black);
	~Fou();
	void LightPossibleMoves(const Board& i_Board, const int& i_PosY, const int& i_PosX);
	/*
	void Mouvement() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

