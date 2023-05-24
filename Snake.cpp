#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.HCell() == startCellPos.HCell() && endCellPos.VCell() > startCellPos.VCell())
		this->endCellPos = endCellPos;
	save = 4;
	///TODO: Do the needed validation
}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	
	pGrid->PrintErrorMessage("You have reached a snake. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
void Snake::Save(ofstream& OutFile, int a)
{
	if (a == save)
	{
		OutFile << position.GetCellNum() <<" "<<endCellPos.GetCellNum()<<endl;
	}
	else
		return;
}

void Snake::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (a == save)
	{
		int start, end;
		Infile >> start >> end;
		CellPosition x(start);
		CellPosition y(end);
		s.SetHCell(x.HCell());
		s.SetVCell(x.VCell());
		e.SetHCell(y.HCell());
		e.SetVCell(y.VCell());
	}
}