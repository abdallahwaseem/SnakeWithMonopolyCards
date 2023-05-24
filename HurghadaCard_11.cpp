#include "HurghadaCard_11.h"

HurghadaCard_11::HurghadaCard_11(const CellPosition& pos)
	:Card(pos)
{
	cardNumber = 11;	// set the inherited cardNumber data member with the card number (11 here)
	Owner = NULL;		// set the Owner to null as intially it doesn't have an owner
	SubOwner = NULL;	// set the SubOwner to null as intially it doesn't have an subowner
}

void HurghadaCard_11::ReadCardParameters(Grid* pGrid)
{
	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Check if there was a HurghadaCard_11 created before this one
	Card* FoundCard = pGrid->GetFirstHurghadaCard_11();
	if (FoundCard == NULL) // If it is the first one
	{
		// 3- Read an integer from the user of the price of the city
		pOut->PrintMessage("New HurghadaCard_11: Enter price of the city: ");
		Price = pIn->GetInteger(pOut);

		// 4- Read an integer from the user of the fees to paid by other users
		pOut->PrintMessage("New HurghadaCard_11: Enter fees to be paid of the city: ");
		Fees = pIn->GetInteger(pOut);

		// 5- Clear status bar
		pOut->ClearStatusBar();
	}
	else // If it was not the first
	{
		HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*> (FoundCard);
		Price = card->Price;
		Fees = card->Fees;
	}
}

void HurghadaCard_11::Apply(Grid* pGrid, Player* pPlayer)
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
				pGrid->SetAllOwnerHurghadaCard_11(pPlayer);
				pGrid->PrintErrorMessage("Congratulations, player " + to_string(pPlayer->GetPlayernum()) + ": you are the owner of Hurghada city");
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

void HurghadaCard_11::SetOwner(Player* pPlayer)
{
	Owner = pPlayer;
}

void HurghadaCard_11::SetSubOwner(Player* pPlayer)
{
	SubOwner = pPlayer;
}


Player* HurghadaCard_11::GetOwner()
{
	return Owner;
}
Player* HurghadaCard_11::GetSubOwner()
{
	return SubOwner;
}
int HurghadaCard_11::GetPrice()
{
	return Price;
}

HurghadaCard_11::~HurghadaCard_11()
{
}

void HurghadaCard_11::Save(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		if (count == 0)
		{
			OutFile << cardNumber << "  " << position.GetCellNum() << " " << Price<<" " << Fees<<endl;
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
int HurghadaCard_11::count = 0;
void HurghadaCard_11::Load(ifstream& Infile, int a, CellPosition& s, CellPosition& e, int& amount)
{
	if (a == save)
	{

		int b, c;
		Infile >> b >> c;
		Price = b;
		Fees = c;
	}
}