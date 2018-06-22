#include "Cavalier.h"



Cavalier::Cavalier(bool i_Black)
	:BasePieces(i_Black)
{
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_Horse.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_Horse.png");
	}
}


Cavalier::~Cavalier()
{
}

void Cavalier::LightPossibleMoves(Board& i_Board,const int& i_PosY, const int& i_PosX, const bool i_Vulnerable)
{
	if (i_PosX > 0 && i_PosY > 1)
	{
		if (i_Board.m_Cases[i_PosY - 2][i_PosX - 1]->m_Piece == nullptr
		|| i_Board.m_Cases[i_PosY - 2][i_PosX - 1]->m_Piece->IsBlack() != IsBlack())
		{
			if (!i_Vulnerable)
			{
				if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - 2, i_PosX - 1))
				{
					i_Board.m_Cases[i_PosY - 2][i_PosX - 1]->SetCaseLight(true, i_Board);
				}
			}
			else
			{
				i_Board.m_Cases[i_PosY - 2][i_PosX - 1]->SetVulnerability(true);
			}
		}
		else if (i_Board.m_Cases[i_PosY - 2][i_PosX - 1]->m_Piece != nullptr
			|| i_Board.m_Cases[i_PosY - 2][i_PosX - 1]->m_Piece->IsBlack() == IsBlack())
		{
			if (i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY - 2][i_PosX - 1]->SetVulnerability(true);
			}
		}
	}

	if (i_PosX < 7 && i_PosY > 1)
	{
		if (i_Board.m_Cases[i_PosY - 2][i_PosX + 1]->m_Piece == nullptr
		|| i_Board.m_Cases[i_PosY - 2][i_PosX + 1]->m_Piece->IsBlack() != IsBlack())
		{
			if (!i_Vulnerable)
			{
				if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - 2, i_PosX + 1))
				{
					i_Board.m_Cases[i_PosY - 2][i_PosX + 1]->SetCaseLight(true, i_Board);
				}
			}
			else
			{
				i_Board.m_Cases[i_PosY - 2][i_PosX + 1]->SetVulnerability(true);
			}
		}
		else if (i_Board.m_Cases[i_PosY - 2][i_PosX + 1]->m_Piece != nullptr
			|| i_Board.m_Cases[i_PosY - 2][i_PosX + 1]->m_Piece->IsBlack() == IsBlack())
		{
			if (i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY - 2][i_PosX + 1]->SetVulnerability(true);
			}
		}
	}

	if (i_PosX < 6 && i_PosY > 0)
	{
		if (i_Board.m_Cases[i_PosY - 1][i_PosX + 2]->m_Piece == nullptr
			|| i_Board.m_Cases[i_PosY - 1][i_PosX + 2]->m_Piece->IsBlack() != IsBlack())
		{
			if (!i_Vulnerable)
			{
				if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - 1, i_PosX + 2))
				{
					i_Board.m_Cases[i_PosY - 1][i_PosX + 2]->SetCaseLight(true, i_Board);
				}
			}
			else
			{
				i_Board.m_Cases[i_PosY - 1][i_PosX + 2]->SetVulnerability(true);
			}
		}
		else if (i_Board.m_Cases[i_PosY - 1][i_PosX + 2]->m_Piece != nullptr
			|| i_Board.m_Cases[i_PosY - 1][i_PosX + 2]->m_Piece->IsBlack() == IsBlack())
		{
			if (i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY - 1][i_PosX + 2]->SetVulnerability(true);
			}
		}
	}

	if (i_PosX < 6 && i_PosY < 7)
	{
		if (i_Board.m_Cases[i_PosY + 1][i_PosX + 2]->m_Piece == nullptr
			|| i_Board.m_Cases[i_PosY + 1][i_PosX + 2]->m_Piece->IsBlack() != IsBlack())
		{
			if (!i_Vulnerable)
			{
				if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + 1, i_PosX + 2))
				{
					i_Board.m_Cases[i_PosY + 1][i_PosX + 2]->SetCaseLight(true, i_Board);
				}
			}
			else
			{
				i_Board.m_Cases[i_PosY + 1][i_PosX + 2]->SetVulnerability(true);
			}
		}
		else if (i_Board.m_Cases[i_PosY + 1][i_PosX + 2]->m_Piece != nullptr
			|| i_Board.m_Cases[i_PosY + 1][i_PosX + 2]->m_Piece->IsBlack() == IsBlack())
		{
			if (i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY + 1][i_PosX + 2]->SetVulnerability(true);
			}
		}
	}

	if (i_PosX < 7 && i_PosY < 6)
	{
		if (i_Board.m_Cases[i_PosY + 2][i_PosX + 1]->m_Piece == nullptr
			|| i_Board.m_Cases[i_PosY + 2][i_PosX + 1]->m_Piece->IsBlack() != IsBlack())
		{
			if (!i_Vulnerable)
			{
				if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + 2, i_PosX + 1))
				{
					i_Board.m_Cases[i_PosY + 2][i_PosX + 1]->SetCaseLight(true, i_Board);
				}
			}
			else
			{
				i_Board.m_Cases[i_PosY + 2][i_PosX + 1]->SetVulnerability(true);
			}
		}
		else if (i_Board.m_Cases[i_PosY + 2][i_PosX + 1]->m_Piece != nullptr
			|| i_Board.m_Cases[i_PosY + 2][i_PosX + 1]->m_Piece->IsBlack() == IsBlack())
		{
			if (i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY + 2][i_PosX + 1]->SetVulnerability(true);
			}
		}
	}

	if (i_PosX > 0 && i_PosY < 6)
	{
		if (i_Board.m_Cases[i_PosY + 2][i_PosX - 1]->m_Piece == nullptr
			|| i_Board.m_Cases[i_PosY + 2][i_PosX - 1]->m_Piece->IsBlack() != IsBlack())
		{
			if (!i_Vulnerable)
			{
				if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + 2, i_PosX - 1))
				{
					i_Board.m_Cases[i_PosY + 2][i_PosX - 1]->SetCaseLight(true, i_Board);
				}
			}
			else
			{
				i_Board.m_Cases[i_PosY + 2][i_PosX - 1]->SetVulnerability(true);
			}
		}
		else if (i_Board.m_Cases[i_PosY + 2][i_PosX - 1]->m_Piece != nullptr
			|| i_Board.m_Cases[i_PosY + 2][i_PosX - 1]->m_Piece->IsBlack() == IsBlack())
		{
			if (i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY + 2][i_PosX - 1]->SetVulnerability(true);
			}
		}
	}

	if (i_PosX > 1 && i_PosY < 7)
	{
		if (i_Board.m_Cases[i_PosY + 1][i_PosX - 2]->m_Piece == nullptr
			|| i_Board.m_Cases[i_PosY + 1][i_PosX - 2]->m_Piece->IsBlack() != IsBlack())
		{
			if (!i_Vulnerable)
			{
				if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + 1, i_PosX - 2))
				{
					i_Board.m_Cases[i_PosY + 1][i_PosX - 2]->SetCaseLight(true, i_Board);
				}
			}
			else
			{
				i_Board.m_Cases[i_PosY + 1][i_PosX - 2]->SetVulnerability(true);
			}
		}
		else if (i_Board.m_Cases[i_PosY + 1][i_PosX - 2]->m_Piece != nullptr
			|| i_Board.m_Cases[i_PosY + 1][i_PosX - 2]->m_Piece->IsBlack() == IsBlack())
		{
			if (i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY + 1][i_PosX - 2]->SetVulnerability(true);
			}
		}
	}

	if (i_PosX > 1 && i_PosY > 0)
	{
		if (i_Board.m_Cases[i_PosY - 1][i_PosX - 2]->m_Piece == nullptr
			|| i_Board.m_Cases[i_PosY - 1][i_PosX - 2]->m_Piece->IsBlack() != IsBlack())
		{
			if (!i_Vulnerable)
			{
				if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY - 1, i_PosX - 2))
				{
					i_Board.m_Cases[i_PosY - 1][i_PosX - 2]->SetCaseLight(true, i_Board);
				}
			}
			else
			{
				i_Board.m_Cases[i_PosY - 1][i_PosX - 2]->SetVulnerability(true);
			}
		}
		else if(i_Board.m_Cases[i_PosY - 1][i_PosX - 2]->m_Piece != nullptr
			|| i_Board.m_Cases[i_PosY - 1][i_PosX - 2]->m_Piece->IsBlack() == IsBlack())
		{
			if(i_Vulnerable)
			{
				i_Board.m_Cases[i_PosY - 1][i_PosX - 2]->SetVulnerability(true);
			} 
		}
	}
}

bool Cavalier::IsKingVulnerableAtPos(Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX)
{
	return BasePieces::IsKingVulnerableAtPos(i_Board, i_PreviousPosY, i_PreviousPosX, i_PosY, i_PosX);
}

/*
void Cavalier::Mouvement()
{
}

bool Cavalier::Illuminer()
{
	return true;
}

void Cavalier::Detruire()
{
}
*/