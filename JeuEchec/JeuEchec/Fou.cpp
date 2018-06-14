#include "Fou.h"



Fou::Fou(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces(i_PosX, i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_Bishop.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_Bishop.png");
	}

	m_Rect.x = m_PosX;
	m_Rect.y = m_PosY;
	m_Rect.h = m_ImageBase->h;
	m_Rect.w = m_ImageBase->w;
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