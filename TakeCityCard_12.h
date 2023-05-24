#pragma once
#include "Card.h"

class TakeCityCard_12 : public Card
{
	

public:
	TakeCityCard_12(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of TakeCityCard_12 on the passed Player
													  // by enabling the player to choose one city

	virtual ~TakeCityCard_12(); // A Virtual Destructor
};