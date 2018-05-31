#include "BasePieces.h"



BasePieces::BasePieces()
{
}


BasePieces::~BasePieces()
{
}

bool BasePieces::VerifMouvLegal()
{
	//if (Floor(MousePosition.x/LenghtOfTiles) >= 0 && Floor(MousePosition.x/LenghtOfTiles) <= 7 && Floor(MousePosition.y/LenghtOfTiles) >= 0 && Floor(MousePosition.y/LenghtOfTiles) <= 7)
	{
		return true;
	}
}

void BasePieces::Mouvement()
{
	if (VerifMouvLegal())
	{
		//m_PosX = Floor(MousePosition.x / LenghtOfTiles);
		//m_PosY = loor(MousePosition.y / LenghtOfTiles);
	}
}

bool BasePieces::Illuminer()
{
	return true;
}

void BasePieces::Detruire()
{
	m_PosX = -1;
	m_PosY = -1;
}
