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
}


Pion::~Pion()
{
}

bool Pion::IsBlack()
{
	return BasePieces::IsBlack();
}

void Pion::Promotion()
{
}

void Pion::Mouvement()
{
}

void Pion::LightPossibleMoves(const Board& i_Board)
{
	int directionY = 1;

	if (IsBlack())
	{
		directionY = -1;
	}

	//Look for one case movement
	if (i_Board.m_Cases[m_PosY + directionY][m_PosX]->m_Piece == nullptr)
	{
		i_Board.m_Cases[m_PosY + directionY][m_PosX]->SetCaseLight(true);
	}
	
	
	//Is has not moved look for double movement
	if (!hasMoved && i_Board.m_Cases[m_PosY + directionY][m_PosX]->m_Piece == nullptr)
	{
		if (i_Board.m_Cases[m_PosY + directionY + directionY][m_PosX]->m_Piece == nullptr)
		{
			i_Board.m_Cases[m_PosY + directionY + directionY][m_PosX]->SetCaseLight(true);
		}
	}
	
	
	//Look For a enemy left/fwrd or right/fwrd
	/*
	if (m_PosX < 7)
	{
		if (i_Board.m_Cases[m_PosY + directionY][m_PosX + 1]->m_Piece->IsBlack() != IsBlack())
		{
			i_Board.m_Cases[m_PosY + directionY][m_PosX + 1]->SetCaseLight(true);
		}
	}
	
	if (m_PosX > 0)
	{
		if (i_Board.m_Cases[m_PosY + directionY][m_PosX - 1]->m_Piece->IsBlack() != IsBlack())
		{
			i_Board.m_Cases[m_PosY + directionY][m_PosX - 1]->SetCaseLight(true);
		}
	}
	*/
}

void Pion::Destroy()
{
}