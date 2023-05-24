#include "AswanCard_9.h"

AswanCard_9::AswanCard_9(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 9;		// set the inherited cardNumber data member with the card number (9 here)
	Owner = NULL;		// set the Owner to null as intially it doesn't have an owner
	SubOwner = NULL;	// set the SubOwner to null as intially it doesn't have an subowner
}

void AswanCard_9::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Check if there was a AswanCard_9 created before this one
	Card* FoundCard = pGrid->GetFirstAswanCard_9();
	if (FoundCard == NULL) // If it is the first one
	{
		// 3- Read an integer from the user of the price of the city
		pOut->PrintMessage("New AswanCard_9: Enter price of the city: ");
		Price = pIn->GetInteger(pOut);

		// 4- Read an integer from the user of the fees to paid by other users
		pOut->PrintMessage("New AswanCard_9: Enter fees to be paid of the city: ");
		Fees = pIn->GetInteger(pOut);

		// 5- Clear status bar
		pOut->ClearStatusBar();
	}
	else // If it was not the first
	{
		AswanCard_9* card = dynamic_cast<AswanCard_9*> (FoundCard);
		Price = card->Price;
		Fees = card->Fees;
	}
}

void AswanCard_9::Apply(Grid* pGrid, Player* pPlayer)
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
				pGrid->SetAllOwnerAswanCard_9(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, player " + to_string(pPlayer->GetPlayernum()) + ": you are the owner of Aswan city");
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


void AswanCard_9::SetOwner(Player* pPlayer)
{
	Owner = pPlayer;
}

Player* AswanCard_9::GetOwner()
{
	return Owner;
}
Player* AswanCard_9::GetSubOwner()
{
	return SubOwner;
}
int AswanCard_9::GetPrice()
{
	return Price;
}
void AswanCard_9::SetSubOwner(Player* pPlayer)
{
	SubOwner = pPlayer;
}

AswanCard_9::~AswanCard_9()
{
}

void AswanCard_9::Save(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		if (count == 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum() << " " << Price << " " << Fees <<" "<< endl;
			count++;
		}
		else if (count > 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum() << " " << endl;;
			count++;
		}
	}
	else
		return;
}

int AswanCard_9::count = 0;
void AswanCard_9::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (a == save)
	{

		int b, c;
		Infile >> b >> c;
		Price = b;
		Fees = c;
	}
}