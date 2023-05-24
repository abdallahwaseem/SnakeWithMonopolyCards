#pragma once
#include"Action.h"
#include "ApplicationManager.h"
#include "Cell.h"
#include<fstream>

class SaveGridAction:public Action
{
protected:

	string filename;
	ofstream savefile;
public:
	SaveGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() ; 
	virtual void Execute() ; 
	virtual ~SaveGridAction();
};