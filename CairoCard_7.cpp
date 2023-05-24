#include "CairoCard_7.h"

CairoCard_7::CairoCard_7(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 7;		// set the inherited cardNumber data member with the card number (7 here)
	Owner = NULL;		// set the Owner to null as intially it doesn't have an owner
	SubOwner = NULL;	// set the SubOwner to null as intially it doesn't have an subowner
}

void CairoCard_7::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Check if there was a CairoCard_7 created before this one
	Card* FoundCard = pGrid->GetFirstCairoCard_7();
	if (FoundCard == NULL) // If it is the first one
	{
		// 3- Read an integer from the user of the price of the city
		pOut->PrintMessage("New CairoCard_7: Enter price of the city: ");
		Price = pIn->GetInteger(pOut);

		// 4- Read an integer from the user of the fees to paid by other users
		pOut->PrintMessage("New CairoCard_7: Enter fees to be paid of the city: ");
		Fees = pIn->GetInteger(pOut);

		// 5- Clear status bar
		pOut->ClearStatusBar();
	}
	else // If it was not the first
	{
		CairoCard_7* card = dynamic_cast<CairoCard_7*> (FoundCard);
		Price = card->Price;
		Fees = card->Fees;
	}
}

void CairoCard_7::Apply(Grid* pGrid, Player* pPlayer)
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
				pGrid->SetAllOwnerCairoCard_7(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, player " + to_string(pPlayer->GetPlayernum()) + ": you are the owner of Cairo city");
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

void CairoCard_7::SetOwner(Player* pPlayer)
{
	Owner = pPlayer;
}

Player* CairoCard_7::GetOwner()
{
	return Owner;
}
Player* CairoCard_7::GetSubOwner()
{
	return SubOwner;
}
int CairoCard_7::GetPrice()
{
	return Price;
}
void CairoCard_7::SetSubOwner(Player* pPlayer)
{
	SubOwner = pPlayer;
}


CairoCard_7::~CairoCard_7()
{
}
void CairoCard_7::Save(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		if (count == 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum() << " " << Price << " " << Fees << endl;;
			count++;
		}
		else if (count > 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum() << " " << endl;
			count++;
		}
	}
	else
		return;
}

int CairoCard_7::count = 0;
int CairoCard_7::open = 0;
void CairoCard_7::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (open == 0)
	{
		if (a == save)
		{
			int b, c;
			Infile >> b >> c;
			Price = b;
			Fees = c;
		}
	}
}