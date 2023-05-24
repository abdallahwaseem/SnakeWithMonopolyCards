#include "AddCoinSetAction.h"

#include "Input.h"
#include "Output.h"
#include "CoinSet.h"


AddCoinSetAction::AddCoinSetAction(ApplicationManager* pApp) :Action(pApp) { checkDrawing = true; }
void  AddCoinSetAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* in = pGrid->GetInput();
	Output* out = pGrid->GetOutput();

	out->PrintMessage("New coin set: Please enter the amount:");
	amount = in->GetInteger(out);

	while (amount <= 0)
	{
		out->PrintMessage("Invalid amount. The valid amount is greater than 0");
		amount = in->GetInteger(out);
	}

	out->PrintMessage("New coin set:Click on the cell:");
	pos = in->GetCellClicked();
	
	if (!pos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid cell position. Click to continue...");
		checkDrawing = false;
		return;
	}

	if (pos.GetCellNum() == 1 || pos.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("A coinset can't be added to the start or end cells, Click to continue...");
		checkDrawing = false;
		return;
	}
	
	out->ClearStatusBar();
}
void AddCoinSetAction::Execute()
{
	ReadActionParameters();
	if (checkDrawing == true)
	{
		CoinSet* C = new CoinSet(pos, amount);
		Grid* pGrid = pManager->GetGrid();

		bool t = pGrid->AddObjectToCell(C);
		if (!t)
		{
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
	}
}
AddCoinSetAction::~AddCoinSetAction() {}