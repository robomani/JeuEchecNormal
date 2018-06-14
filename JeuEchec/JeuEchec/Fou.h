#pragma once
#include "BasePieces.h"
class Fou :
	public BasePieces
{
public:
	Fou(bool i_Black, int i_PosX, int i_PosY);
	~Fou();

	void Mouvement() override;
	//bool VerifMouvLegal() override;
	bool Illuminer() override;
	void Detruire() override;
};

