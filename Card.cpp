#include "Card.h"


Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
	save = 1;
}

void Card::SetCardNumber(int cnum)
{
	cardNumber = cnum; // needs validation
}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"
	pOut->DrawCell(position, cardNumber);


}

void Card::ReadCardParameters(Grid* pGrid)
{
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{

	// The following line is to print the following message if a player reaches a card of any type

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}

void Card::SetWalletAmount(int amount){}
void Card::SetChoice(int inChoice){}
void Card::SetBenefitNumber(int number){}
void Card::SetFreezeBool(bool even){}
void Card::SetNumberofturns(int turn){}

int Card::GetWalletAmount()
{
	return 0;
}
 int Card::GetChoice()
 {
	 return 0;
 }
 int Card::GetBenefitNumber()
 {
	 return 0;
 }
 bool Card::GetFreezeBool() { return 0; }
 int Card::GetNumberOfTurnsFreezed() { return 0; }
Card::~Card()
{
}

void Card::Save(ofstream& OutFile, int a)
{
	if (a == save)
	{
		OutFile << cardNumber << "  " << position.GetCellNum() << " "<<endl;
	}
	return;
}

void Card::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount){}
