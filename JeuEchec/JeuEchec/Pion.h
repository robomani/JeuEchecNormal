#pragma once
#include "BasePieces.h"
class Pion :
	public BasePieces
{
public:
	Pion();
	~Pion();

	void Promotion();

	void Mouvement() override;
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

