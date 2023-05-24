#pragma once
#include "Action.h"
#include"CopyCardAction.h"
#include"CutCardORCoinSetAction.h"

class PasteCardORCoinAction :public Action
{
	CellPosition finalpos;
	bool checkDrawing;
public:
	PasteCardORCoinAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~PasteCardORCoinAction();
};
