#pragma once
#include "BasePieces.h"
class Fou :
	public BasePieces
{
public:
	Fou(bool i_Black, int i_PosX, int i_PosY);
	~Fou();

	void Mouvement() override;
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

