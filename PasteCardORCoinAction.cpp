#include"PasteCardORCoinAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
#include "CoinSet.h"
#include "DecWalletCard_1.h"
#include "NextCard_2.h"
#include "BackwardCard_3.h"
#include "PreventCard_4.h"
#include "FireCard_5.h"
#include "FreezeCard_6.h"
#include "CairoCard_7.h"
#include "AlexCard_8.h"
#include "AswanCard_9.h"
#include "LuxorCard_10.h"
#include "HurghadaCard_11.h"
#include "TakeCityCard_12.h"
#include "LoseCityCard_13.h"
#include"ReturnMortgagedCard_14.h"
#include"BenefitAllCard_15.h"

PasteCardORCoinAction::PasteCardORCoinAction(ApplicationManager* pApp) :Action(pApp) {checkDrawing = true;}
void PasteCardORCoinAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* in = pGrid->GetInput();
	Output* out = pGrid->GetOutput();

	out->PrintMessage("Click on the cell u want your card/coinset to be pasted in:");
	finalpos = in->GetCellClicked();

	if (!finalpos.IsValidCell())
	{
		pGrid->PrintErrorMessage("Invalid cell position. Click to continue...");
		checkDrawing = false;
		return;
	}

	if (finalpos.GetCellNum() == 1 || finalpos.GetCellNum() == 99)
	{
		pGrid->PrintErrorMessage("A coinset/card can't be added to the start or end cells, Click to continue...");
		checkDrawing = false;
		return;
	}
}
void PasteCardORCoinAction::Execute()
{
	ReadActionParameters();
	if (checkDrawing == true)
	{
		Grid* pGrid = pManager->GetGrid();
		Input* in = pGrid->GetInput();
		Output* out = pGrid->GetOutput();
		Card* ncard = pGrid->GetClipboard();
		CoinSet* ncoinset = pGrid->GetcClipboard();
		if (ncoinset != NULL)
		{
			int n = ncoinset->getamount();
			CoinSet* pastecoin = new CoinSet(finalpos, n);
			bool t = pGrid->AddObjectToCell(pastecoin);
			if (!t)
			{
				pGrid->PrintErrorMessage("Error: Cell already has an object !,Click to continue.");
			}
			else if (pGrid->getclipboardcheck() == 2)
			{
				pGrid->RemoveObjectFromCell(ncoinset->GetPosition());
			}
		}
		else if (ncard != NULL)
		{
			Card* pasteCard;
			int n = ncard->GetCardNumber();
			switch (n)
			{
			case 1:
				pasteCard = new DecWalletCard_1(finalpos);
				pasteCard->SetWalletAmount(ncard->GetWalletAmount());
				break;
			case 2:
				pasteCard = new NextCard_2(finalpos);
				pasteCard->SetChoice(ncard->GetChoice());
				break;
			case 3:
				pasteCard = new BackwardCard_3(finalpos);
				break;
			case 4:
				pasteCard = new PreventCard_4(finalpos);
				break;
			case 5:
				pasteCard = new FireCard_5(finalpos);
				break;
			case 6:
				pasteCard = new FreezeCard_6(finalpos);
				pasteCard->SetFreezeBool(ncard->GetFreezeBool());
				pasteCard->SetNumberofturns(ncard->GetNumberOfTurnsFreezed());
				break;
			case 7:
				pasteCard = new CairoCard_7(finalpos);
				pasteCard->ReadCardParameters(pGrid);
				break;
			case 8:
				pasteCard = new AlexCard_8(finalpos);
				pasteCard->ReadCardParameters(pGrid);
				break;
			case 9:
				pasteCard = new AswanCard_9(finalpos);
				pasteCard->ReadCardParameters(pGrid);
				break;
			case 10:
				pasteCard = new LuxorCard_10(finalpos);
				pasteCard->ReadCardParameters(pGrid);
				break;
			case 11:
				pasteCard = new HurghadaCard_11(finalpos);
				pasteCard->ReadCardParameters(pGrid);
				break;
			case 12:
				pasteCard = new TakeCityCard_12(finalpos);
				break;
			case 13:
				pasteCard = new LoseCityCard_13(finalpos);
				break;
			case 14:
				pasteCard = new ReturnMortgagedCard_14(finalpos);
				break;
			case 15:
				pasteCard = new BenefitAllCard_15(finalpos);
				pasteCard->SetBenefitNumber(ncard->GetBenefitNumber());
				break;
			}
			if (pasteCard)
			{
				bool t = pGrid->AddObjectToCell(pasteCard);
				if (!t)
				{
					pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
				}
				else if (pGrid->getclipboardcheck() == 2)
				{
					pGrid->RemoveObjectFromCell(ncard->GetPosition());
				}
			}
		}
	}
}
PasteCardORCoinAction::~PasteCardORCoinAction() {}
