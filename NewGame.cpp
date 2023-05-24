#include "NewGame.h"

NewGame::NewGame(ApplicationManager* pApp) : Action(pApp)
{
	// The constructor initializes the ApplicationManager pointer data member
}

void NewGame::ReadActionParameters()
{
	// Get a Pointer to the Grid and Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();

	// Ask the user if he wants to start a new game
	pGrid->PrintErrorMessage("Start a new game. Click to continue.");

	// Clear status bar
	pOut->ClearStatusBar();
}


void NewGame::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Get a Pointer to the Grid interface
	Grid* pGrid = pManager->GetGrid();
	pGrid->StartNewGame();


}

NewGame::~NewGame()
{
}