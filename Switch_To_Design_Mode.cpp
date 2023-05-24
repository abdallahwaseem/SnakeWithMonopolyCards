#include "Switch_To_Design_Mode.h"
#include"Grid.h"
#include "Player.h"
Switch_To_Design_Mode::Switch_To_Design_Mode(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

Switch_To_Design_Mode::~Switch_To_Design_Mode()
{

}

void Switch_To_Design_Mode::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	
}
void Switch_To_Design_Mode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Are you sure you want to end game ?(Yes/No)");
	string Ans = pIn->GetSrting(pOut);
	if (Ans == "Yes" || Ans == "yes")
	{
		pGrid->PrintErrorMessage("Player " + to_string(pGrid->WinnerPlayer()->GetPlayernum()) + " is the winner with wallet value " + to_string(pGrid->WinnerPlayer()->GetWallet()) + ", click to continue");
		pGrid->StartNewGame();
		pOut->CreateDesignModeToolBar();
	}
}