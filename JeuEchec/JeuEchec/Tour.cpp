#include "Tour.h"



Tour::Tour(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces(i_Black, i_PosX, i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_Rook.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_Rook.png");
	}
}


Tour::~Tour()
{
}

/*
void Tour::Mouvement()
{
}

bool Tour::VerifMouvLegal()
{
	return true;
}

bool Tour::Illuminer()
{
	return true;
}

void Tour::Detruire()
{
}
*/