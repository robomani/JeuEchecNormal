#pragma once
#include "BasePieces.h"
class Tour :
	public BasePieces
{
public:
	Tour();
	~Tour();

	bool Bouger = false;

	void Mouvement() override;
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

