#include "CutCardORCoinSetAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CoinSet.h"

CutCardORCoinSetAction::CutCardORCoinSetAction(ApplicationManager* pApp) :CopyCardAction(pApp) {}

void CutCardORCoinSetAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* in = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	Card* temp1 = NULL;
	CoinSet* temp2 = NULL;
	pGrid->SetClipboard(temp1);
	pGrid->SetClipboard(temp2);
	out->PrintMessage("if you want to cut a card enter 1 or if you want to copy a coin set enter 2 ");
	int f = in->GetInteger(out);
	if (f == 1)
	{
		out->PrintMessage("Click on a card:");
		CellPosition a = in->GetCellClicked();
		cardptr = dynamic_cast<Card*>(pGrid->GetGameObject(a));
		if (cardptr == NULL)
		{
			pGrid->PrintErrorMessage("No card exists in this cell:");
			return;
		}
		else
		{
			out->PrintMessage("Card cut!");
		}
		pGrid->SetClipboard(cardptr);
		pGrid->setclipboardcheck(2);
	}
	else if (f == 2)
	{
		out->PrintMessage("click on a coinset");
		CellPosition a = in->GetCellClicked();
		coinptr = dynamic_cast<CoinSet*>(pGrid->GetGameObject(a));
		if (coinptr == NULL)
		{
			pGrid->PrintErrorMessage("No coinset exists in this cell:");
			return;
		}
		else
		{
			out->PrintMessage("Coinset cut!");
		}
		pGrid->SetClipboard(coinptr);
		pGrid->setclipboardcheck(2);
	}
}

void CutCardORCoinSetAction::Execute()
{
	ReadActionParameters();
}


CutCardORCoinSetAction::~CutCardORCoinSetAction() {}