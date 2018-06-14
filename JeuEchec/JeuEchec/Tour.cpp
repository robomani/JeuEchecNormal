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

void Tour::LightPossibleMoves(const Board& i_Board, const int& i_PosY, const int& i_PosX)
{
	int directionY = 1;

	if (IsBlack())
	{
		directionY = -1;
	}

	//Look for one case movement
	if (i_Board.m_Cases[i_PosY + directionY][i_PosX]->m_Piece == nullptr)
	{
		i_Board.m_Cases[i_PosY + directionY][i_PosX]->SetCaseLight(true);
	}



	//Look For a enemy left/fwrd or right/fwrd
	if (i_PosX < 7)
	{
		if (i_Board.m_Cases[i_PosY + directionY][i_PosX + 1]->m_Piece != nullptr)
		{
			if (i_Board.m_Cases[i_PosY + directionY][i_PosX + 1]->m_Piece->IsBlack() != IsBlack())
			{
				i_Board.m_Cases[i_PosY + directionY][i_PosX + 1]->SetCaseLight(true);
			}
		}
	}

	if (i_PosX > 0)
	{
		if (i_Board.m_Cases[i_PosY + directionY][i_PosX - 1]->m_Piece != nullptr)
		{
			if (i_Board.m_Cases[i_PosY + directionY][i_PosX - 1]->m_Piece->IsBlack() != IsBlack())
			{
				i_Board.m_Cases[i_PosY + directionY][i_PosX - 1]->SetCaseLight(true);
			}
		}
	}
}