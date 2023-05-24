#pragma once
#include"Action.h"
#include "ApplicationManager.h"
#include "Cell.h"
#include<fstream>

class OpenGridAction :public Action
{
protected:

	string lfilename;
	ifstream loadfile;
public:
	OpenGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~OpenGridAction();
};