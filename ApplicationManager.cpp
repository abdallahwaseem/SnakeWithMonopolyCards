#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddCardAction.h"
#include "RollDiceAction.h"
#include"AcceptMortgage.h"
#include"ReturnMortgage.h"
#include"SaveGridAction.h"
#include"AddSnakeAction.h"
#include"AddLadderAction.h"
#include"AddCoinSetAction.h"
#include"AddCardAction.h"
#include"NewGame.h"
#include"CopyCardAction.h"
#include"CutCardORCoinSetAction.h"
#include"PasteCardORCoinAction.h"
#include"OpenGridAction.h"
#include "Switch_To_Play_Mode.h"
#include "Switch_To_Design_Mode.h"
#include"DeleteGameObject.h"
#include"SellCity.h"
#include"InputDiceValue.h"
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;
	case ADD_COIN_SET:
		pAct = new AddCoinSetAction(this);
		break;
	case DELETE_GAME_OBJ:
		pAct = new DeleteGameObject(this);
		break;
	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;
	case COPY_CARDorCOIN:
		pAct = new CopyCardAction(this);
		break;
	case CUT_CARDorCOIN:
		pAct = new CutCardORCoinSetAction(this);
		break;
	case  PASTE:
		pAct = new PasteCardORCoinAction(this);
		break;
	case  SAVE_GRID:
		pAct = new SaveGridAction(this);
		break;
	case OPEN_GRID:
		pAct = new OpenGridAction(this);
		break;
	case EXIT:
		break;
	case TO_PLAY_MODE:
		pAct = new Switch_To_Play_Mode(this);
		 ///TODO: temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;
	case INPUT_DICE_VALUE:
		pAct = new InputDiceValue(this);
		break;
	case OFFER_MORTGAGE:
		pAct = new OfferMortgage(this);
		break;
	case ACCEPT_MORTGAGE:
		pAct = new AcceptMortgage(this);
		break;
	case RETURN_MORTGAGE:
		pAct = new ReturnMortgage(this);
		break;
	case SELL_CITY:
		pAct = new SellCity(this);
		break;
	case NEW_GAME:
		pAct = new NewGame(this);
		break;
	case TO_DESIGN_MODE:
		pAct = new Switch_To_Design_Mode(this);
		//TODO: temporary till you made its action class (CHANGE THIS LATTER)
		break;
	
	
	
		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
