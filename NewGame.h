#pragma once
#include"Action.h"
#include "ApplicationManager.h"
#include "Cell.h"
#include "Grid.h"
#include "Player.h"

// Base class for all possible actions (actions are icons of the toolbar)
class NewGame :public Action
{
protected:

public:

	NewGame(ApplicationManager* pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters(); // Reads parameters required for action to execute 
										 // (code depends on action type so virtual)

	virtual void Execute();  // Executes action (code depends on action type so virtual)

	virtual ~NewGame();  // Virtual Destructor
};

