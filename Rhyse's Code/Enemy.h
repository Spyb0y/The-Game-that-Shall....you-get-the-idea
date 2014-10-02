#pragma once
#include <ctime>

class Player;

class Enemy
{
public:
	Enemy(){}
	Enemy(float health, int damage, int level);
	~Enemy();
	virtual void Attack(Player*){}
	virtual int GetEnemyHealth(){ return 0; }
	virtual void SetEnemyHealth(int){};
	virtual int GetEnemyLevel(){ return 0; }
	virtual bool GetIsBoss(){ return false; }
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

};

class ArmoredPhesant : public Enemy
{
public:
	ArmoredPhesant();
	~ArmoredPhesant();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	void Guard();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;

};

class Basilisk : public Enemy
{
public:
	Basilisk();
	~Basilisk();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class Crocodile : public Enemy
{
public:
	Crocodile();
	~Crocodile();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class DeviousPenguin : public Enemy
{
public:
	DeviousPenguin();
	~DeviousPenguin();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class Dragon : public Enemy
{
public:
	Dragon();
	~Dragon();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

//Boss
class HornetQueen : public Enemy
{
public:
	HornetQueen();
	~HornetQueen();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

//Boss
class Gargoyle : public Enemy
{
public:
	Gargoyle();
	~Gargoyle();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class GiantBeetle : public Enemy
{
public:
	GiantBeetle();
	~GiantBeetle();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class GiantEagle : public Enemy
{
public:
	GiantEagle();
	~GiantEagle();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class GiantRat : public Enemy
{
public:
	GiantRat();
	~GiantRat();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	void Bite();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class GiantWasp : public Enemy
{
public:
	GiantWasp();
	~GiantWasp();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	void Sting();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
};

class Gorgon : public Enemy
{
public:
	Gorgon();
	~Gorgon();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

//Boss
class Minotaur : public Enemy
{
public:
	Minotaur();
	~Minotaur();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class Ogre : public Enemy
{
public:
	Ogre();
	~Ogre();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class Pheasent : public Enemy
{
public:
	Pheasent();
	~Pheasent();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class RadDragon : public Enemy
{
public:
	RadDragon();
	~RadDragon();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class Rat : public Enemy
{
public:
	Rat();
	~Rat();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	int mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class StoneGolem : public Enemy
{
public:
	StoneGolem();
	~StoneGolem();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

//Boss
class StoneGuardian : public Enemy
{
public:
	StoneGuardian();
	~StoneGuardian();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class TheKing’sRoyalGuard : public Enemy
{
public:
	TheKing’sRoyalGuard();
	~TheKing’sRoyalGuard();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

//Boss
class TheStalker : public Enemy
{
public:
	TheStalker();
	~TheStalker();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class Troll : public Enemy
{
public:
	Troll();
	~Troll();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};

class WarHound : public Enemy
{
public:
	WarHound();
	~WarHound();
	void Attack(Player*);
	int GetEnemyHealth();
	void SetEnemyHealth(int);
	int GetEnemyLevel();
	bool GetIsBoss();
protected:
	float mHealth;
	float mDamage;
	const int MIN_HIT;
	const int MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	bool isBoss;
	//Skill pointer to the skill class
};



