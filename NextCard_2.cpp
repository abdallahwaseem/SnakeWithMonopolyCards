#include "NextCard_2.h"
#include"CoinSet.h"
#include"Ladder.h"
#include"Card.h"
#include"Snake.h"
NextCard_2::NextCard_2(const CellPosition& pos) :Card(pos)
{
	cardNumber = 2;
}
void NextCard_2::ReadCardParameters(Grid* pGrid)
{
	Output* out = pGrid->GetOutput();
	Input* in = pGrid->GetInput();
	out->PrintMessage("Choose the required game object: 1=ladders, 2=snakes, 3=coin sets, 4=cards");
	choice = in->GetInteger(out);
}
void NextCard_2::Apply(Grid* pGrid, Player* pPlayer)
{
	CellPosition playerPos = pPlayer->GetCell()->GetCellPosition();
	int v;
	int h;
	//pGrid->CellList[v][h]

	if (choice == 1)
	{
		if (pGrid->GetNextLadder(playerPos) != NULL)
		{
			Ladder* pLadder = pGrid->GetNextLadder(playerPos);
			pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());
			pLadder->Apply(pGrid, pPlayer);
			return;
		}
		if (pGrid->GetNextLadder(CellPosition::GetCellPositionFromNum(1)) != NULL)
		{
			Ladder* pLadder = pGrid->GetNextLadder(CellPosition::GetCellPositionFromNum(1));
			pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());
			pLadder->Apply(pGrid, pPlayer);
			return;
		}
	}
	else if (choice == 4)
	{
		if (pGrid->GetNextCard(playerPos) != NULL)
		{
			Card* pCard = pGrid->GetNextCard(playerPos);
			pGrid->UpdatePlayerCell(pPlayer, pCard->GetPosition());
			pCard->Apply(pGrid, pPlayer);
			return;
		}
		if (pGrid->GetNextCard(CellPosition::GetCellPositionFromNum(1)) != NULL)
		{
			Card* pCard = pGrid->GetNextCard(CellPosition::GetCellPositionFromNum(1));
			if (CellPosition::GetCellNumFromPosition(pCard->GetPosition()) == position.GetCellNumFromPosition(position))
				return;
			pGrid->UpdatePlayerCell(pPlayer, pCard->GetPosition());
			pCard->Apply(pGrid, pPlayer);
			return;
		}
	}
	else if (choice == 2)
	{
		if (pGrid->GetNextSnake(playerPos) != NULL)
		{
			Snake* pSnake = pGrid->GetNextSnake(playerPos);
			pGrid->UpdatePlayerCell(pPlayer, pSnake->GetPosition());
			pSnake->Apply(pGrid, pPlayer);
			return;
		}
		if (pGrid->GetNextSnake(CellPosition::GetCellPositionFromNum(1)) != NULL)
		{
			Snake* pSnake = pGrid->GetNextSnake(CellPosition::GetCellPositionFromNum(1));
			pGrid->UpdatePlayerCell(pPlayer, pSnake->GetPosition());
			pSnake->Apply(pGrid, pPlayer);
			return;
		}
	}
	else if (choice == 3)
	{
		if (pGrid->GetNextCoinSet(playerPos) != NULL)
		{
			CoinSet* pCoinSet = pGrid->GetNextCoinSet(playerPos);
			pGrid->UpdatePlayerCell(pPlayer, pCoinSet->GetPosition());
			pCoinSet->Apply(pGrid, pPlayer);
			return;
		}
		if (pGrid->GetNextCoinSet(CellPosition::GetCellPositionFromNum(1)) != NULL)
		{
			CoinSet* pCoinSet = pGrid->GetNextCoinSet(CellPosition::GetCellPositionFromNum(1));
			pGrid->UpdatePlayerCell(pPlayer, pCoinSet->GetPosition());
			pCoinSet->Apply(pGrid, pPlayer);
			return;
		}
	}


}
void NextCard_2::SetChoice(int inChoice)
{
	choice = inChoice;
}
int NextCard_2::GetChoice()
{
	return choice;
}
NextCard_2::~NextCard_2(void) {}
void NextCard_2::Save(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		OutFile << cardNumber << "  " << position.GetCellNum() << " " << choice<<" "<<endl;
	}
	else
		return;

	return;
}

void NextCard_2::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (a == save)
	{
		int c;
		Infile >>c;
		choice = c;
	}
}
