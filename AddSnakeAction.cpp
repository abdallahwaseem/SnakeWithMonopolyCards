#include"AddSnakeAction.h"
#include "Input.h"
#include"Output.h"
#include"Snake.h"
#include "Ladder.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) :Action(pApp) 
{
	CheckDrawing = true;
}

void AddSnakeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	if (!startPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid cell position. Click to continue...");
		CheckDrawing = false;
		return;
	}

	if (startPos.VCell() == 8)
	{
		pGrid->PrintErrorMessage("Start cell cannot be placed in the first row. Click to continue...");
		CheckDrawing = false;
		return;
	}

	if (startPos.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("A snake can't be added to the start or end cells, Click to continue...");
		CheckDrawing = false;
		return;
	}

	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (!endPos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid cell position. Click to continue...");
		CheckDrawing = false;
		return;
	}

	if (startPos.GetCellNum() == endPos.GetCellNum())
	{
		pGrid->PrintErrorMessage("The start and end cells cannot be placed in the same cell");
		CheckDrawing = false;
		return;
	}

	if (endPos.GetCellNum() == 1 || endPos.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("A ladder can't be added to the start or end cells, Click to continue...");
		CheckDrawing = false;
		return;
	}

	if (startPos.HCell() != endPos.HCell()) //Check if vertical or start is after end
	{
		pGrid->PrintErrorMessage("The start and end cell should be in the same column. Click to continue...");
		CheckDrawing = false;
		return;
	}
	if (startPos.VCell() > endPos.VCell())
	{
		pGrid->PrintErrorMessage("The start cell should be after the end cell in the grid. Click to continue...");
		CheckDrawing = false;
		return;
	}

	CellPosition BottomCell(8, startPos.HCell());
	for (int i = BottomCell.GetCellNum(); i < startPos.GetCellNum(); i += 11)//overlap
	{
		CellPosition checkCell(i);
		Ladder* checkLadder = pGrid->GetNextLadder(checkCell);

		if (checkLadder)
		{
			int endV = checkLadder->GetEndPosition().VCell();
			if (checkLadder->GetPosition().HCell() == checkCell.HCell() && startPos.VCell() == endV)
			{
				pGrid->PrintErrorMessage("The start cell of a snake cannot be the end cell of another ladder. Click to continue");
				CheckDrawing = false;
				return;
			}
		}
	}

	for (int i = startPos.GetCellNum(); i >= endPos.GetCellNum(); i -= 11)//overlap
	{
		CellPosition checkCell(i);
		Snake* checkSnake = pGrid->GetNextSnake(checkCell);
		if (checkSnake)
		{
			int startV = checkSnake->GetPosition().VCell();
			if (checkSnake->GetPosition().HCell() == checkCell.HCell() && startV > startPos.VCell() && startV <= endPos.VCell())
			{
				if (startV == endPos.VCell())
				{
					pGrid->PrintErrorMessage("The end cell of a snake cannot be the start cell of another snake. Click to continue");
					CheckDrawing = false;
					return;
				}
				else
				{
					pGrid->PrintErrorMessage("Two snakes cannot overlap. Click to continue...");
					CheckDrawing = false;
					return;
				}
			}
		}
	}
	
	CellPosition TopCell(0, startPos.HCell());
	for (int i = startPos.GetCellNum(); i < TopCell.GetCellNum(); i += 11)//overlap
	{
		CellPosition checkCell(i);
		Snake* checkSnake = pGrid->GetNextSnake(checkCell);
		if (checkSnake)
		{
			int startV = checkSnake->GetPosition().VCell();
			int endV = checkSnake->GetEndPosition().VCell();
			if (checkSnake->GetPosition().HCell() == checkCell.HCell() && startPos.VCell() > startV && startPos.VCell() <= endV)
			{
				if (startPos.VCell() == endV)
				{
					pGrid->PrintErrorMessage("The end cell of a snake cannot be the start cell of another snake. Click to continue");
					CheckDrawing = false;
					return;
				}
				else
				{
					pGrid->PrintErrorMessage("Two snake cannot overlap. Click to continue...");
					CheckDrawing = false;
					return;
				}
			}
		}
	}
	
	//Start cell can't be the end of another ladder


	pOut->ClearStatusBar();
}



void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	if (CheckDrawing == true)
	{
		// Create a Ladder object with the parameters read from the user
		Snake* pSnake = new Snake(startPos, endPos);

		Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

		// Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pSnake);

		// if the GameObject cannot be added
		if (!added)
		{
			// Print an appropriate message
			pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		}
	}
}
AddSnakeAction::~AddSnakeAction() {}