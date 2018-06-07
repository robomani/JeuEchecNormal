#include "Cavalier.h"



Cavalier::Cavalier(bool i_Black, int i_PosX, int i_PosY)
	:BasePieces()
{
	if (i_Black)
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/CavalierNoir.bmp");
	}
	else
	{
		m_ImageBase = SDL_LoadBMP("ArtWork/CavalierBlanc.bmp");
	}

}


Cavalier::~Cavalier()
{
}

void Cavalier::Mouvement()
{
}

bool Cavalier::VerifMouvLegal()
{
	return true;
}

bool Cavalier::Illuminer()
{
	return true;
}

void Cavalier::Detruire()
{
}
