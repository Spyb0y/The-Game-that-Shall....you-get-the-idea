#pragma once

class Enemy
{
public:
	Enemy(){}
	Enemy(float health, float damage, int level);
	~Enemy();
	virtual void Attack(){}
protected:
	bool isDefeated;

};

class ArmoredPhesant : public Enemy
{
public:
	ArmoredPhesant();
	~ArmoredPhesant();
	void Attack();
	void Guard();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	
};

class Basilisk : public Enemy
{
public:
	Basilisk();
	~Basilisk();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class Crocodile : public Enemy
{
public:
	Crocodile();
	~Crocodile();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class DeviousPenguin : public Enemy
{
public:
	DeviousPenguin();
	~DeviousPenguin();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class Dragon : public Enemy
{
public:
	Dragon();
	~Dragon();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

//Boss
class HornetQueen : public Enemy
{
public:
	HornetQueen();
	~HornetQueen();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

//Boss
class Gargoyle : public Enemy
{
public:
	Gargoyle();
	~Gargoyle();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class GiantBeetle : public Enemy
{
public:
	GiantBeetle();
	~GiantBeetle();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class GiantEagle : public Enemy
{
public:
	GiantEagle();
	~GiantEagle();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class GiantRat : public Enemy
{
public:
	GiantRat();
	~GiantRat();
	void Attack();
	void Bite();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class GiantWasp : public Enemy
{
public:
	GiantWasp();
	~GiantWasp();
	void Attack();
	void Sting();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
};

class Gorgon : public Enemy
{
public:
	Gorgon();
	~Gorgon();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

//Boss
class Minotaur : public Enemy
{
public:
	Minotaur();
	~Minotaur();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class Ogre : public Enemy
{
public:
	Ogre();
	~Ogre();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class Pheasent : public Enemy
{
public:
	Pheasent();
	~Pheasent();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class RadDragon : public Enemy
{
public:
	RadDragon();
	~RadDragon();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class Rat : public Enemy
{
public:
	Rat();
	~Rat();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class StoneGolem : public Enemy
{
public:
	StoneGolem();
	~StoneGolem();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

//Boss
class StoneGuardian : public Enemy
{
public:
	StoneGuardian();
	~StoneGuardian();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class TheKing’sRoyalGuard : public Enemy
{
public:
	TheKing’sRoyalGuard();
	~TheKing’sRoyalGuard();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

//Boss
class TheStalker : public Enemy
{
public:
	TheStalker();
	~TheStalker();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	//Skill pointer to the skill class
};

class Troll : public Enemy
{
public:
	Troll();
	~Troll();
	void Attack();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};

class WarHound : public Enemy
{
public:
	WarHound();
	~WarHound();
	void Attack();
	void Bite();
protected:
	float mHealth;
	float mDamage;
	const float MIN_HIT;
	const float MAX_HIT;
	//Terrain pointer to terrain class
	int mLevel;
	//Skill pointer to the skill class
};



