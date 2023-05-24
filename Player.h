#pragma once

#include "Grid.h"
#include "Cell.h"

class Player
{
	Cell * pCell;		   // pointer to the current Cell of the player

	const int playerNum;   // the player number (from 0 to MaxPlayerCount-1)
	                       // player number does NOT change after construction (const.)

	int stepCount;		   // step count which is the same as his cellNum: from 1 to NumVerticalCells*NumHorizontalCells
	int wallet;		       // player's wallet (how many coins he has -- integer)
	int justRolledDiceNum; // the current dice number which is just rolled by the player
	int turnCount;         // a counter that starts with 0, is incremented with each dice roll
	                       // and reset again when reached 3
	                       // it is used to indicate when to move and when to add to your wallet
	int turnsOwed;			
	bool playable;			// See if the player's turn is preventedd
	int turnsFreezed;		// Number of turns the player will be freezed
	int turnsBenefit;		// Number of turns the player will take the benefit of the owned cities
	bool benefitSwitch;		// Checks to switch the benefit or not
public:

	Player(Cell * pCell, int playerNum); // Constructor making any needed initializations

	// ====== Setters and Getters ======

	void SetCell(Cell * cell);				// A setter for the pCell
	Cell* GetCell() const;					// A getter for the pCell

	void SetWallet(int wallet);				// A setter for the wallet
	int GetWallet() const;					// a getter for the wallet

	void SetStepCount(int step);			// a setter for the StepCount
	int GetStepCount() const;				// a getter for the StepCount

	void SetTurnCount(int turn);			// a setter for the turnCount
	int GetTurnCount();						// A getter for the turnCount

	void SetTurnsOwed(int turn);			// A setter for SetTurnsOwed
	int GetTurnsOwed();						// A getter for SetTurnsOwed

	void SetPlayable(bool play);			// A setter for Playable
	bool GetPlayable();						// A getter for Playable

	void SetTurnsFreezed(int turn);			// A setter for turnsFreezed

	void SetTurnsBenefit(int turns);		// A setter for turnsBenefit
	int GetTurnsBenefit();					// A getter for turnsBenefit

	void SetBenefitSwitch(bool switchT);	// A setter for benefitSwitch
	bool GetBenefitSwitch();				// A getter for benefitSwitch

	int GetPlayernum()const;				// A getter for the Player number
	int GetjustRolledDiceNum();				// A getter for the just rolled dice number
	///TODO: You can add setters and getters for data members here (if needed)

	// ====== Drawing Functions ======

	void Draw(Output* pOut) const;			// Draws the Player's Circle on its current cell

	void ClearDrawing(Output* pOut) const;	// Clears the Player's Circle from its current cell

	// ====== Game Functions ======

	void Move(Grid * pGrid, int diceNumber);	// Moves the Player with the passed diceNumber 
	                                            // and Applies the Game Object's effect (if any) of the end reached cell 
	                                            // for example, if the end cell contains a ladder, take it
	
	void AppendPlayerInfo(string & playersInfo) const; // Appends player's info to the input string, 
	                                                   // for example: P0(wallet, turnCount)

};

