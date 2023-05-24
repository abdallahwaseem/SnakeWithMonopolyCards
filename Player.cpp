#include "Player.h"
#include "GameObject.h"
#include "FreezeCard_6.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(1), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	playable = true;
	turnsFreezed = 0;
	turnsBenefit = 0;
	benefitSwitch = false;
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
}
int Player::GetWallet() const
{
	return wallet;
}

void Player::SetStepCount(int step)
{
	this->stepCount = step;
}

int Player::GetStepCount() const
{
	return stepCount;
}

void Player::SetTurnCount(int turn)
{
	this->turnCount = turn;
}

int Player::GetTurnCount()
{
	return turnCount;
}

void Player::SetTurnsOwed(int turn)
{
	turnsOwed = turn;
}

int Player::GetTurnsOwed()
{
	return turnsOwed;
}

void Player::SetPlayable(bool play)
{
	playable = play;
}

bool Player::GetPlayable()
{
	return playable;
}

void Player::SetTurnsFreezed(int turn)
{
	turnsFreezed = turn;
}
void Player::SetTurnsBenefit(int turns)
{
	turnsBenefit = turns;
}

int Player::GetTurnsBenefit()
{
	return turnsBenefit;
}

void Player::SetBenefitSwitch(bool switchT)
{
	benefitSwitch = switchT;
}

bool Player::GetBenefitSwitch()
{
	return benefitSwitch;
}

int Player::GetjustRolledDiceNum()
{
	return justRolledDiceNum;
}
int Player::GetPlayernum() const
{
	return playerNum;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);

	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);

	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below

	// == Here are some guideline steps (numbered below) to implement this function ==
	if (this == pGrid->GetBenefitPlayer())
	{
		int turns = this->GetTurnsBenefit();
		this->SetTurnsBenefit(turns - 1);
		if (this->GetTurnsBenefit() == 0)
			this->SetBenefitSwitch(false);
	}

	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	if (diceNumber >= 0)
	{
		turnCount++;

		// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
		//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
		if (turnCount == 3)
		{
			if (turnsFreezed == 0)
				wallet += (diceNumber * 10);
			else
			{
				pGrid->PrintErrorMessage("Your turn has been freezed. Click to continue...");
				turnsFreezed--;
			}
			turnCount = 0;
			return;
		}


		if (wallet <= 0)
		{
			pGrid->PrintErrorMessage("Your wallet has 0 or less coins. You can't move until your wallet is recharged. Click to continue...");
			return;
		}
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = this->GetCell()->GetCellPosition();
	if (playable == false)
	{
		pGrid->PrintErrorMessage("Your turn has been prevented. Click to continue...");
		pos.AddCellNum(0);
		playable = true;
		return;
	}
	else if (turnsFreezed > 0)
	{
		pGrid->PrintErrorMessage("Your turn has been freezed. Click to continue...");
		pos.AddCellNum(0);
		turnsFreezed--;
		return;
	}
	else
		pos.AddCellNum(diceNumber);

	if (pos.GetCellNum() < 1)
	{
		pos.SetHCell(0);
		pos.SetVCell(8);
		pGrid->UpdatePlayerCell(this, pos);
	}
	else
	{
		// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
		//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
		pGrid->UpdatePlayerCell(this, pos);

		// 6- Apply() the game object of the reached cell (if any)

		if (pGrid->GetGameObject(pos) != NULL)
		{
			pGrid->GetGameObject(pos)->Apply(pGrid, this);
		}


		// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
		if (pos.GetCellNum() == 99)
		{
			pGrid->PrintErrorMessage("Player " + to_string(playerNum) + " is the winner with wallet value " + to_string(wallet) + ", click to continue");
			pGrid->SetEndGame(true);
		}

	}
	stepCount = pos.GetCellNum();
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}