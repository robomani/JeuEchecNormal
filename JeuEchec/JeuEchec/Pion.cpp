#include "Pion.h"



Pion::Pion(bool i_Black, int i_PosX, int i_PosY)
	: BasePieces(i_PosX, i_PosY)
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

void Pion::LightPossibleMoves(const Board& i_Board)
{
	int directionY = 1;

	if (IsBlack())
	{
		directionY = -1;
	}

	//Look for one case movement
	if (i_Board.m_Cases[floor(m_PosY / 50) + directionY][floor(m_PosX / 50)]->m_Piece == nullptr)
	{
		i_Board.m_Cases[floor(m_PosY / 50) + directionY][floor(m_PosX / 50)]->SetCaseLight(true);
	}
	
	//Is has not moved look for double movement
	if (!hasMoved && i_Board.m_Cases[floor(m_PosY / 50) + directionY][floor(m_PosX / 50)]->m_Piece == nullptr)
	{
		if (i_Board.m_Cases[floor(m_PosY / 50) + directionY + directionY][floor(m_PosX / 50)]->m_Piece == nullptr)
		{
			i_Board.m_Cases[floor(m_PosY / 50) + directionY + directionY][floor(m_PosX / 50)]->SetCaseLight(true);
		}
	}
	
	//Look For a enemy left/fwrd or right/fwrd
	if (i_Board.m_Cases[floor(m_PosY / 50) + directionY][floor(m_PosX / 50) + 1]->m_Piece->IsBlack() != IsBlack())
	{
		i_Board.m_Cases[floor(m_PosY / 50) + directionY][floor(m_PosX / 50) + 1]->SetCaseLight(true);
	}	
	
	if (i_Board.m_Cases[floor(m_PosY / 50) + directionY][floor(m_PosX / 50) - 1]->m_Piece->IsBlack() != IsBlack())
	{
		i_Board.m_Cases[floor(m_PosY / 50) + directionY][floor(m_PosX / 50) - 1]->SetCaseLight(true);
	}
}

void Pion::Destroy()
{
}