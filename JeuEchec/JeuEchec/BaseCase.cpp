#include "BaseCase.h"



BaseCase::BaseCase()
{

}


BaseCase::~BaseCase()
{
}

void BaseCase::Illuminer(bool i_Voulue)
{
	if (i_Voulue)
	{
		m_ImageCurrent = m_ImageIlluminer;
	}
	else
	{
		m_ImageCurrent = m_ImageBase;
	}
}