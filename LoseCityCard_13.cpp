#include "CairoCard_7.h"
#include "AlexCard_8.h"
#include "AswanCard_9.h"
#include "LuxorCard_10.h"
#include "HurghadaCard_11.h"
#include "LoseCityCard_13.h"



LoseCityCard_13::LoseCityCard_13(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 13; // set the inherited cardNumber data member with the card number (13 here)
}

void LoseCityCard_13::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// Get the highest price card
	Card* pCard = pGrid->GetHighestPriceCity(pGrid, pPlayer);

	if (CairoCard_7* CairoCard = dynamic_cast<CairoCard_7*> (pCard))
	{
		pGrid->SetAllOwnerCairoCard_7(NULL);
		pGrid->PrintErrorMessage("Player " + to_string(pPlayer->GetPlayernum()) + " you have lost Cairo city. Click to continue...");
	}
	else if (AlexCard_8* CairoCard = dynamic_cast<AlexCard_8*> (pCard))
	{
		pGrid->SetAllOwnerAlexCard_8(NULL);
		pGrid->PrintErrorMessage("Player " + to_string(pPlayer->GetPlayernum()) + " you have lost Alex city. Click to continue...");
	}
	else if (AswanCard_9* CairoCard = dynamic_cast<AswanCard_9*> (pCard))
	{
		pGrid->SetAllOwnerAswanCard_9(NULL);
		pGrid->PrintErrorMessage("Player " + to_string(pPlayer->GetPlayernum()) + " you have lost Aswan city. Click to continue...");
	}
	else if (LuxorCard_10* CairoCard = dynamic_cast<LuxorCard_10*> (pCard))
	{
		pGrid->SetAllOwnerLuxorCard_10(NULL);
		pGrid->PrintErrorMessage("Player " + to_string(pPlayer->GetPlayernum()) + " you have lost Luxor city. Click to continue...");
	}
	else if (HurghadaCard_11* CairoCard = dynamic_cast<HurghadaCard_11*> (pCard))
	{
		pGrid->SetAllOwnerHurghadaCard_11(NULL);
		pGrid->PrintErrorMessage("Player " + to_string(pPlayer->GetPlayernum()) + " you have lost Hurghada city. Click to continue...");
	}
	else
		pGrid->PrintErrorMessage("You don't have any cities to lose. Click to continue...");


}

LoseCityCard_13::~LoseCityCard_13()
{
}