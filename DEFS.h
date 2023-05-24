#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		 // Add Ladder Action
	ADD_SNAKE,		 // Add Snake Action
	ADD_COIN_SET,  // Add Coin Set Action
	ADD_CARD,		 // Add Card Action
	COPY_CARDorCOIN,  // Copy Card or Coin Action
	CUT_CARDorCOIN,	  // Cut Card or Coin Action
	PASTE,				// Paste Card or Coin Action
	DELETE_GAME_OBJ,  // Delete game object Action
	SAVE_GRID,		 // Save Info of Designed Grid
	OPEN_GRID,		// Open a Saved Grid
	EXIT,			 // Exit Application
    TO_PLAY_MODE,	 // Go to Play Mode

	///TODO: Add more action types of Design Mode
	//DONE

	//  [2] Actions of Play Mode

	ROLL_DICE,		 // Roll Dice Action
	INPUT_DICE_VALUE,// Input dice value
	OFFER_MORTGAGE,	 //  Offer City for Mortgage
	ACCEPT_MORTGAGE, //	Accept Mortgage
	RETURN_MORTGAGE, // Return Mortgaged City
	SELL_CITY,		 // Sell Owned City
	NEW_GAME,		 // Start a new game
	TO_DESIGN_MODE,	 // Go to Design Mode
	//EXIT,			 // Exit Application

	///TODO: Add more action types of Play Mode
	//DONE

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif