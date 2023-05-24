
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

AcceptMortgage::AcceptMortgage(ApplicationManager* pApp) : Action(pApp)
{

}
AcceptMortgage::~AcceptMortgage()
{
}

void AcceptMortgage::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	string* Offer = pGrid->GetOfferedPos();
	if (Offer == NULL)
	{
		pGrid->PrintErrorMessage("There are no offered cities to accept");
		return;
	}
	
	
	pOut->PrintMessage("How many cities do you want to accept?");
	NumberOfAcceptedCities = pIn->GetInteger(pOut);
	AcceptedPos = new string[NumberOfAcceptedCities];
	pOut->PrintMessage("Choose the city you want to accept by typing its name.");
	for (int i = 0; i < NumberOfAcceptedCities; i++)
	{
		AcceptedPos[i] = pIn->GetSrting(pOut);
	}
	pOut->ClearStatusBar();
	Player* pPlayer = pGrid->GetCurrentPlayer();
	for (int i = 0; i < NumberOfAcceptedCities; i++)
	{
		int k = 0;
		for (int j = 0; j < pGrid->GetNumOfOfferedCities(); j++)
		{
			if (AcceptedPos[i] == Offer[j])
			{
				k = 1;
				string city = AcceptedPos[i];
				while (city != "Cairo" && city != "Alex" && city != "Aswan" && city != "Luxor" && city != "Hurghada")
				{
					pOut->PrintMessage("Please enter the correct city name which is (Cairo or Alex or Aswan or Luxor or Hurghada)");
					city = pIn->GetSrting(pOut);
				}

				if (city == "Cairo")
				{
					CairoCard_7* card = dynamic_cast<CairoCard_7*>(pGrid->GetFirstCairoCard_7());
					card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
					pGrid->SetAllSubOwnerCairoCard_7(pPlayer);
					pPlayer->SetWallet((pPlayer->GetWallet()) - (card->GetPrice()) * 0.7);
					pGrid->PrintErrorMessage("Congratulations, you are mortgaging Cairo city. Click to continue...");
				}
				else if (city == "Alex")
				{
					AlexCard_8* card = dynamic_cast<AlexCard_8*>(pGrid->GetFirstAlexCard_8());
					card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
					pGrid->SetAllSubOwnerAlexCard_8(pPlayer);
					pPlayer->SetWallet((pPlayer->GetWallet()) - (card->GetPrice()) * 0.7);
					pGrid->PrintErrorMessage("Congratulations, you are mortgaging Alex city. Click to continue...");
				}
				else if (city == "Aswan")
				{
					AswanCard_9* card = dynamic_cast<AswanCard_9*>(pGrid->GetFirstAswanCard_9());
					card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
					pGrid->SetAllSubOwnerAswanCard_9(pPlayer);
					pPlayer->SetWallet((pPlayer->GetWallet()) - (card->GetPrice()) * 0.7);
					pGrid->PrintErrorMessage("Congratulations, you are mortgaging Aswan city. Click to continue...");
				}
				else if (city == "Luxor")
				{
					LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(pGrid->GetFirstLuxorCard_10());
					card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
					pGrid->SetAllSubOwnerLuxorCard_10(pPlayer);
					pPlayer->SetWallet((pPlayer->GetWallet()) - (card->GetPrice()) * 0.7);
					pGrid->PrintErrorMessage("Congratulations, you are mortgaging Luxor city. Click to continue...");
				}
				else if (city == "Hurghada")
				{
					HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(pGrid->GetFirstHurghadaCard_11());
					card->GetOwner()->SetWallet((card->GetOwner()->GetWallet()) + (card->GetPrice()) * 0.7);
					pGrid->SetAllSubOwnerHurghadaCard_11(pPlayer);
					pPlayer->SetWallet((pPlayer->GetWallet()) - (card->GetPrice()) * 0.7);
					pGrid->PrintErrorMessage("Congratulations, you are mortgaging Hurghada city. Click to continue...");
				}

			}
			if (k == 0)
				pGrid->PrintErrorMessage("The city is not offered! Click to continue");
		}
	}
}
void AcceptMortgage::ReadActionParameters()	
{

}
