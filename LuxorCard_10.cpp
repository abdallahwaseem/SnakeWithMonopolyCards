#include "LuxorCard_10.h"

LuxorCard_10::LuxorCard_10(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 10;	// set the inherited cardNumber data member with the card number (10 here)
	Owner = NULL;		// set the Owner to null as intially it doesn't have an owner
	SubOwner = NULL;	// set the SubOwner to null as intially it doesn't have an subowner
}

void LuxorCard_10::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Check if there was a CairoCard_7 created before this one
	Card* FoundCard = pGrid->GetFirstLuxorCard_10();
	if (FoundCard == NULL) // If it is the first one
	{
		// 3- Read an integer from the user of the price of the city
		pOut->PrintMessage("New LuxorCard_10: Enter price of the city: ");
		Price = pIn->GetInteger(pOut);

		// 4- Read an integer from the user of the fees to paid by other users
		pOut->PrintMessage("New LuxorCard_10: Enter fees to be paid of the city: ");
		Fees = pIn->GetInteger(pOut);

		// 5- Clear status bar
		pOut->ClearStatusBar();
	}
	else // If it was not the first
	{
		LuxorCard_10* card = dynamic_cast<LuxorCard_10*> (FoundCard);
		Price = card->Price;
		Fees = card->Fees;
	}
}

void LuxorCard_10::Apply(Grid* pGrid, Player* pPlayer)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	if (Owner == NULL && SubOwner == NULL) // Check if city is bought
	{
		if (pPlayer->GetWallet() >= Price)	// Check if player has enough coins
		{
			pOut->PrintMessage("You have reached a city. Do you want to buy it? y/n");
			string bought = pIn->GetSrting(pOut);
			while (bought != "y" && bought != "n")
			{
				pOut->PrintMessage("Please enter y for Yes or n for No");
				bought = pIn->GetSrting(pOut);
			}
			pOut->ClearStatusBar();
			if (bought == "y") // Check if player wants to buy city
			{
				pPlayer->SetWallet((pPlayer->GetWallet()) - Price);
				pGrid->SetAllOwnerLuxorCard_10(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, player " + to_string(pPlayer->GetPlayernum()) + ": you are the owner of Luxor city");
			}
		}
		else
			pGrid->PrintErrorMessage("You don't have enough coins to buy this city. Click to continue...");
		return;
	}
	if (pGrid->GetBenefitPlayer() == NULL)	// Checks that benefit card is not activated
	{
		if (Owner != NULL && SubOwner == NULL)	// Checks that the city is bought and not mortgaged
		{
			if (pPlayer != Owner)	// Check that the current player is not the owner
			{
				pGrid->PrintErrorMessage("You have reached a bought city. Click to continue...");
				pPlayer->SetWallet((pPlayer->GetWallet()) - Fees);	// Deduct the fees from the player's wallet
				Owner->SetWallet((Owner->GetWallet()) + Fees);		// Add the fees to the owner's wallet
			}
			else
				pGrid->PrintErrorMessage("You have reached your city. Click to continue...");
		}
		else if (SubOwner != NULL) // Check if city is mortgaged
		{
			if (pPlayer != SubOwner)
			{
				pGrid->PrintErrorMessage("You have reached a bought city. Click to continue...");
				pPlayer->SetWallet((pPlayer->GetWallet()) - Fees);
				SubOwner->SetWallet((SubOwner->GetWallet()) + Fees);
			}
			else
				pGrid->PrintErrorMessage("You have reached your city. Click to continue...");
		}
	}
	else
	{
		Player* currentOwner = pGrid->GetBenefitPlayer();
		pGrid->PrintErrorMessage("You have reached a bought city. Click to continue...");
		pPlayer->SetWallet((pPlayer->GetWallet()) - Fees);
		currentOwner->SetWallet(currentOwner->GetWallet() + Fees);
	}
}

void LuxorCard_10::SetOwner(Player* pPlayer)
{
	Owner = pPlayer;
}
Player* LuxorCard_10::GetOwner()
{
	return Owner;
}
Player* LuxorCard_10::GetSubOwner()
{
	return SubOwner;
}
int LuxorCard_10::GetPrice()
{
	return Price;
}
void LuxorCard_10::SetSubOwner(Player* pPlayer)
{
	SubOwner = pPlayer;
}
LuxorCard_10::~LuxorCard_10()
{
}
int LuxorCard_10::count = 0;

void LuxorCard_10::Save(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		if (count == 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum() << " " << Price << " " << Fees << endl;
			count++;
		}
		else if (count > 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum()<<" "<<endl;
			count++;
		}
	}
	else
		return;
}

void LuxorCard_10::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (a == save)
	{
		int b, c;
		Infile >> b >> c;
		Price = b;
		Fees = c;
	}
}