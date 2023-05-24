#pragma once
#include "Card.h"

class PreventCard_4 :public Card
{
public:
	PreventCard_4(const CellPosition pos);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~PreventCard_4();
};

