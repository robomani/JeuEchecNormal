#include "Roi.h"



Roi::Roi(bool i_Black)
	: BasePieces(i_Black)
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

bool Roi::LightPossibleMoves()
{
	if(possible move != vulnérable)
	{
		Case[y][x].SetAlight(true);
	}
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