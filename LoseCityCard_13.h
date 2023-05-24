#pragma once

class LoseCityCard_13 : public Card
{

public:
	LoseCityCard_13(const CellPosition& pos); // A Constructor takes card position

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of LoseCityCard_13 on the passed Player
													  // by making the player lose the maximum price city

	virtual ~LoseCityCard_13(); // A Virtual Destructor
};