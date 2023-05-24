#pragma once
#include "Action.h"

class AddSnakeAction :public Action
{
	CellPosition startPos;
	CellPosition endPos;
	bool CheckDrawing;  // Validation check for drawing
public:

	AddSnakeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Ladder Object 
							// then Sets this Ladder object to the GameObject Pointer of its Cell


	virtual ~AddSnakeAction(); // Virtual Destructor

};
