#include "Switch_To_Play_Mode.h"
#include"Grid.h"
#include "SaveGridAction.h"
#include "NewGame.h"
#include <fstream>

Switch_To_Play_Mode::Switch_To_Play_Mode(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

Switch_To_Play_Mode::~Switch_To_Play_Mode()
{

}

void Switch_To_Play_Mode::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Do you want to save Grid first?(Yes/No) ");
	string k= pIn->GetSrting(pOut);

	if (k == "Yes" || k == "yes")
	{
		pManager->ExecuteAction(SAVE_GRID);
	}
}


// Execute the action
void Switch_To_Play_Mode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ReadActionParameters();
	pOut->CreatePlayModeToolBar();
	pManager->ExecuteAction(NEW_GAME);
}