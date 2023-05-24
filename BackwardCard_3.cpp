#include "BackwardCard_3.h"
#include"Grid.h"

BackwardCard_3::BackwardCard_3(const CellPosition& pos) : Card(pos)// set the cell position of the card
{
	cardNumber = 3; 
}
BackwardCard_3::~BackwardCard_3(){}

void BackwardCard_3::Apply(Grid* pGrid, Player* pPlayer)
{
	pGrid->PlayerListLoop(pGrid, pPlayer);
}