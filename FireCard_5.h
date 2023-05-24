#pragma once
#include "Card.h"
#include "GameObject.h"

class FireCard_5 : public Card
{

public:
	FireCard_5(const CellPosition& pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~FireCard_5();
	
};
