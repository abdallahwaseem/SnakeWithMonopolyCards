#pragma once
#include"Action.h"
#include"Grid.h"
#include <fstream>

class Switch_To_Play_Mode:public Action
{

public:
	Switch_To_Play_Mode(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	virtual void Execute(); 


	virtual ~Switch_To_Play_Mode();
};

