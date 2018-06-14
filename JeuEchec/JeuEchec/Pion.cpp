#include "Pion.h"



Pion::Pion(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces(i_Black, i_PosX, i_PosY)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_Pawn.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_Pawn.png");
	}

	m_Rect.x = m_PosX;
	m_Rect.y = m_PosY;
	m_Rect.h = m_ImageBase->h;
	m_Rect.w = m_ImageBase->w;
}


Pion::~Pion()
{
}

void Pion::Promotion()
{
}
void Pion::Mouvement()
{
}

//bool Pion::VerifMouvLegal()
//{
//	return true;
//}

bool Pion::Illuminer()
{
	return true;
}

void Pion::Detruire()
{
}

