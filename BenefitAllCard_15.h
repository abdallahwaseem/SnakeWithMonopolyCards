#pragma once

#include "Card.h"

// [ BenefitAllCard_15 ] Summary:


class BenefitAllCard_15 : public Card
{
	// BenefitAllCard_15 Parameters:
	int benefitNumber; // the number of turn the benefit of owned cities will be switched

public:
	BenefitAllCard_15(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of BenefitAllCard_15 which is:
													// Number of turns the player will take the benefit of all owned cities

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of BenefitAllCard_15 on the passed Player

	virtual void SetBenefitNumber(int number);
	virtual int GetBenefitNumber();

	
	virtual ~BenefitAllCard_15(); // A Virtual Destructor
	virtual void Save(ofstream& OutFile, int a);
	virtual void Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount);
};


