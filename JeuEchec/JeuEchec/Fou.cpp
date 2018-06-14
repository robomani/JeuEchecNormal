#include "Fou.h"



Fou::Fou(bool i_Black)
	: BasePieces(i_Black)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_Bishop.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_Bishop.png");
	}
}


Fou::~Fou()
{
}

/*
void Fou::Mouvement()
{
}

bool Fou::VerifMouvLegal()
{
	return true;
}

bool Fou::Illuminer()
{
	return true;
}

void Fou::Detruire()
{
}
*/