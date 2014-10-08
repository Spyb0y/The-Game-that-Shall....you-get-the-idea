#pragma once
#include <ctime>
#include <sstream>

class Player;

class Enemy
{
public:
	Enemy() : type(0) {}
	Enemy(float health, int damage, int level);
	~Enemy();
	virtual void Attack(Player*){}
	virtual std::stringstream DisplayEnemy(Enemy* enemy);
	virtual int GetEnemyHealth(){ return 0; }
	virtual void SetEnemyHealth(int){};
	virtual int GetEnemyLevel(){ return 0; }
	virtual bool GetIsBoss(){ return false; }
	virtual const int GetEnemyType();
protected:
	bool isDefeated;
	virtual int Sting(int mDamage);
	virtual int Bite(int mDamage);
	virtual int Guard(int mHealth);
	virtual int Regeneration(int mHp);
	virtual int Rage(int mDamage);
	virtual int FlameBreath(int mDamage);
	virtual void Wait();
	//final bosses special attack
	virtual int FireBreath(int mDamage);
	const int type;
};

class ArmoredPhesant : public Enemy
{
public:
	ArmoredPhesant();
	~ArmoredPhesant();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	void Guard();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class Basilisk : public Enemy
{
public:
	Basilisk();
	~Basilisk();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class Crocodile : public Enemy
{
public:
	Crocodile();
	~Crocodile();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class DeviousPenguin : public Enemy
{
public:
	DeviousPenguin();
	~DeviousPenguin();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class Dragon : public Enemy
{
public:
	Dragon();
	~Dragon();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

//Boss
class HornetQueen : public Enemy
{
public:
	HornetQueen();
	~HornetQueen();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

//Boss
class Gargoyle : public Enemy
{
public:
	Gargoyle();
	~Gargoyle();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class GiantBeetle : public Enemy
{
public:
	GiantBeetle();
	~GiantBeetle();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class GiantEagle : public Enemy
{
public:
	GiantEagle();
	~GiantEagle();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class GiantRat : public Enemy
{
public:
	GiantRat();
	~GiantRat();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	void Bite();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class GiantWasp : public Enemy
{
public:
	GiantWasp();
	~GiantWasp();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	void Sting();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class Gorgon : public Enemy
{
public:
	Gorgon();
	~Gorgon();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

//Boss
class Minotaur : public Enemy
{
public:
	Minotaur();
	~Minotaur();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class Ogre : public Enemy
{
public:
	Ogre();
	~Ogre();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class Pheasent : public Enemy
{
public:
	Pheasent();
	~Pheasent();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class RadDragon : public Enemy
{
public:
	RadDragon();
	~RadDragon();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class Rat : public Enemy
{
public:
	Rat();
	~Rat();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	int mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class StoneGolem : public Enemy
{
public:
	StoneGolem();
	~StoneGolem();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

//Boss
class StoneGuardian : public Enemy
{
public:
	StoneGuardian();
	~StoneGuardian();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class TheKing’sRoyalGuard : public Enemy
{
public:
	TheKing’sRoyalGuard();
	~TheKing’sRoyalGuard();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

//Boss
class TheStalker : public Enemy
{
public:
	TheStalker();
	~TheStalker();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class Troll : public Enemy
{
public:
	Troll();
	~Troll();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};

class WarHound : public Enemy
{
public:
	WarHound();
	~WarHound();
	void Attack(Player*);
	//std::stringstream DisplayEnemy(Enemy* enemy);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
	const int GetEnemyType();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	const int type;
};



