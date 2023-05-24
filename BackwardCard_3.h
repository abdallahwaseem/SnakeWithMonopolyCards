#pragma once
#include "Card.h"
#include"Grid.h"
class BackwardCard_3 : public Card
{
	
public:
	BackwardCard_3(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);	// Applys the function of BackwardCard_3 which move backward the other players
														// the same number of the just rolled dice of the current player
	virtual ~BackwardCard_3(); // A Virtual Destructor
};
