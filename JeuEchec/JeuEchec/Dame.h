#pragma once
#include "BasePieces.h"
class Dame :
	public BasePieces
{
public:
	Dame();
	~Dame();

	void Mouvement() override;
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

