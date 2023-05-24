#include "SellCity.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include"CairoCard_7.h"
#include"AlexCard_8.h"
#include"AswanCard_9.h"
#include"LuxorCard_10.h"
#include"HurghadaCard_11.h"
SellCity::SellCity(ApplicationManager* pApp) : Action(pApp)
{

}
SellCity::~SellCity()
{
}
void SellCity::Execute()
{

	Grid* pGrid = pManager->GetGrid();
	Player* pPlayer = pGrid->GetCurrentPlayer();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	if (pGrid->PlayerHasCities(pPlayer))
	{
		pOut->PrintMessage("How many cities do you want to sell?");
		NumberOfSoldCities = pIn->GetInteger(pOut);
		SoldPos = new string[NumberOfSoldCities];
		pOut->PrintMessage("Choose the city you want to sell by typing its name.");

		for (int i = 0; i < NumberOfSoldCities; i++)
		{
			SoldPos[i] = pIn->GetSrting(pOut);
		}
		pOut->ClearStatusBar();
		for (int i = 0; i < NumberOfSoldCities; i++)
		{

			string city = SoldPos[i];
			while (city != "Cairo" && city != "Alex" && city != "Aswan" && city != "Luxor" && city != "Hurghada")
			{
				pOut->PrintMessage("Please enter the correct city name which is (Cairo or Alex or Aswan or Luxor or Hurghada)");
				city = pIn->GetSrting(pOut);
			}

			if (city == "Cairo")
			{
				CairoCard_7* card = dynamic_cast<CairoCard_7*>(pGrid->GetFirstCairoCard_7());;
				if (card)
				{
					if (card->GetOwner() == pPlayer)
					{
						if (card->GetSubOwner() == NULL)
						{
							card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.9);
							pGrid->SetAllOwnerCairoCard_7(NULL);
						}
						else
							pGrid->PrintErrorMessage("Sorry this city is mortgaged. Click to Continue");
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
						if (card->GetSubOwner() == NULL)
						{
							card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.9);
							pGrid->SetAllOwnerAlexCard_8(NULL);
						}
						else
							pGrid->PrintErrorMessage("Sorry this city is mortgaged. Click to Continue");
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
						if (card->GetSubOwner() == NULL)
						{
							card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.9);
							pGrid->SetAllOwnerAswanCard_9(NULL);
						}
						else
							pGrid->PrintErrorMessage("Sorry this city is mortgaged. Click to Continue");
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
						if (card->GetSubOwner() == NULL)
						{
							card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.9);
							pGrid->SetAllOwnerLuxorCard_10(NULL);
						}
						else
							pGrid->PrintErrorMessage("Sorry this city is mortgaged. Click to Continue");
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
						if (card->GetSubOwner() == NULL)
						{
							card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.9);
							pGrid->SetAllOwnerHurghadaCard_11(NULL);
						}
						else
							pGrid->PrintErrorMessage("Sorry this city is mortgaged. Click to Continue");
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
		pGrid->PrintErrorMessage("You don't have cities to sell. Click to continue...");
}
void SellCity::ReadActionParameters()
{

}