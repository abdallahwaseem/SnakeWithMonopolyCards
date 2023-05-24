#include "ReturnMortgagedCard_14.h"
#include "CairoCard_7.h"
#include "AlexCard_8.h"
#include "AswanCard_9.h"
#include "LuxorCard_10.h"
#include "HurghadaCard_11.h"
#include"Grid.h"




ReturnMortgagedCard_14::ReturnMortgagedCard_14(const CellPosition& pos):Card(pos)
{
	cardNumber = 14; // set the inherited cardNumber data member with the card number (14 here)
}

void ReturnMortgagedCard_14::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);

	// Get the Lowest price card
	Card* pcard = pGrid->GetLowestPriceCity(pGrid, pPlayer);
	CairoCard_7* card7 = dynamic_cast<CairoCard_7*> (pcard);
	AlexCard_8* card8 = dynamic_cast<AlexCard_8*> (pcard);
	AswanCard_9* card9 = dynamic_cast<AswanCard_9*> (pcard);
	LuxorCard_10* card10 = dynamic_cast<LuxorCard_10*> (pcard);
	HurghadaCard_11* card11 = dynamic_cast<HurghadaCard_11*> (pcard);
	if (card7)
	{
		if (card7->GetSubOwner() != NULL)
		{
			pGrid->SetAllSubOwnerCairoCard_7(NULL);
			pGrid->PrintErrorMessage("You have returned Cairo city. Click to continue...");
		}
		else
			pGrid->PrintErrorMessage("You haven't mortgaged Cairo city. Click to continue...");
	}
	else if (card8)
	{
		if (card8->GetSubOwner() != NULL)
		{
			pGrid->SetAllSubOwnerAlexCard_8(NULL);
			pGrid->PrintErrorMessage("You have returned Alex city. Click to continue...");
		}
		else
			pGrid->PrintErrorMessage("You haven't mortgaged Alex city. Click to continue...");
	}
	else if (card9)
	{
		if (card9->GetSubOwner() != NULL)
		{
			pGrid->SetAllSubOwnerAswanCard_9(NULL);
			pGrid->PrintErrorMessage("You have returned Aswan city. Click to continue...");
		}
		else
			pGrid->PrintErrorMessage("You haven't mortgaged Aswan city. Click to continue...");
	}
	else if (card10)
	{
		if (card7->GetSubOwner() != NULL)
		{
			pGrid->SetAllSubOwnerLuxorCard_10(NULL);
			pGrid->PrintErrorMessage("You have returned Luxor city. Click to continue...");
		}
		else
			pGrid->PrintErrorMessage("You haven't mortgaged Luxor city. Click to continue...");
	}
	else if (card11)
	{
		if (card7->GetSubOwner() != NULL)
		{
			pGrid->SetAllSubOwnerHurghadaCard_11(NULL);
			pGrid->PrintErrorMessage("You have returned Hurghada city. Click to continue...");
		}
		else
			pGrid->PrintErrorMessage("You haven't mortgaged Hurghada city. Click to continue...");
	}
	else
		pGrid->PrintErrorMessage("You don't have any cities to return. Click to continue...");

}

ReturnMortgagedCard_14::~ReturnMortgagedCard_14()
{
}