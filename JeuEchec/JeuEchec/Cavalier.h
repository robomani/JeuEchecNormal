#pragma once
#include "BasePieces.h"
class Cavalier :
	public BasePieces
{
public:
	Cavalier(bool i_Black, int i_PosX, int i_PosY);
	~Cavalier();

	/*
	void Mouvement() override;
	bool VerifMouvLegal() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

