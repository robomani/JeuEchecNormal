#include "BaseCase.h"
#include "BasePieces.h"


BaseCase::BaseCase(int i_PosX, int i_PosY, BasePieces* i_Piece = nullptr)
	: PosX (i_PosX)
	, PosY (i_PosY)
	, m_Piece (i_Piece)
{

}


BaseCase::~BaseCase()
{
}

bool BaseCase::Illuminer(bool i_Voulue)
{
	if (i_Voulue)
	{
		m_ImageCurrent = m_ImageIlluminer;
	}
	else
	{
		m_ImageCurrent = m_ImageBase;
	}
	return true;
}