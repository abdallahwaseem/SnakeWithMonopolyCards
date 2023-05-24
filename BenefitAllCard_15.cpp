#include "BenefitAllCard_15.h"

BenefitAllCard_15::BenefitAllCard_15(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 15; // set the inherited cardNumber data member with the card number (15 here)
	benefitNumber = 0; // Number of turns the benefits will be turned

}

void BenefitAllCard_15::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("BenefitAllCard_15: Enter Number Of Turns the player can take benefit ");
	benefitNumber = pIn->GetInteger(pOut);
	while (benefitNumber < 1)
	{
		pOut->PrintMessage("Invalid input\nEnter how many turns you want to collect others fees");
		benefitNumber = pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();
}

void BenefitAllCard_15::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("The benefits of all bought are going to be switch for you for " + to_string(benefitNumber) + " turns");
	pPlayer->SetBenefitSwitch(true);
	pPlayer->SetTurnsBenefit(benefitNumber);
}

void BenefitAllCard_15::SetBenefitNumber(int number)
{
	benefitNumber = number;
}

int BenefitAllCard_15::GetBenefitNumber()
{
	return benefitNumber;
}



void BenefitAllCard_15::Save(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		OutFile << cardNumber << "  " << position.GetCellNum() << " " << benefitNumber << " " << endl;
	}
	else
		return;

	return;
}

void BenefitAllCard_15::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{

	if (a == save)
	{
		int b;
		Infile >> b;
		benefitNumber = b;
	}
}



BenefitAllCard_15::~BenefitAllCard_15() {}

