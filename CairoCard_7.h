#pragma once
#include "Card.h"

class CairoCard_7 : public Card
{
	int Price;			// Price of the city
	int Fees;			// Fees to be paid
	Player* Owner;		// Owner of the city
	Player* SubOwner;	// Subowner of the city if it mortgaged
	static int count;
	static int open;
public:
	CairoCard_7(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CairoCard_7 

	virtual void Apply(Grid* pGrid, Player* pPlayer);	// Apply the function of monopoly card

	void SetOwner(Player* pPlayer);				// A setter for Owner
	virtual Player* GetOwner();					// A getter for Owner


	void SetSubOwner(Player* pPlayer);			// A setter for SubOwner
	virtual Player* GetSubOwner();				// A getter for SubOwner

	virtual int GetPrice();						// A getter for Price

	virtual ~CairoCard_7(); // A Virtual Destructor

	virtual void Save(ofstream& OutFile, int a);
	virtual void Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount);
};