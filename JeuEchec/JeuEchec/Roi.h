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
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

