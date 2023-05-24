#include "ReturnMortgage.h"
#include "AcceptMortgage.h"
#include "OfferMortgage.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include"CairoCard_7.h"
#include"AlexCard_8.h"
#include"AswanCard_9.h"
#include"LuxorCard_10.h"
#include"HurghadaCard_11.h"

ReturnMortgage::ReturnMortgage(ApplicationManager* pApp) : Action(pApp)
{

}
ReturnMortgage::~ReturnMortgage()
{
}

void ReturnMortgage::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Player* pPlayer = pGrid->GetCurrentPlayer();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pGrid->PlayerHasCities(pPlayer))
	{
		pOut->PrintMessage("How many cities do you want to return?");
		NumOfReturnedCities = pIn->GetInteger(pOut);
		ReturnedPos = new string[NumOfReturnedCities];
		pOut->PrintMessage("Choose the city you want to return by typing its name.");
		for (int i = 0; i < NumOfReturnedCities; i++)
		{
			ReturnedPos[i] = pIn->GetSrting(pOut);
		}
		pOut->ClearStatusBar();

		for (int i = 0; i < NumOfReturnedCities; i++)
		{
			string city = ReturnedPos[i];
			while (city != "Cairo" && city != "Alex" && city != "Aswan" && city != "Luxor" && city != "Hurghada")
			{
				pOut->PrintMessage("Please enter the correct city name which is (Cairo or Alex or Aswan or Luxor or Hurghada)");
				city = pIn->GetSrting(pOut);
			}

			if (city == "Cairo")
			{
				CairoCard_7* card = dynamic_cast<CairoCard_7*>(pGrid->GetFirstCairoCard_7());
				if (card)
				{
					if (card->GetOwner() == pPlayer)
					{
						card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) - (card->GetPrice()) * 0.7);
						card->GetSubOwner()->SetWallet((card->GetSubOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
						pGrid->SetAllSubOwnerCairoCard_7(NULL);
						pGrid->PrintErrorMessage("Conragtulations, you returned Cairo city. Click to continue...");
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Cairo. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Cairo is not found. Click to Continue");

			}
			else if (city == "Alex")
			{
				AlexCard_8* card = dynamic_cast<AlexCard_8*>(pGrid->GetFirstAlexCard_8());
				if (card)
				{
					if (card->GetOwner() == pPlayer)
					{
						card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) - (card->GetPrice()) * 0.7);
						card->GetSubOwner()->SetWallet((card->GetSubOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
						pGrid->SetAllSubOwnerAlexCard_8(NULL);
						pGrid->PrintErrorMessage("Conragtulations, you returned Alex city. Click to continue...");
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Alex. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Alex is not found. Click to Continue");
			}
			else if (city == "Aswan")
			{
				AswanCard_9* card = dynamic_cast<AswanCard_9*>(pGrid->GetFirstAswanCard_9());
				if (card)
				{
					if (card->GetOwner() == pPlayer)
					{
						card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) - (card->GetPrice()) * 0.7);
						card->GetSubOwner()->SetWallet((card->GetSubOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
						pGrid->SetAllSubOwnerAswanCard_9(NULL);
						pGrid->PrintErrorMessage("Conragtulations, you returned Aswan city. Click to continue...");
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Aswan. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Aswan is not found. Click to Continue");
			}
			else if (city == "Luxor")
			{
				LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(pGrid->GetFirstLuxorCard_10());
				if (card)
				{
					if (card->GetOwner() == pPlayer)
					{
						card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) - (card->GetPrice()) * 0.7);
						card->GetSubOwner()->SetWallet((card->GetSubOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
						pGrid->SetAllSubOwnerLuxorCard_10(NULL);
						pGrid->PrintErrorMessage("Conragtulations, you returned Luxor city. Click to continue...");
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Luxor. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Luxor is not found. Click to Continue");
			}
			else if (city == "Hurghada")
			{
				HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(pGrid->GetFirstHurghadaCard_11());
				if (card)
				{
					if (card->GetOwner() == pPlayer)
					{
						card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) - (card->GetPrice()) * 0.7);
						card->GetSubOwner()->SetWallet((card->GetSubOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
						pGrid->SetAllSubOwnerHurghadaCard_11(NULL);
						pGrid->PrintErrorMessage("Conragtulations, you returned Hurghada city. Click to continue...");
					}
					else
						pGrid->PrintErrorMessage("Sorry you are not the owner of Hurghada. Click to Continue");
				}
				else
					pOut->PrintMessage("Sorry Hurghada is not found. Click to Continue");
			}
		}
	}
	else
		pGrid->PrintErrorMessage("You don't have cities to return. Click to continue...");

}
void ReturnMortgage::ReadActionParameters()
{
}