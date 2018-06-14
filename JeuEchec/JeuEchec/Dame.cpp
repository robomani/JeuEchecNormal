#include "Dame.h"



Dame::Dame(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces (i_Black, i_PosX, i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_Queen.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_Queen.png");
	}
}


Dame::~Dame()
{
}

/*
void Dame::Mouvement()
{
}

bool Dame::VerifMouvLegal()
{
	return true;
}

bool Dame::Illuminer()
{
	return true;
}

void Dame::Detruire()
{
}
*/