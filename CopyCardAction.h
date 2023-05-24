#pragma once
#include "Action.h"

class CopyCardAction :public Action
{
protected:
	Card* cardptr;
	CoinSet* coinptr;

public:
	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads AddLadderAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new Ladder Object 
							// then Sets this Ladder object to the GameObject Pointer of its Cell


	virtual ~CopyCardAction(); // Virtual Destructor
};
