#include "Grid.h"
#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include "Card.h"
#include "Player.h"
#include"Snake.h"
#include"CoinSet.h"
#include "CairoCard_7.h"
#include "AlexCard_8.h"
#include "AswanCard_9.h"
#include "LuxorCard_10.h"
#include "HurghadaCard_11.h"
#include "TakeCityCard_12.h"
#include "LoseCityCard_13.h"
Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;

	// Initialize OfferPos with NULL
	OfferedPos = NULL;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetClipboard(CoinSet* c)
{
	cClipboard = c;
}
CoinSet* Grid::GetcClipboard() const
{
	return cClipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

GameObject* Grid::GetGameObject(CellPosition a)
{
	int v = a.VCell();
	int h = a.HCell();
	return CellList[v][h]->GetGameObject();
}

Player* Grid::GetPlayerFromPos(CellPosition a)
{
	int v = a.VCell();
	int h = a.HCell();
	int check = 0;
	int position = -1;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		int V = PlayerList[i]->GetCell()->GetCellPosition().VCell();
		int H = PlayerList[i]->GetCell()->GetCellPosition().HCell();
		if (V == v && H == h)
		{
			position = i;
			check++;
			if (check > 1)
				return NULL;
		}
	}
	if (check == 1)
		return PlayerList[position];
	else
		return NULL;
}

Card* Grid::GetHighestPriceCity(Grid* pGrid, Player* pPlayer)
{
	int max = 0;
	Card* pMaxCard = NULL;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CairoCard_7* card = dynamic_cast<CairoCard_7*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() > max)
					{
						max = card->GetPrice();
						pMaxCard = card;
					}

				}
			}
			if (AlexCard_8* card = dynamic_cast<AlexCard_8*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() > max)
					{
						max = card->GetPrice();
						pMaxCard = card;
					}

				}
			}
			if (AswanCard_9* card = dynamic_cast<AswanCard_9*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() > max)
					{
						max = card->GetPrice();
						pMaxCard = card;
					}

				}
			}
			if (LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() > max)
					{
						max = card->GetPrice();
						pMaxCard = card;
					}

				}
			}
			if (HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() > max)
					{
						max = card->GetPrice();
						pMaxCard = card;
					}

				}
			}
		}
	}
	return pMaxCard;
}
Card* Grid::GetLowestPriceCity(Grid* pGrid, Player* pPlayer)
{
	int min = 99999999999;
	Card* pMinCard = NULL;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CairoCard_7* card = dynamic_cast<CairoCard_7*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() < min)
					{
						min = card->GetPrice();
						pMinCard = card;
					}

				}
			}
			if (AlexCard_8* card = dynamic_cast<AlexCard_8*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() < min)
					{
						min = card->GetPrice();
						pMinCard = card;
					}

				}
			}
			if (AswanCard_9* card = dynamic_cast<AswanCard_9*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() < min)
					{
						min = card->GetPrice();
						pMinCard = card;
					}

				}
			}
			if (LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() < min)
					{
						min = card->GetPrice();
						pMinCard = card;
					}

				}
			}
			if (HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
				{
					if (card->GetPrice() < min)
					{
						min = card->GetPrice();
						pMinCard = card;
					}

				}
			}
		}
	}
	return pMinCard;
}

void Grid::SetAllOwnerCairoCard_7(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CairoCard_7* card = dynamic_cast<CairoCard_7*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetOwner(Owner);
		}
	}
}
void Grid::SetAllSubOwnerCairoCard_7(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CairoCard_7* card = dynamic_cast<CairoCard_7*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetSubOwner(Owner);
		}
	}
}

void Grid::SetAllOwnerAlexCard_8(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			AlexCard_8* card = dynamic_cast<AlexCard_8*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetOwner(Owner);
		}
	}
}
void Grid::SetAllSubOwnerAlexCard_8(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			AlexCard_8* card = dynamic_cast<AlexCard_8*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetSubOwner(Owner);
		}
	}
}
void Grid::SetAllOwnerAswanCard_9(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			AswanCard_9* card = dynamic_cast<AswanCard_9*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetOwner(Owner);
		}
	}
}
void Grid::SetAllSubOwnerAswanCard_9(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			AswanCard_9* card = dynamic_cast<AswanCard_9*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetSubOwner(Owner);
		}
	}
}

