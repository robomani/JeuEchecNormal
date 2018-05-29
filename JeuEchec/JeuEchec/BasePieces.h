#pragma once
class BasePieces
{
public:
	BasePieces();
	~BasePieces();

	virtual void VerifMouvLegal();
	virtual void Mouvement();
	virtual void Illuminer();
	virtual void Detruire();

protected:
	int m_PosX;
	int m_PosY;
};

