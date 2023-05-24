#include "AlexCard_8.h"

AlexCard_8::AlexCard_8(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 8;		// set the inherited cardNumber data member with the card number (8 here)
	Owner = NULL;		// set the Owner to null as intially it doesn't have an owner
	SubOwner = NULL;	// set the SubOwner to null as intially it doesn't have an subowner
}

void AlexCard_8::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Check if there was a AlexCard_8 created before this one
	Card* FoundCard = pGrid->GetFirstAlexCard_8();
	if (FoundCard == NULL) // If it is the first one
	{
		// 3- Read an integer from the user of the price of the city
		pOut->PrintMessage("New AlexCard_8: Enter price of the city: ");
		Price = pIn->GetInteger(pOut);

		// 4- Read an integer from the user of the fees to paid by other users
		pOut->PrintMessage("New AlexCard_8: Enter fees to be paid of the city: ");
		Fees = pIn->GetInteger(pOut);

		// 5- Clear status bar
		pOut->ClearStatusBar();
	}
	else // If it was not the first
	{
		AlexCard_8* card = dynamic_cast<AlexCard_8*> (FoundCard);
		Price = card->Price;
		Fees = card->Fees;
	}
}

void AlexCard_8::Apply(Grid* pGrid, Player* pPlayer)
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
				pGrid->SetAllOwnerAlexCard_8(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, player " + to_string(pPlayer->GetPlayernum()) + ": you are the owner of Alex city");
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

void AlexCard_8::SetOwner(Player* pPlayer)
{
	Owner = pPlayer;
}

void AlexCard_8::SetSubOwner(Player* pPlayer)
{
	SubOwner = pPlayer;
}

Player* AlexCard_8::GetOwner()
{
	return Owner;
}
Player* AlexCard_8::GetSubOwner()
{
	return SubOwner;
}
int AlexCard_8::GetPrice()
{
	return Price;
}
AlexCard_8::~AlexCard_8()
{
}

void AlexCard_8::Save(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		if (count == 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum() << " " << Price<<" " << Fees<<" "<<endl;
			count++;
		}
		else if (count > 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum() << endl;
			count++;
		}
	}
	else
		return;
}

int AlexCard_8::count = 0;

void AlexCard_8::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (a == save)
	{

		int b, c;
		Infile >> b >> c;
		Price = b;
		Fees = c;
	}
}