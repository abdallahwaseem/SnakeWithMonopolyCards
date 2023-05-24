#pragma once
#include"Card.h"

class FreezeCard_6 : public Card
{
	bool Even; // If true the players in even cells will be freezed
				// If false the players in odd cells will be freezed
	int NumberOfTurnsFreezed; // Number of turns the players will be freezed
public:
	FreezeCard_6(const CellPosition& pos); // A Constructor takes card position
	virtual void ReadCardParameters(Grid* pGrid); 
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual void SetFreezeBool(bool even);
	virtual void SetNumberofturns(int turn);
	virtual int GetNumberOfTurnsFreezed();
	virtual bool GetFreezeBool();
	virtual ~FreezeCard_6(); // A Virtual Destructor
	virtual void Save(ofstream& OutFile, int a);
	virtual void Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount);
};