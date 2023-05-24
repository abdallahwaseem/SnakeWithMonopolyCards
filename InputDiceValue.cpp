#include "InputDiceValue.h"

#include "Grid.h"
#include "Player.h"

InputDiceValue::InputDiceValue(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceValue::ReadActionParameters()
{
	// no parameters to read from user
}

void InputDiceValue::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("enter dice value ");
	int diceNumber = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
	while (diceNumber < 1 || diceNumber > 6)
	{
		pOut->PrintMessage("Re-enter dice value. Accepted value is between 1 and 6");
		diceNumber = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
	}
	if (pGrid->GetEndGame())
	{
		pOut->PrintMessage("to restart enter 1, to switch to design mode enter 2");
		int restartCondtion = pIn->GetInteger(pOut);
		if (restartCondtion == 1)
			pManager->ExecuteAction(NEW_GAME);
		else if (restartCondtion == 2)
			pManager->ExecuteAction(TO_DESIGN_MODE);
	}
	else
	{
		
		Player* p = pGrid->GetCurrentPlayer();
		p->Move(pGrid, diceNumber);
		pGrid->AdvanceCurrentPlayer();
	}
}

InputDiceValue::~InputDiceValue()
{
}