void Grid::SetAllOwnerLuxorCard_10(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetOwner(Owner);
		}
	}
}
void Grid::SetAllSubOwnerLuxorCard_10(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetSubOwner(Owner);
		}
	}
}

void Grid::SetAllOwnerHurghadaCard_11(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetOwner(Owner);
		}
	}
}
void Grid::SetAllSubOwnerHurghadaCard_11(Player* Owner)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(CellList[i][j]->GetGameObject());
			if (card)
				card->SetSubOwner(Owner);
		}
	}
}

Card* Grid::GetFirstCairoCard_7()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			CairoCard_7* card = dynamic_cast<CairoCard_7*>(CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}

Card* Grid::GetFirstAlexCard_8()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			AlexCard_8* card = dynamic_cast<AlexCard_8*>(CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}

Card* Grid::GetFirstAswanCard_9()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			AswanCard_9* card = dynamic_cast<AswanCard_9*>(CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}

Card* Grid::GetFirstLuxorCard_10()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}

Card* Grid::GetFirstHurghadaCard_11()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(CellList[i][j]->GetGameObject());
			if (card)
				return card;
		}
	}
	return NULL;
}

// ========= Other Getters =========


Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder* Grid::GetNextLadder(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasLadder() != NULL)
			{
				return CellList[i][j]->HasLadder();
			}

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}


Card* Grid::GetNextCard(const CellPosition& position)
{
	int startH = position.HCell() + 1;
	for (int i = position.VCell(); i >= 0; i--)
	{
		for (int j = startH; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasCard() != NULL)
			{
				return CellList[i][j]->HasCard();
			}
		}
		startH = 0;
	}
	return NULL;
}
Snake* Grid::GetNextSnake(const CellPosition& position)
{
	int startH = position.HCell();
	for (int i = position.VCell(); i >= 0; i--)
	{
		for (int j = startH; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasSnake() != NULL)
			{
				return CellList[i][j]->HasSnake();
			}
		}
		startH = 0;
	}
	return NULL;
}
CoinSet* Grid::GetNextCoinSet(const CellPosition& position)
{
	int startH = position.HCell();
	for (int i = position.VCell(); i >= 0; i--)
	{
		for (int j = startH; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasCoinSet() != NULL)
			{
				return CellList[i][j]->HasCoinSet();
			}
		}
		startH = 0;
	}
	return NULL;
}

void Grid::setclipboardcheck(int a)
{
	clipboardcheck = a;
}
int Grid::getclipboardcheck()
{
	return clipboardcheck;
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		///TODO: Add the code that draws the CoinSet game objects

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}

void Grid::fire(Player* p, CellPosition newp, int vc, int hc)
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		int v = PlayerList[i]->GetCell()->GetCellPosition().VCell();
		int h = PlayerList[i]->GetCell()->GetCellPosition().HCell();
		if ((PlayerList[i]->GetPlayernum() != (p->GetPlayernum())) && (v == vc || h == hc))
		{
			UpdatePlayerCell(PlayerList[i], newp);
		}
	}
}

