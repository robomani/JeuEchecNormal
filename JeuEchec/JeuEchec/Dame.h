#pragma once
#include "BasePieces.h"
class Dame :
	public BasePieces
{
public:
	Dame(bool i_Black);
	~Dame();

	/*
	void Mouvement() override;
	bool VerifMouvLegal() override;
	bool Illuminer() override;
	void Detruire() override;
	*/
};

