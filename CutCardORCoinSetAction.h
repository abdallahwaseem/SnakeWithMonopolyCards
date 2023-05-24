#pragma once

#include "Action.h"
#include"CopyCardAction.h"

class CutCardORCoinSetAction :public CopyCardAction
{

public:
	CutCardORCoinSetAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


	virtual ~CutCardORCoinSetAction();
};

