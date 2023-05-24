#include<fstream>
#include"SaveGridAction.h"
#include"Grid.h"

SaveGridAction::SaveGridAction(ApplicationManager* pApp) :Action(pApp) {}


void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* in = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	out->PrintMessage("Enter the name of the file to be saved to.");
	filename = in->GetSrting(out);
	savefile.open(filename + ".txt", ios::out);
}


void SaveGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* out = pGrid->GetOutput();
	int l = pGrid->numladders();
	int s = pGrid->numsnakes();
	int c = pGrid->numcards();
	int cs = pGrid->numcoinsets();
	savefile <<l <<endl;
	pGrid->SaveAll(savefile, 2);
	savefile << s << endl;
	pGrid->SaveAll(savefile, 4);
	savefile << cs << endl;
	pGrid->SaveAll(savefile, 3);
	savefile << c<< endl;
	pGrid->SaveAll(savefile, 1);
	savefile.close();
	out->PrintMessage("File has been saved.");
}

SaveGridAction::~SaveGridAction()
{}