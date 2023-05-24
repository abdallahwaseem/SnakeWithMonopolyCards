#include "FireCard_5.h"
#include"CoinSet.h"
#include"Ladder.h"
#include"Card.h"
#include"Snake.h"

FireCard_5::FireCard_5(const CellPosition& pos) :Card(pos) 
{
	cardNumber = 5;

}

void FireCard_5::Apply(Grid* pGrid, Player* pPlayer)
{
	int v = position.VCell();
	int h = position.HCell();
	CellPosition p(1);
	pGrid->fire(pPlayer, p, v, h);
}

FireCard_5:: ~FireCard_5() {}
