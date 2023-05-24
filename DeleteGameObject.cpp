


#include "DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include"Grid.h"

DeleteGameObject::DeleteGameObject(ApplicationManager* pApp) :Action(pApp) 
{ checkDelete = true; }

void DeleteGameObject::ReadActionParameters()
{
    Grid* pGrid = pManager->GetGrid();
    Output* out = pGrid->GetOutput();
    Input* in = pGrid->GetInput();
    out->PrintMessage("Click on the cell containing the object you wish to delete.");
    CellPosition a = in->GetCellClicked();
    GameObject* b = NULL;
    b = pGrid->GetGameObject(a);
    if (b == NULL)
    {
        pGrid->PrintErrorMessage("This cell is already empty!.");
        checkDelete = false;
        return;
    }
    dpos = a;
}
void DeleteGameObject::Execute()
{
    ReadActionParameters();
    if (checkDelete)
    {
        Grid* pGrid = pManager->GetGrid();
        Output* out = pGrid->GetOutput();
        Input* in = pGrid->GetInput();
        pGrid->RemoveObjectFromCell(dpos);
        pGrid->PrintErrorMessage("Successfully deleted. Click to continue...");
    }
}
DeleteGameObject::~DeleteGameObject() {}