#include "BasePieces.h"




BasePieces::BasePieces()
{
}


BasePieces::~BasePieces()
{
}

bool BasePieces::VerifMouvLegal()
{
	//if (Floor(MousePosition.x/LenghtOfTiles) >= 0 && Floor(MousePosition.x/LenghtOfTiles) <= 7 && Floor(MousePosition.y/LenghtOfTiles) >= 0 && Floor(MousePosition.y/LenghtOfTiles) <= 7)
	{
		return true;
	}
}

void BasePieces::Mouvement()
{
	if (VerifMouvLegal())
	{
		//m_PosX = Floor(MousePosition.x / LenghtOfTiles);
		//m_PosY = loor(MousePosition.y / LenghtOfTiles);
	}
}

bool BasePieces::Illuminer()
{
	return true;
}

void BasePieces::Detruire()
{
	m_PosX = -1;
	m_PosY = -1;
}

SDL_Surface* BasePieces::loadSurface(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, m_ImageBase->format, NULL);
		if (optimizedSurface == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return optimizedSurface;
}
