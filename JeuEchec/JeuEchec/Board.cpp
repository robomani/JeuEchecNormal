#include "Board.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Fou.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
#include "BaseCase.h"
#include <vector>


Board::Board()
{
	initialisation();
}


Board::~Board()
{
}


void Board::initialisation()
{
	for (int i = 0; i < 8; i++)
	{
		m_Cases.push_back(std::vector<BaseCase*>());
		for (int x = 0; x < 16; x++)
		{
			if (i < 2)
			{
				switch (x)
				{
				case 0:
					m_Cases[i].push_back(new BaseCase(x, i * 7, new Tour(i, x, i * 7)));
					break;
				case 1:
					m_Cases[i].push_back(new BaseCase(x, i * 7, new Cavalier(i, x, i * 7)));
					break;
				case 2:
					m_Cases[i].push_back(new BaseCase(x, i * 7, new Fou(i, x, i * 7)));
					break;
				case 3:
					m_Cases[i].push_back(new BaseCase(x, i * 7, new Dame(i, x, i * 7)));
					break;
				case 4:
					m_Cases[i].push_back(new BaseCase(x, i * 7, new Roi(i, x, i * 7)));
					break;
				case 5:
					m_Cases[i].push_back(new BaseCase(x, i * 7, new Fou(i, x, i * 7)));
					break;
				case 6:
					m_Cases[i].push_back(new BaseCase(x, i * 7, new Cavalier(i, x, i * 7)));
					break;
				case 7:
					m_Cases[i].push_back(new BaseCase(x, i * 7, new Tour(i, x, i * 7)));
					break;
				default:
					m_Cases[i].push_back(new BaseCase(x - 8, (i * 5) + 1, new Pion(i, x - 8, (i * 5) + 1)));
					break;
				}
			}
			else
			{
				m_Cases[i].push_back(new BaseCase(x, i));
			}
			

		}

	}
}
