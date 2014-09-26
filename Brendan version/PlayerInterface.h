#pragma once

class PlayerInterface
{
public:
	PlayerInterface();
	~PlayerInterface();
	void BattlePhase();
	void PostBattlePhase();
	void PlaceTile();
	void Update(float dt);

protected:
	int choice;
	bool Equip;
	bool Remove;
};

