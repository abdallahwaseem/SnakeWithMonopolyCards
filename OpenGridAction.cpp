#include"OpenGridAction.h"
#include "Grid.h"
#include"ladder.h"
#include"Snake.h"
#include"CoinSet.h"
#include"card.h"
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

OpenGridAction::OpenGridAction(ApplicationManager* pApp) :Action(pApp) {}
void OpenGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* in = pGrid->GetInput();
	Output* out = pGrid->GetOutput();

	out->PrintMessage("write the name of the text file you wish to open");
	lfilename = in->GetSrting(out);
	loadfile.open(lfilename + ".txt");
}
void OpenGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* in = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	int cairocounter = 0;
	int alexcounter = 0;
	int aswancounter = 0;
	int luxorcounter = 0;
	int hurghadacounter = 0;
	int l, s, cs, c;
	if (loadfile.fail())
	{
		pGrid->PrintErrorMessage("Can't open the text file, Click to continue");
	}
	else
	{
		pGrid->DeleteAll();
		pGrid->UpdateInterface();
		loadfile >> l;
		for (int i = 0;i < l;i++)
		{
			Ladder* ladderptr;
			CellPosition start;
			CellPosition end;
			int a;
			ladderptr = new Ladder(start, end);
			ladderptr->Load(loadfile, 2, start, end,a);
			delete ladderptr;
			ladderptr = new Ladder(start, end);
			pGrid->AddObjectToCell(ladderptr);
			pGrid->GetOutput()->DrawLadder(start, end);
		}
		loadfile >> s;
		for (int i = 0;i < s;i++)
		{
			Snake* Snakeptr;
			CellPosition start;
			CellPosition end;
			int a;
			Snakeptr = new Snake(start, end);
			Snakeptr->Load(loadfile, 4, start, end,a);
			delete Snakeptr;
			Snakeptr = new Snake(start, end);
			pGrid->AddObjectToCell(Snakeptr);
			out->DrawSnake(start, end);
		}
		loadfile >> cs;
		for (int i = 0;i < cs;i++)
		{
			CoinSet* CoinSetptr;
			CellPosition start;
			CellPosition end;
			int amount=0;
			CoinSetptr = new CoinSet(start, amount);
			CoinSetptr->Load(loadfile, 3, start,end, amount);
			delete CoinSetptr;
			CoinSetptr = new CoinSet(start, amount);
			pGrid->AddObjectToCell(CoinSetptr);
			out->DrawCoinSet(start);
		}
		loadfile >> c;
		for (int i = 0;i < c;i++)
		{
			Card* Cardptr;
			CellPosition end;
			int amount = 0;
			int n;
			int h;
			
			loadfile >> n>>h;
			CellPosition start(h);
			switch (n)
			{
			case 1:
				Cardptr = new DecWalletCard_1(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
				
			case 2:
				Cardptr = new NextCard_2(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			case 3:
				Cardptr = new BackwardCard_3(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			case 4:
				Cardptr = new PreventCard_4(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			case 5:
				Cardptr = new FireCard_5(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			case 6:
				Cardptr = new FreezeCard_6(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			case 7:
				Cardptr = new CairoCard_7(start);
				if (cairocounter== 0)
				{
					Cardptr->Load(loadfile, 1, start, end, amount);
					cairocounter++;
				}
				else
				{
					Cardptr->ReadCardParameters(pGrid);
				}
				break;
			case 8:
				Cardptr = new AlexCard_8(start);
				
				if (alexcounter == 0)
				{
					Cardptr->Load(loadfile, 1, start, end, amount);
					alexcounter++;
				}
				else
				{
					Cardptr->ReadCardParameters(pGrid);
				}
				break;
			case 9:
				Cardptr = new AswanCard_9(start);
				
				if (aswancounter == 0)
				{
					Cardptr->Load(loadfile, 1, start, end, amount);
					aswancounter++;
				}
				else
				{
					Cardptr->ReadCardParameters(pGrid);
				}
				break;
			case 10:
				Cardptr = new LuxorCard_10(start);
				if (luxorcounter == 0)
				{
					Cardptr->Load(loadfile, 1, start, end, amount);
					luxorcounter++;
				}
				else
				{
					Cardptr->ReadCardParameters(pGrid);
				}
				break;
			case 11:
				Cardptr = new HurghadaCard_11(start);
				if (hurghadacounter == 0)
				{
					Cardptr->Load(loadfile, 1, start, end, amount);
					hurghadacounter++;
				}
				else
				{
					Cardptr->ReadCardParameters(pGrid);
				}
				break;
			case 12:
				Cardptr = new TakeCityCard_12(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			case 13:
				Cardptr = new LoseCityCard_13(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			case 14:
				Cardptr = new ReturnMortgagedCard_14(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			case 15:
				Cardptr = new BenefitAllCard_15(start);
				Cardptr->Load(loadfile, 1, start, end, amount);
				break;
			}
			Cardptr->SetCardNumber(n);
			pGrid->AddObjectToCell(Cardptr);
			pGrid->GetOutput()->DrawCell(start, Cardptr->GetCardNumber());
		}
		pGrid->PrintErrorMessage("Grid loaded successfully. Click to continue...");
	}
}
OpenGridAction::~OpenGridAction(){}