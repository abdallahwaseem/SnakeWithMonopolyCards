#pragma once

#include "GameObject.h"
#include "Player.h"

class CoinSet : public GameObject // inherited from GameObject
{
	int Amount; // Amount of money the player takes when he/she stops by a coin set

public:

	CoinSet(const CellPosition& CellPos, const int amount); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a coint set at cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the coin set by adding amount to the player's wallet
	
	int getamount();	// A getter for amount
	virtual void Save(ofstream& OutFile,int a) ;	
	virtual void Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount);

	virtual ~CoinSet(); // Virtual destructor
};