#include "FreezeCard_6.h"
FreezeCard_6::FreezeCard_6(const CellPosition& pos) : Card(pos)
{
	cardNumber = 6;
}
void FreezeCard_6::ReadCardParameters(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Choose which numbers do you want to freeze. even or odd cells");
	string freezedCells = pIn->GetSrting(pOut);
	while (freezedCells != "even" && freezedCells != "odd")
	{
		pOut->PrintMessage("Please enter even or odd only.");
		freezedCells = pIn->GetSrting(pOut);
	}
	if (freezedCells == "even")
		Even = true;
	else if (freezedCells == "odd")
		Even = false;
	pOut->PrintMessage("Please enter number of turns to be freezed.");
	NumberOfTurnsFreezed = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void FreezeCard_6::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	if (Even)
		pGrid->PrintErrorMessage("Players in the even cells will be freezed for " + to_string(NumberOfTurnsFreezed) + " turns. Click to continue...");
	else
		pGrid->PrintErrorMessage("Players in the odd cells will be freezed for " + to_string(NumberOfTurnsFreezed) + " turns. Click to continue...");
	pGrid->PLayerListFreeze(pGrid, pPlayer, NumberOfTurnsFreezed, Even);
}

int FreezeCard_6::GetNumberOfTurnsFreezed()
{
	return NumberOfTurnsFreezed;
}

void FreezeCard_6::SetFreezeBool(bool even)
{
	Even = even;
}
void FreezeCard_6::SetNumberofturns(int turn)
{
	NumberOfTurnsFreezed = turn;
 }

bool FreezeCard_6::GetFreezeBool()
{
	return Even;
}

FreezeCard_6::~FreezeCard_6()
{
}

void FreezeCard_6::Save(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		OutFile << cardNumber << "  " << position.GetCellNum() << " " << Even << " " << NumberOfTurnsFreezed << " " << endl;
	}
	else
		return;

	return;
}

void FreezeCard_6::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{

	if (a == save)
	{
		int b, c;
		Infile >> b >> c;
		Even = b;
		NumberOfTurnsFreezed = c;
	}
}