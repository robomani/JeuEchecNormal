#include "Dame.h"



Dame::Dame(bool i_Black)
	: BasePieces (i_Black)
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