int Grid::numberofgameobjects(int a)
{
	int count = 0;
	if (a == 1)
	{
		for (int i = 1; i <= 99; i++)
		{
			CellPosition a = CellPosition::GetCellPositionFromNum(i);
			GameObject* p = GetGameObject(a);
			Card* ptr = dynamic_cast<Card*>(p);
			if (ptr != NULL)
			{
				count++;
			}
		}
	}
	else if (a == 2)
	{
		for (int i = 1; i <= 99; i++)
		{
			CellPosition a = CellPosition::GetCellPositionFromNum(i);
			GameObject* p = GetGameObject(a);
			Ladder* ptr = dynamic_cast<Ladder*>(p);
			if (ptr != NULL)
			{
				count++;
			}
		}
	}
	else if (a == 3)
	{
		for (int i = 1; i <= 99; i++)
		{
			CellPosition a = CellPosition::GetCellPositionFromNum(i);
			GameObject* p = GetGameObject(a);
			CoinSet* ptr = dynamic_cast<CoinSet*>(p);
			if (ptr != NULL)
			{
				count++;
			}
		}
	}
	else if (a == 4)
	{
		for (int i = 1; i <= 99; i++)
		{
			CellPosition a = CellPosition::GetCellPositionFromNum(i);
			GameObject* p = GetGameObject(a);
			Snake* ptr = dynamic_cast<Snake*>(p);
			if (ptr != NULL)
			{
				count++;
			}
		}
	}
	return count;
}


void Grid::SaveAll(ofstream& OutFile, int a)
{
	if (a == 1)
	{
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				GameObject* p = CellList[i][j]->GetGameObject();
				if (p != NULL)
				{
					int s = p->getsave();
					if (s == a)
						p->Save(OutFile, a);
				}
			}
		}
	}
	else if (a == 2)
	{
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				GameObject* p = CellList[i][j]->GetGameObject();
				if (p != NULL)
				{
					int s = p->getsave();
					if (s == a)
						p->Save(OutFile, a);
				}
			}
		}
	}
	else if (a == 3)
	{
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				GameObject* p = CellList[i][j]->GetGameObject();
				if (p != NULL)
				{
					int s = p->getsave();
					if (s == a)
						p->Save(OutFile, a);
				}
			}
		}
	}
	else if (a == 4)
	{
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				GameObject* p = CellList[i][j]->GetGameObject();
				if (p != NULL)
				{
					int s = p->getsave();
					if (s == a)
						p->Save(OutFile, a);
				}
			}
		}
	}
	return;
}

int Grid::numladders()
{
	int c = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			GameObject* p = CellList[i][j]->HasLadder();
			if (p != NULL)
			{
				c++;
			}
		}
	}
	return c;
}
int Grid::numsnakes()
{
	int c = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			GameObject* p = CellList[i][j]->HasSnake();
			if (p != NULL)
			{
				c++;
			}
		}
	}
	return c;
}
int Grid::numcards()
{
	int c = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			GameObject* p = CellList[i][j]->HasCard();
			if (p != NULL)
			{
				c++;
			}
		}
	}
	return c;
}
int Grid::numcoinsets()
{
	int c = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			GameObject* p = CellList[i][j]->HasCoinSet();
			if (p != NULL)
			{
				c++;
			}
		}
	}
	return c;
}
void Grid::PlayerListLoop(Grid* pGrid, Player* pPlayer)
{
	int k = pGrid->GetCurrentPlayer()->GetjustRolledDiceNum();
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (PlayerList[i] != pPlayer)
		{
			PlayerList[i]->Move(pGrid, -k);
			Ladder* l = PlayerList[i]->GetCell()->HasLadder();
			Card* ca = PlayerList[i]->GetCell()->HasCard();
			Snake* s = PlayerList[i]->GetCell()->HasSnake();
			CoinSet* c = PlayerList[i]->GetCell()->HasCoinSet();
			if (l)
				l->Apply(pGrid, PlayerList[i]);
			if (ca)
				ca->Apply(pGrid, PlayerList[i]);
			if (s)
				s->Apply(pGrid, PlayerList[i]);
			if (c)
				c->Apply(pGrid, PlayerList[i]);
		}
	}
}

void Grid::PLayerListFreeze(Grid* pGrid, Player* pPlayer, int NumberOfTurnsFreezed, bool Even)
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (PlayerList[i] != pPlayer)
		{
			if (Even)
			{
				if (PlayerList[i]->GetStepCount() % 2 == 0)
					PlayerList[i]->SetTurnsFreezed(NumberOfTurnsFreezed);
			}
			else
			{
				if (PlayerList[i]->GetStepCount() % 2 != 0)
					PlayerList[i]->SetTurnsFreezed(NumberOfTurnsFreezed);
			}
		}
	}
}

