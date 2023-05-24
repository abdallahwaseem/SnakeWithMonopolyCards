#include "PreventCard_4.h"
#include"Output.h"
#include"CellPosition.h"
#include"Player.h"
#include"Grid.h"

PreventCard_4::PreventCard_4(const CellPosition pos) :Card(pos)
{
	cardNumber = 4;
}

void PreventCard_4::Apply(Grid* grid, Player* pPlayer)
{
	Card::Apply(grid, pPlayer);
	Output* pOut = grid->GetOutput();
	pOut->PrintMessage("Click on the player you want to skip his/her next turn");
	CellPosition  c = grid->GetInput()->GetCellClicked();
	int x = c.HCell();
	int	y = c.VCell();
	if (pPlayer->GetCell()->GetCellPosition().VCell() == y && pPlayer->GetCell()->GetCellPosition().HCell() == x)
	{
		pOut->PrintMessage("You can't choose yourself");
	}
	else
	{
		Player* n = grid->GetPlayerFromPos(c);
		if (n != NULL)
		{
			n->SetPlayable(false);
			grid->PrintErrorMessage("Player " + to_string(n->GetPlayernum()) + " won't move the next turn.");
		}
		while (n == NULL)
		{
			grid->PrintErrorMessage("You cannot select a cell without players or with more than one player. Click to try again.");
			CellPosition  c = grid->GetInput()->GetCellClicked();
			int x = c.HCell();
			int	y = c.VCell();
			if (pPlayer->GetCell()->GetCellPosition().VCell() == y && pPlayer->GetCell()->GetCellPosition().HCell() == x)
			{
				pOut->PrintMessage("You can't choose yourself");
			}
			else
			{
				n = grid->GetPlayerFromPos(c);
				if (n != NULL)
				{
					n->SetPlayable(false);
					grid->PrintErrorMessage("Player " + to_string(n->GetPlayernum()) + " won't move the next turn.");
				}
			}
		}
	}

}

PreventCard_4::~PreventCard_4()
{
}