#pragma once
#include "BasePieces.h"
class Dame :
	public BasePieces
{
public:
	Dame(bool i_Black, int i_PosX, int i_PosY);
	~Dame();

	void Mouvement() override;
	bool VerifMouvLegal() override;
	bool Illuminer() override;
	void Detruire() override;
};

