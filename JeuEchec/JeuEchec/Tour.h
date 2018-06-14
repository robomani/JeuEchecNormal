#pragma once
#include "BasePieces.h"
class Tour :
	public BasePieces
{
public:
	Tour(bool i_Black, int i_PosX, int i_PosY);
	~Tour();

	/*
	bool Bouger = false;

	void Mouvement() override;
	//bool VerifMouvLegal() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

