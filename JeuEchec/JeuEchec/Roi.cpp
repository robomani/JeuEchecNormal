#include "Roi.h"



Roi::Roi(bool i_Black)
	: BasePieces(i_Black)
{
	isKing = true;
	if (i_Black)
	{
		m_ImageBase = loadSurface("ArtWork/Black_King.png");
	}
	else
	{
		m_ImageBase = loadSurface("ArtWork/White_King.png");
	}
}


Roi::~Roi()
{
}


void Roi::LightPossibleMoves(Board& i_Board, const int& i_PosY, const int& i_PosX, const bool i_Vulnerable)
{
	//Loop in a -1 -> 1 range in X and Y around the pawn.
	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			//Prevent check at his own position.
			if (x != 0 || y != 0)
			{
				//Prevent look outside the Grid in negative X axis.
				if (x <= 0)
				{
					if (i_PosX >= 0)
					{
						//Prevent look outside the Grid in Y axis.
						if (y <= 0)
						{
							if (i_PosY > 0)
							{
								if (i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY + y][i_PosX + x]->isVulnerable)
										{
											i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetCaseLight(true, i_Board);
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetVulnerability(true);
									}
								}	
								else if (i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetVulnerability(true);
									}
								}
							}
							else if (i_PosY == 0)
							{
								if (i_Board.m_Cases[i_PosY ][i_PosX + x]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY][i_PosX + x]->isVulnerable)
										{
											i_Board.m_Cases[i_PosY][i_PosX + x]->SetCaseLight(true, i_Board);
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
									}
								}
								else if (i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
									}
								}
							}
						}
						else if (y > 0)
						{
							if (i_PosY < 7)
							{
								if (i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY + y][i_PosX + x]->isVulnerable)
										{
											i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetCaseLight(true, i_Board);
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetVulnerability(true);
									}
								}
								else if (i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetVulnerability(true);
									}
								}
							}
						}
					}					
					else if (i_PosX == 0)
					{
						//Prevent look outside the Grid in Y axis.
						if (y <= 0)
						{
							if (i_PosY > 0)
							{
								if (i_Board.m_Cases[i_PosY + y][i_PosX]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY + y][i_PosX]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY + y][i_PosX]->isVulnerable)
										{
											if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + y, i_PosX))
											{
												i_Board.m_Cases[i_PosY + y][i_PosX]->SetCaseLight(true, i_Board);
											}
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY + y][i_PosX]->SetVulnerability(true);
									}
								}
								else if (i_Board.m_Cases[i_PosY + y][i_PosX]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY + y][i_PosX]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY + y][i_PosX]->SetVulnerability(true);
									}
								}
							}
							else if (i_PosY == 0)
							{
								if (i_Board.m_Cases[i_PosY][i_PosX]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY][i_PosX]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY][i_PosX]->isVulnerable)
										{
											if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY, i_PosX))
											{
												i_Board.m_Cases[i_PosY][i_PosX]->SetCaseLight(true, i_Board);
											}
											i_Board.m_Cases[i_PosY][i_PosX]->SetCaseLight(true, i_Board);
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY][i_PosX]->SetVulnerability(true);
									}
								}
								else if (i_Board.m_Cases[i_PosY][i_PosX]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY][i_PosX]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY][i_PosX]->SetVulnerability(true);
									}
								}
							}
						}
						else if (y > 0)
						{
							if (i_PosY < 7)
							{
								if (i_Board.m_Cases[i_PosY + y][i_PosX]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY + y][i_PosX]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY + y][i_PosX]->isVulnerable)
										{
											if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + y, i_PosX))
											{
												i_Board.m_Cases[i_PosY + y][i_PosX]->SetCaseLight(true, i_Board);
											}
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY + y][i_PosX]->SetVulnerability(true);
									}
								}
								else if (i_Board.m_Cases[i_PosY + y][i_PosX]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY + y][i_PosX]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY + y][i_PosX]->SetVulnerability(true);
									}
								}
							}
						}
					}					
				}
				//Prevent look outside the Grid in positive X axis.
				else if (x > 0)
				{
					if (i_PosX < 7)
					{
						//Prevent look outside the Grid in Y axis.
						if (y <= 0)
						{
							if (i_PosY > 0)
							{
								if (i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY + y][i_PosX + x]->isVulnerable)
										{
											if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + y, i_PosX + x))
											{
												i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetCaseLight(true, i_Board);
											}
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetVulnerability(true);
									}
								}
								else if (i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetVulnerability(true);
									}
								}
							}
							else if (i_PosY == 0)
							{
								if (i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY][i_PosX + x]->isVulnerable)
										{
											if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY, i_PosX + x))
											{
												i_Board.m_Cases[i_PosY][i_PosX + x]->SetCaseLight(true, i_Board);
											}
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
									}
								}
								else if (i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY][i_PosX + x]->SetVulnerability(true);
									}
								}
							}
						}
						else if (y > 0)
						{
							if (i_PosY < 7)
							{
								if (i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece == nullptr
									|| i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece->IsBlack() != IsBlack())
								{
									if (!i_Vulnerable)
									{
										if (!i_Board.m_Cases[i_PosY + y][i_PosX + x]->isVulnerable)
										{
											if (!IsKingVulnerableAtPos(i_Board, i_PosY, i_PosX, i_PosY + y, i_PosX + x))
											{
												i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetCaseLight(true, i_Board);
											}
										}
									}
									else
									{
										i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetVulnerability(true);
									}
								}
								else if (i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece != nullptr
									&& i_Board.m_Cases[i_PosY + y][i_PosX + x]->m_Piece->IsBlack() == IsBlack())
								{
									if (i_Vulnerable)
									{
										i_Board.m_Cases[i_PosY + y][i_PosX + x]->SetVulnerability(true);
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

bool Roi::IsKingVulnerableAtPos(Board& i_Board, const int& i_PreviousPosY, const int& i_PreviousPosX, const int& i_PosY, const int& i_PosX)
{
	return BasePieces::IsKingVulnerableAtPos(i_Board, i_PreviousPosY, i_PreviousPosX, i_PosY, i_PosX);
}

/*
void Roi::Roque()
{
}

void Roi::Mouvement()
{
}

bool Roi::Illuminer()
{
	return true;
}

void Roi::Detruire()
{
}
*/