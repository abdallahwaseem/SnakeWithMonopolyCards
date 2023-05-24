#include "CairoCard_7.h"
#include "AlexCard_8.h"
#include "AswanCard_9.h"
#include "LuxorCard_10.h"
#include "HurghadaCard_11.h"
#include "TakeCityCard_12.h"


TakeCityCard_12::TakeCityCard_12(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number (12 here)
}

void TakeCityCard_12::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// 2- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 3- Choose the city to take
	pOut->PrintMessage("Enter the name of the city you want to take: ");
	string city = pIn->GetSrting(pOut);

	while (city != "Cairo" && city != "Alex" && city != "Aswan" && city != "Luxor" && city != "Hurghada")
	{
		pOut->PrintMessage("Please enter the correct city name which is (Cairo or Alex or Aswan or Luxor or Hurghada)");
		city = pIn->GetSrting(pOut);
	}

	if (city == "Cairo")
	{
		CairoCard_7* card = dynamic_cast<CairoCard_7*>(pGrid->GetFirstCairoCard_7());
		if (card == NULL)
			pGrid->PrintErrorMessage("This city is not available on the grid. Click to continue...");
		else
		{
			if (card->GetOwner() == NULL && card->GetSubOwner() == NULL)
			{
				pGrid->SetAllOwnerCairoCard_7(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Cairo city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() == NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Cairo city. Click to continue...");
				pGrid->SetAllOwnerCairoCard_7(NULL);
				pGrid->SetAllOwnerCairoCard_7(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Cairo city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() != NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Cairo city. Click to continue...");
				pGrid->SetAllOwnerCairoCard_7(NULL);
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Cairo city. Click to continue.");
				pGrid->SetAllSubOwnerCairoCard_7(NULL);
				pGrid->SetAllOwnerCairoCard_7(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Cairo city");
			}
			else
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Cairo city. Click to continue.");
				pGrid->SetAllSubOwnerCairoCard_7(NULL);
				pGrid->SetAllOwnerCairoCard_7(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Cairo city");
			}
		}

	}
	else if (city == "Alex")
	{
		AlexCard_8* card = dynamic_cast<AlexCard_8*>(pGrid->GetFirstAlexCard_8());
		if (card == NULL)
			pGrid->PrintErrorMessage("This city is not available on the grid.");
		else
		{
			if (card->GetOwner() == NULL && card->GetSubOwner() == NULL)
			{
				pGrid->SetAllOwnerAlexCard_8(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Alex city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() == NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Alex city. Click to continue...");
				pGrid->SetAllOwnerAlexCard_8(NULL);
				pGrid->SetAllOwnerAlexCard_8(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Alex city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() != NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Alex city. Click to continue...");
				pGrid->SetAllOwnerAlexCard_8(NULL);
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Alex city. Click to continue.");
				pGrid->SetAllSubOwnerAlexCard_8(NULL);
				pGrid->SetAllOwnerAlexCard_8(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Alex city");
			}
			else
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Alex city. Click to continue.");
				pGrid->SetAllSubOwnerAlexCard_8(NULL);
				pGrid->SetAllOwnerAlexCard_8(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Alex city");
			}
		}
	}
	else if (city == "Aswan")
	{
		AswanCard_9* card = dynamic_cast<AswanCard_9*>(pGrid->GetFirstAswanCard_9());
		if (card == NULL)
			pGrid->PrintErrorMessage("This city is not available on the grid.");
		else
		{
			if (card->GetOwner() == NULL && card->GetSubOwner() == NULL)
			{
				pGrid->SetAllOwnerAswanCard_9(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Aswan city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() == NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Aswan city. Click to continue...");
				pGrid->SetAllOwnerAswanCard_9(NULL);
				pGrid->SetAllOwnerAswanCard_9(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Aswan city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() != NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Aswan city. Click to continue...");
				pGrid->SetAllOwnerAswanCard_9(NULL);
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Aswan city. Click to continue.");
				pGrid->SetAllSubOwnerAswanCard_9(NULL);
				pGrid->SetAllOwnerAswanCard_9(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Aswan city");
			}
			else
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Aswan city. Click to continue.");
				pGrid->SetAllSubOwnerAswanCard_9(NULL);
				pGrid->SetAllOwnerAswanCard_9(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Aswan city");
			}
		}
	}
	else if (city == "Luxor")
	{
		LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(pGrid->GetFirstLuxorCard_10());
		if (card == NULL)
			pGrid->PrintErrorMessage("This city is not available on the grid.");
		else
		{
			if (card->GetOwner() == NULL && card->GetSubOwner() == NULL)
			{
				pGrid->SetAllOwnerLuxorCard_10(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Luxor city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() == NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Luxor city. Click to continue...");
				pGrid->SetAllOwnerLuxorCard_10(NULL);
				pGrid->SetAllOwnerLuxorCard_10(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Aswan city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() != NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Luxor city. Click to continue...");
				pGrid->SetAllOwnerLuxorCard_10(NULL);
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Luxor city. Click to continue.");
				pGrid->SetAllSubOwnerLuxorCard_10(NULL);
				pGrid->SetAllOwnerLuxorCard_10(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Aswan city");
			}
			else
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Luxor city. Click to continue.");
				pGrid->SetAllSubOwnerLuxorCard_10(NULL);
				pGrid->SetAllOwnerLuxorCard_10(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Luxor city");
			}
		}
	}
	else if (city == "Hurghada")
	{
		HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(pGrid->GetFirstHurghadaCard_11());
		if (card == NULL)
			pGrid->PrintErrorMessage("This city is not available on the grid.");
		else
		{
			if (card->GetOwner() == NULL && card->GetSubOwner() == NULL)
			{
				pGrid->SetAllOwnerHurghadaCard_11(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Hurghada city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() == NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Hurghada city. Click to continue...");
				pGrid->SetAllOwnerHurghadaCard_11(NULL);
				pGrid->SetAllOwnerHurghadaCard_11(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Hurghada city");
			}
			else if (card->GetOwner() != NULL && card->GetSubOwner() != NULL)
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetOwner()->GetPlayernum()) + " Lost Hurghada city. Click to continue...");
				pGrid->SetAllOwnerHurghadaCard_11(NULL);
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Hurghada city. Click to continue.");
				pGrid->SetAllSubOwnerHurghadaCard_11(NULL);
				pGrid->SetAllOwnerHurghadaCard_11(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Hurghada city");
			}
			else
			{
				pGrid->PrintErrorMessage("Player number " + to_string(card->GetSubOwner()->GetPlayernum()) + " is no longer mortgaging Hurghada city. Click to continue.");
				pGrid->SetAllSubOwnerHurghadaCard_11(NULL);
				pGrid->SetAllOwnerHurghadaCard_11(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, you are the owner of Hurghada city");
			}
		}

	}

}

TakeCityCard_12::~TakeCityCard_12()
{
}