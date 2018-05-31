#pragma once
#include "BasePieces.h"
class Dame :
	public BasePieces
{
public:
	Dame(bool i_Black, int i_PosX, int i_PosY);
	~Dame();

	void Mouvement() override;
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

