#include "CoinSet.h"

CoinSet::CoinSet(const CellPosition& CellPos, const int amount)
	: GameObject(CellPos)
{
	Amount = amount;
	save = 3;
}

void CoinSet::Draw(Output* pOut) const
{
	pOut->DrawCoinSet(position);
}

void CoinSet::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Print a message "You have reached a coint set. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a coint set. Click to continue ...");

	// 2- Apply the coin set's effect by adding the player's wallet by amount
	pPlayer->SetWallet((pPlayer->GetWallet()) + Amount);
}

int CoinSet::getamount()
{
	return Amount;
}

CoinSet::~CoinSet()
{
}

void CoinSet::Save(ofstream& OutFile, int a)
{

	if (a == save)
	{
		OutFile << position.GetCellNum() << " " << Amount <<" " <<endl;
	}
		return;
}


void CoinSet::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (a == save)
	{
		int start, a;
		Infile >> start >> a;
		CellPosition x(start);
		s.SetHCell(x.HCell());
		s.SetVCell(x.VCell());
		amount = a;
	}
}

