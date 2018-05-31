#include "Board.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Fou.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"



Board::Board()
{
}


Board::~Board()
{
}

void Board::initialisation()
{
	for (int i = 0; i < 2; i++)
	{
		for (int x = 0; x < 16; x++)
		{
			switch (x)
			{
			case 0:
				m_PiecesEnJeu[i][x] = new Tour(i,x,i*7);
				break;
			case 1:
				m_PiecesEnJeu[i][x] = new Cavalier(i, x, i * 7);
				break;
			case 2:
				m_PiecesEnJeu[i][x] = new Fou(i, x, i * 7);
				break;
			case 3:
				m_PiecesEnJeu[i][x] = new Dame(i, x, i * 7);
				break;
			case 4:
				m_PiecesEnJeu[i][x] = new Roi(i, x, i * 7);
				break;
			case 5:
				m_PiecesEnJeu[i][x] = new Fou(i, x, i * 7);
				break;
			case 6:
				m_PiecesEnJeu[i][x] = new Cavalier(i, x, i * 7);
				break;
			case 7:
				m_PiecesEnJeu[i][x] = new Tour(i, x, i * 7);
				break;
			default:
				m_PiecesEnJeu[i][x] = new Pion(i, x-8, i * 7);
				break;
			}

		}

	}
}
