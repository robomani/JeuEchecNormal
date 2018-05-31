#pragma once
#include "BasePieces.h"
class Pion :
	public BasePieces
{
public:
	Pion(bool i_Black, int i_PosX, int i_PosY);
	~Pion();

	void Promotion();

	void Mouvement() override;
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