Player* Grid::GetBenefitPlayer()
{
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (PlayerList[i]->GetBenefitSwitch() == true)
			return PlayerList[i];
	}
	return NULL;
}

void Grid::StartNewGame()
{
	const CellPosition start(8, 0);
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i]->SetWallet(100);
		PlayerList[i]->SetTurnCount(0);
		PlayerList[i]->SetStepCount(1);
		PlayerList[i]->SetPlayable(true);
		PlayerList[i]->SetBenefitSwitch(false);
		PlayerList[i]->SetTurnsBenefit(0);
		PlayerList[i]->SetTurnsFreezed(0);
		UpdatePlayerCell(PlayerList[i], start);
	}
	currPlayerNumber = 0;
	endGame = false;

	SetAllOwnerCairoCard_7(NULL);
	SetAllSubOwnerCairoCard_7(NULL);
	SetAllOwnerAlexCard_8(NULL);
	SetAllSubOwnerAlexCard_8(NULL);
	SetAllOwnerAswanCard_9(NULL);
	SetAllSubOwnerAswanCard_9(NULL);
	SetAllOwnerLuxorCard_10(NULL);
	SetAllSubOwnerLuxorCard_10(NULL);
	SetAllOwnerHurghadaCard_11(NULL);
	SetAllSubOwnerHurghadaCard_11(NULL);
}

bool Grid::PlayerHasCities(Player* pPlayer)
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CairoCard_7* card = dynamic_cast<CairoCard_7*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
					return true;
			}
			if (AlexCard_8* card = dynamic_cast<AlexCard_8*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
					return true;
			}
			if (AswanCard_9* card = dynamic_cast<AswanCard_9*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
					return true;
			}
			if (LuxorCard_10* card = dynamic_cast<LuxorCard_10*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
					return true;
			}
			if (HurghadaCard_11* card = dynamic_cast<HurghadaCard_11*>(CellList[i][j]->GetGameObject()))
			{
				if (card->GetOwner() == pPlayer)
					return true;
			}
		}
		return false;
	}
}
void Grid::SetOfferedPos(string* p, int a)
{
	OfferedPos = new string[a];
	for (size_t i = 0; i < a; i++)
	{
		OfferedPos[i] = p[i];
	}
}
string* Grid::GetOfferedPos()
{
	return OfferedPos;
}
Player* Grid::WinnerPlayer()
{
	int maxWallet = 0;
	int playerCounter = 0;
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		int walletChecker = PlayerList[i]->GetWallet();
		if (walletChecker >maxWallet)
			maxWallet = walletChecker;
	}
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		if (PlayerList[i]->GetWallet() == maxWallet)
			playerCounter++;
	}
	if (playerCounter >1)
	{
		int maxStepCount = 0;
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			int stepCountChecker = PlayerList[i]->GetStepCount();
			if (stepCountChecker > maxStepCount)
				maxStepCount = stepCountChecker;
		}
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			if (PlayerList[i]->GetStepCount() == maxStepCount && PlayerList[i]->GetWallet() == maxWallet)
			{
				return PlayerList[i];
		
			}
		}
	}
	else if(playerCounter == 1)
	{
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			if (PlayerList[i]->GetWallet() == maxWallet)
			{
				return PlayerList[i];
	
			}
		}
	}
}


void Grid::DeleteAll()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			GameObject* a = NULL;
			a = CellList[i][j]->GetGameObject();
			if (a != NULL)
			{
				CellPosition a = CellList[i][j]->GetCellPosition();
				RemoveObjectFromCell(a);
			}
		}
	}
}
int Grid::GetNumOfOfferedCities()
{
	return NumOfOfferedCities;
}
void Grid::SetNumOfOfferedCities(int s)
{
	 NumOfOfferedCities=s;
}
