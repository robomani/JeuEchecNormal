#include "Roi.h"



Roi::Roi(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces(i_Black, i_PosX, i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_King.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_King.png");
	}
}


Roi::~Roi()
{
}

/*
void Roi::Roque()
{
}

void Roi::Mouvement()
{
}

bool Roi::VerifMouvLegal()
{
	return true;
}

bool Roi::Illuminer()
{
	return true;
}

void Roi::Detruire()
{
}
*/