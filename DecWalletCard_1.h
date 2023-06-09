#pragma once

#include "Card.h"

// [ DecWalletCard_1 ] Summary:
// Its Apply() Function: Decrements the value of the passing player�s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class DecWalletCard_1 :	public Card
{
	// DecWalletCard_1 Parameters:
	int walletAmount; // the wallet value to decrease from the player

public:
	DecWalletCard_1(const CellPosition & pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid * pGrid); // Reads the parameters of DecWalletCard_1 which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of DecWalletCard_1 on the passed Player
	                                                  // by decrementing the player's wallet by the walletAmount data member
	virtual int GetWalletAmount();
	virtual void SetWalletAmount(int a);
	virtual ~DecWalletCard_1(); // A Virtual Destructor
	virtual void Save(ofstream& OutFile, int a );
	virtual void Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount);
};


