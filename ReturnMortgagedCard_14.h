#pragma once
#include"Card.h"
class ReturnMortgagedCard_14 : public Card
{

	public:
		ReturnMortgagedCard_14(const CellPosition& pos); // A Constructor takes card position

		virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of ReturnMortgagedCard_14 on the passed Player
	
		virtual ~ReturnMortgagedCard_14(); // A Virtual Destructor

};

