#include "Pion.h"



Pion::Pion(bool i_Black)
	: BasePieces(i_Black)
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

void Pion::LightPossibleMoves(const Board& i_Board,const int& i_PosY,const int& i_PosX, const bool i_Vulnerable)
{
	int directionY = 1;

	if (IsBlack())
	{
		directionY = -1;
	}

	//Look for one case movement
	if (i_Board.m_Cases[i_PosY + directionY][i_PosX]->m_Piece == nullptr)
	{
		if (!i_Vulnerable)
		{
			i_Board.m_Cases[i_PosY + directionY][i_PosX]->SetCaseLight(true);
		}
	}
	
	
	//Is has not moved look for double movement
	if (!hasMoved && i_Board.m_Cases[i_PosY + directionY][i_PosX]->m_Piece == nullptr)
	{
		if (i_Board.m_Cases[i_PosY + directionY + directionY][i_PosX]->m_Piece == nullptr)
		{
			if (!i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY + directionY + directionY][i_PosX]->SetCaseLight(true);
			}
		}
	}
	
	
	//Look For a enemy left/fwrd or right/fwrd
	if (i_PosX < 7)
	{

		if (i_Board.m_Cases[i_PosY + directionY][i_PosX + 1]->m_Piece != nullptr || i_Vulnerable)
		{
			if (i_Board.m_Cases[i_PosY + directionY][i_PosX + 1]->m_Piece == nullptr 
			|| i_Board.m_Cases[i_PosY + directionY][i_PosX + 1]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + directionY][i_PosX + 1]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY + directionY][i_PosX + 1]->SetVulnerability(true);
				}
			}
		}
	}
	
	if (i_PosX > 0)
	{
		if (i_Board.m_Cases[i_PosY + directionY][i_PosX - 1]->m_Piece != nullptr || i_Vulnerable)
		{
			if (i_Board.m_Cases[i_PosY + directionY][i_PosX - 1]->m_Piece == nullptr 
			|| i_Board.m_Cases[i_PosY + directionY][i_PosX - 1]->m_Piece->IsBlack() != IsBlack())
			{
				if (!i_Vulnerable)
				{
					i_Board.m_Cases[i_PosY + directionY][i_PosX - 1]->SetCaseLight(true);
				}
				else
				{
					i_Board.m_Cases[i_PosY + directionY][i_PosX - 1]->SetVulnerability(true);
				}
			}
		}
	}
}

void Pion::Destroy()
{
}