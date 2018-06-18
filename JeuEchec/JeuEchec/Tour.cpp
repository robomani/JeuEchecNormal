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
	//Bool that turn false when a object or a border is found to stop the check in that direction.
	bool checkRight = true;
	bool checkLeft = true;
	bool checkTop = true;
	bool checkBottom = true;

	for (int x = 1; x < 8; x++)
	{
		if (i_PosX + x < 8)
		{
			//Look for right direction
			if (checkRight && (i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece == nullptr))
			{
				i_Board.m_Cases[i_PosY][i_PosX + x]->SetCaseLight(true);
			}
			else if (checkRight && i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
			{
				i_Board.m_Cases[i_PosY][i_PosX + x]->SetCaseLight(true);
				checkRight = false;
			}
			else
			{
				checkRight = false;
			}
		}

		if (i_PosX - x > -1)
		{
			//Look for left direction
			if (checkLeft && (i_Board.m_Cases[i_PosY][i_PosX - x]->m_Piece == nullptr))
			{
				i_Board.m_Cases[i_PosY][i_PosX - x]->SetCaseLight(true);
			}
			else if (checkLeft && i_Board.m_Cases[i_PosY][i_PosX - x]->m_Piece->IsBlack() != IsBlack())
			{
				i_Board.m_Cases[i_PosY][i_PosX - x]->SetCaseLight(true);
				checkLeft = false;
			}
			else
			{
				checkLeft = false;
			}
		}

		if (i_PosY + x < 8)
		{
			//look for top direction
			if (checkTop && (i_Board.m_Cases[i_PosY + x][i_PosX]->m_Piece == nullptr))
			{
				i_Board.m_Cases[i_PosY + x][i_PosX]->SetCaseLight(true);
			}
			else if (checkTop && i_Board.m_Cases[i_PosY + x][i_PosX]->m_Piece->IsBlack() != IsBlack())
			{
				i_Board.m_Cases[i_PosY + x][i_PosX]->SetCaseLight(true);
				checkTop = false;
			}
			else
			{
				checkTop = false;
			}
		}

		if (i_PosY - x > -1)
		{
			//Look for bottom direction
			if (checkBottom && (i_Board.m_Cases[i_PosY - x][i_PosX]->m_Piece == nullptr))
			{
				i_Board.m_Cases[i_PosY - x][i_PosX]->SetCaseLight(true);
			}
			else if (checkBottom && i_Board.m_Cases[i_PosY - x][i_PosX]->m_Piece->IsBlack() != IsBlack())
			{
				i_Board.m_Cases[i_PosY - x][i_PosX]->SetCaseLight(true);
				checkBottom = false;
			}
			else
			{
				checkBottom = false;
			}
		}
	}
}