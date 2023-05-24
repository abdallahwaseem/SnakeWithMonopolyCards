#include "OfferMortgage.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include"CairoCard_7.h"
#include"AlexCard_8.h"
#include"AswanCard_9.h"
#include"LuxorCard_10.h"
#include"HurghadaCard_11.h"

OfferMortgage::OfferMortgage(ApplicationManager* pApp) : Action(pApp)
{
}
OfferMortgage::~OfferMortgage()
{
}

void OfferMortgage::ReadActionParameters()
{
}

void OfferMortgage::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	Player* pPlayer = pGrid->GetCurrentPlayer();

	if (pGrid->PlayerHasCities(pPlayer))
	{

		pOut->PrintMessage("How many cities do you want to offer?");
		NumOfOfferedCities = pIn->GetInteger(pOut);
		OfferedPos = new string[NumOfOfferedCities];
		pOut->PrintMessage("Choose the city you want to offer by typing its name.");

		for (int i = 0; i < NumOfOfferedCities; i++)
		{

			string city = pIn->GetSrting(pOut);
			while (city != "Cairo" && city != "Alex" && city != "Aswan" && city != "Luxor" && city != "Hurghada")
			{
				pOut->PrintMessage("Please enter the correct city name which is (Cairo or Alex or Aswan or Luxor or Hurghada)");
				city = pIn->GetSrting(pOut);
			}

			if (city == "Cairo")
			{
				CairoCard_7* card7 = dynamic_cast<CairoCard_7*>(pGrid->GetFirstCairoCard_7());
				if (card7)
				{
					if (card7->GetOwner() == pPlayer)
					{
						OfferedPos[i] = city;
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Cairo. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Cairo is not found. Click to Continue");

			}
			else if (city == "Alex")
			{
				AlexCard_8* card8 = dynamic_cast<AlexCard_8*>(pGrid->GetFirstAlexCard_8());
				if (card8)
				{
					if (card8->GetOwner() == pPlayer)
					{
						OfferedPos[i] = city;
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Alex. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Alex is not found. Click to Continue");
			}


			else if (city == "Aswan")
			{
				AswanCard_9* card9 = dynamic_cast<AswanCard_9*>(pGrid->GetFirstAswanCard_9());
				if (card9)
				{
					if (card9->GetOwner() == pPlayer)
					{
						OfferedPos[i] = city;
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Aswan. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Aswan is not found. Click to Continue");
			}
			else if (city == "Luxor")
			{
				LuxorCard_10* card10 = dynamic_cast<LuxorCard_10*>(pGrid->GetFirstLuxorCard_10());
				if (card10)
				{
					if (card10->GetOwner() == pPlayer)
					{
						OfferedPos[i] = city;
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Luxor. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Luxor is not found. Click to Continue");
			}
			else if (city == "Hurghada")
			{
				HurghadaCard_11* card11 = dynamic_cast<HurghadaCard_11*>(pGrid->GetFirstHurghadaCard_11());
				if (card11)
				{
					if (card11->GetOwner() == pPlayer)
					{
						OfferedPos[i] = city;
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Hurghada. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Hurghada is not found. Click to Continue");;
			}

			pOut->ClearStatusBar();
		}
		pGrid->SetOfferedPos(OfferedPos, NumOfOfferedCities);
		pGrid->SetNumOfOfferedCities(NumOfOfferedCities);

		pGrid->PrintErrorMessage("Click to see Offered cities:");
		for (int i = 0; i < NumOfOfferedCities; i++)
		{
			pGrid->PrintErrorMessage(OfferedPos[i] + " City" + ", click to continue");
		}
	}
	else
		pGrid->PrintErrorMessage("You don't have cities to offer");	
}
string* OfferMortgage::GetOfferedPos()
{
	string* collect;
	collect = new string[NumOfOfferedCities];
	for (int i = 0; i < NumOfOfferedCities; i++)
	{
		collect[i] = OfferedPos[i];
	}
	return collect;

}
