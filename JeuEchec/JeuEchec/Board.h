#pragma once
#include "BasePieces.h"
#include "Board.h"
#include "Cavalier.h"
#include "Dame.h"
#include "Fou.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
#include "BaseCase.h"
#include <vector>

class Board
{
public:
	Board();
	~Board();

	int m_Hauteur;
	int m_Largeur;

	std::vector<std::vector<BaseCase*>> m_Cases;
	BasePieces* m_PiecesEnJeu[2][16];

	void initialisation();
};

