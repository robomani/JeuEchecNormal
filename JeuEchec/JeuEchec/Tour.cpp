#include "Tour.h"



Tour::Tour(bool i_Black)
	: BasePieces(i_Black)
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