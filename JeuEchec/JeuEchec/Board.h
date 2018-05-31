#pragma once
#include "BasePieces.h"

class Board
{
public:
	Board();
	~Board();

	int m_Hauteur;
	int m_Largeur;


	BasePieces* m_PiecesEnJeu[2][16];

	void initialisation();
};

