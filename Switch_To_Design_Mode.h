#pragma once
#include "Action.h"
class Switch_To_Design_Mode: public Action
{

public:
	Switch_To_Design_Mode(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute();


	virtual ~Switch_To_Design_Mode();
};

