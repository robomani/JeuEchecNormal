#pragma once
#include "BasePieces.h"
class Cavalier :
	public BasePieces
{
public:
	Cavalier();
	~Cavalier();

	void Mouvement() override;
	void VerifMouvLegal() override;
	void Illuminer() override;
	void Detruire() override;
};

