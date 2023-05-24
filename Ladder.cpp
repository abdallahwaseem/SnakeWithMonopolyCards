#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.HCell() == startCellPos.HCell() && endCellPos.VCell() < startCellPos.VCell())
		this->endCellPos = endCellPos;
	///TODO: Do the needed validation
	save = 2;
}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	pGrid->PrintErrorMessage("You have reached a ladder. Click to continue ...");

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
void Ladder::Save(ofstream& OutFile, int a)
{
	
	if (a == save)
	{
		OutFile << position.GetCellNum() <<" "<<endCellPos.GetCellNum()<<endl;
	}
	else
		return;
}

void Ladder::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (a == save)
	{
		int start, end;
		Infile >> start>> end;
		CellPosition x(start);
		CellPosition y(end);
		s.SetHCell(x.HCell());
		s.SetVCell(x.VCell());
		e.SetHCell(y.HCell());
		e.SetVCell(y.VCell());
	}
}