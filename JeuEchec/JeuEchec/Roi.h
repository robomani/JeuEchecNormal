#pragma once
#include "BasePieces.h"
class Roi :
	public BasePieces
{
public:
	Roi(bool i_Black, int i_PosX, int i_PosY);
	~Roi();

	bool Bouger = false;
	bool Echec = false;

	void Roque();

	void Mouvement() override;
	bool VerifMouvLegal() override;
	bool Illuminer() override;
	void Detruire() override;
};

