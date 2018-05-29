#pragma once
#include "BasePieces.h"
class Fou :
	public BasePieces
{
public:
	Fou();
	~Fou();

	void Mouvement() override;
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

