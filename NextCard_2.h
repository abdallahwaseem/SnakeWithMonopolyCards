#pragma once
#include "Card.h"
#include "GameObject.h"

class NextCard_2 : public Card
{
	int choice;
public:
	NextCard_2(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void SetChoice(int inChoice);
	virtual int GetChoice();
	virtual ~NextCard_2();
	virtual void Save(ofstream& OutFile, int a);
	virtual void Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount);
};
