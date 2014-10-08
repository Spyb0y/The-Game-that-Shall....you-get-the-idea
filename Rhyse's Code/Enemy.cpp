#include <sstream>
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(float health, int damage, int level) : type(0)
{

}

Enemy::~Enemy()
{
}

const int Enemy::GetEnemyType()
{
	return type;
}

ArmoredPhesant::ArmoredPhesant() :
MAX_HIT(25),
MIN_HIT(5),
type(1)
{
	mHealth = 15;
	mDamage = 3;
	mLevel = 2;
	isBoss = false;
}

void ArmoredPhesant::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (randSkill < 50)
	{
		ArmoredPhesant::SetEnemyHealth(Enemy::Guard(mHealth));
	}
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int ArmoredPhesant::GetEnemyHealth()
{
	return mHealth;
}

void ArmoredPhesant::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int ArmoredPhesant::GetEnemyLevel()
{
	return mLevel;
}

bool ArmoredPhesant::GetIsBoss()
{
	return isBoss;
}

const int ArmoredPhesant::GetEnemyType()
{
	return type;
}

Basilisk::Basilisk() :
MAX_HIT(15),
MIN_HIT(5),
type(2)
{
	mHealth = 60;
	mDamage = 4;
	mLevel = 5;
	isBoss = false;
}

void Basilisk::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		if (randSkill < 30)
		{
			Basilisk::Attack(mHero);
		}
		else
		{
			return;
		}
	}
}

int Basilisk::GetEnemyHealth()
{
	return mHealth;
}

void Basilisk::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Basilisk::GetEnemyLevel()
{
	return mLevel;
}

bool Basilisk::GetIsBoss()
{
	return isBoss;
}

const int Basilisk::GetEnemyType()
{
	return type;
}

Crocodile::Crocodile() :
MAX_HIT(25),
MIN_HIT(6),
type(3)
{
	mHealth = 20;
	mDamage = 5;
	mLevel = 4;
	isBoss = false;
}

void Crocodile::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int skillRand = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		if (skillRand < 40)
		{
			playerHealth = playerHealth - Enemy::Bite(mDamage);
		}
		else
		{
			playerHealth = playerHealth - mDamage;
		}
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int Crocodile::GetEnemyHealth()
{
	return mHealth;
}

void Crocodile::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Crocodile::GetEnemyLevel()
{
	return mLevel;
}

bool Crocodile::GetIsBoss()
{
	return isBoss;
}

const int Crocodile::GetEnemyType()
{
	return type;
}

DeviousPenguin::DeviousPenguin() :
MAX_HIT(2),
MIN_HIT(1),
type(4)
{
	mHealth = 10;
	mDamage = 1;
	mLevel = 4;
	isBoss = false;
}

void DeviousPenguin::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int DeviousPenguin::GetEnemyHealth()
{
	return mHealth;
}

void DeviousPenguin::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int DeviousPenguin::GetEnemyLevel()
{
	return mLevel;
}

bool DeviousPenguin::GetIsBoss()
{
	return isBoss;
}

const int DeviousPenguin::GetEnemyType()
{
	return type;
}

Dragon::Dragon() :
MAX_HIT(30),
MIN_HIT(6),
type(5)
{
	mHealth = 50;
	mDamage = 7;
	mLevel = 5;
	isBoss = false;
}

void Dragon::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		if (randSkill < 10)
		{
			playerHealth = playerHealth - Enemy::FlameBreath(mDamage);
		}
		else
		{
			playerHealth = playerHealth - mDamage;
		}
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int Dragon::GetEnemyHealth()
{
	return mHealth;
}

void Dragon::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Dragon::GetEnemyLevel()
{
	return mLevel;
}

bool Dragon::GetIsBoss()
{
	return isBoss;
}

const int Dragon::GetEnemyType()
{
	return type;
}

//Boss
HornetQueen::HornetQueen() :
MAX_HIT(50),
MIN_HIT(5),
type(6)
{
	mHealth = 100;
	mDamage = 25;
	mLevel = 4;
	isBoss = true;
}

void HornetQueen::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int HornetQueen::GetEnemyHealth()
{
	return mHealth;
}

void HornetQueen::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int HornetQueen::GetEnemyLevel()
{
	return mLevel;
}

bool HornetQueen::GetIsBoss()
{
	return isBoss;
}

const int HornetQueen::GetEnemyType()
{
	return type;
}

//Boss
Gargoyle::Gargoyle() :
MAX_HIT(50),
MIN_HIT(1),
type(7)
{
	mHealth = 75;
	mDamage = 20;
	mLevel = 3;
	isBoss = false;
}

void Gargoyle::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}


int Gargoyle::GetEnemyHealth()
{
	return mHealth;
}

void Gargoyle::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Gargoyle::GetEnemyLevel()
{
	return mLevel;
}

bool Gargoyle::GetIsBoss()
{
	return isBoss;
}

const int Gargoyle::GetEnemyType()
{
	return type;
}

GiantBeetle::GiantBeetle() :
MAX_HIT(20),
MIN_HIT(0),
type(8)
{
	mHealth = 4;
	mDamage = 1;
	mLevel = 1;
	isBoss = false;
}

void GiantBeetle::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int GiantBeetle::GetEnemyHealth()
{
	return mHealth;
}

void GiantBeetle::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int GiantBeetle::GetEnemyLevel()
{
	return mLevel;
}

bool GiantBeetle::GetIsBoss()
{
	return isBoss;
}

const int GiantBeetle::GetEnemyType()
{
	return type;
}

GiantEagle::GiantEagle() :
MAX_HIT(20),
MIN_HIT(6),
type(9)
{
	mHealth = 20;
	mDamage = 6;
	mLevel = 4;
	isBoss = false;
}

void GiantEagle::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int skillRand = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		if (skillRand < 20)
		{
			GiantEagle::Attack(mHero);
		}
		else
		{
			return;
		}
	}
}

int GiantEagle::GetEnemyHealth()
{
	return mHealth;
}

void GiantEagle::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int GiantEagle::GetEnemyLevel()
{
	return mLevel;
}

bool GiantEagle::GetIsBoss()
{
	return isBoss;
}

const int GiantEagle::GetEnemyType()
{
	return type;
}

GiantRat::GiantRat() :
MAX_HIT(25),
MIN_HIT(5),
type(10)
{
	mHealth = 10;
	mDamage = 3;
	mLevel = 2;
	isBoss = false;
}

void GiantRat::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		if (randSkill < 50)
		{
			playerHealth = playerHealth - Enemy::Bite(mDamage);
		}
		else
		{
			playerHealth = playerHealth - mDamage;
		}
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int GiantRat::GetEnemyHealth()
{
	return mHealth;
}

void GiantRat::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int GiantRat::GetEnemyLevel()
{
	return mLevel;
}

bool GiantRat::GetIsBoss()
{
	return isBoss;
}

const int GiantRat::GetEnemyType()
{
	return type;
}

GiantWasp::GiantWasp() :
MAX_HIT(25),
MIN_HIT(8),
type(11)
{
	mHealth = 14;
	mDamage = 1;
	mLevel = 2;
	isBoss = false;
}

void GiantWasp::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		if (randSkill < 45)
		{
			playerHealth = playerHealth - Enemy::Sting(mDamage);
		}
		else
		{
			playerHealth = playerHealth - mDamage;
		}
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int GiantWasp::GetEnemyHealth()
{
	return mHealth;
}

void GiantWasp::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int GiantWasp::GetEnemyLevel()
{
	return mLevel;
}

bool GiantWasp::GetIsBoss()
{
	return isBoss;
}

const int GiantWasp::GetEnemyType()
{
	return type;
}


Gorgon::Gorgon() :
MAX_HIT(40),
MIN_HIT(4),
type(12)
{
	mHealth = 25;
	mDamage = 5;
	mLevel = 3;
	isBoss = false;
}

void Gorgon::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		if (randSkill < 15)
		{
			Gorgon::Attack(mHero);
		}
		else
		{
			return;
		}
	}
}

int Gorgon::GetEnemyHealth()
{
	return mHealth;
}

void Gorgon::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Gorgon::GetEnemyLevel()
{
	return mLevel;
}

bool Gorgon::GetIsBoss()
{
	return isBoss;
}

const int Gorgon::GetEnemyType()
{
	return type;
}

//Boss
Minotaur::Minotaur() :
MAX_HIT(25),
MIN_HIT(1),
type(13)
{
	mHealth = 30;
	mDamage = 10;
	mLevel = 1;
	isBoss = true;
}

void Minotaur::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int Minotaur::GetEnemyHealth()
{
	return mHealth;
}

void Minotaur::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Minotaur::GetEnemyLevel()
{
	return mLevel;
}

bool Minotaur::GetIsBoss()
{
	return isBoss;
}

const int Minotaur::GetEnemyType()
{
	return type;
}

Ogre::Ogre() :
MAX_HIT(30),
MIN_HIT(6),
type(14)
{
	mHealth = 30;
	mDamage = 6;
	mLevel = 5;
	isBoss = false;
}

void Ogre::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		if (randSkill < 15)
		{
			playerHealth = playerHealth - Enemy::Rage(mDamage);
		}
		else
		{
			playerHealth = playerHealth - mDamage;
		}
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int Ogre::GetEnemyHealth()
{
	return mHealth;
}

void Ogre::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Ogre::GetEnemyLevel()
{
	return mLevel;
}

bool Ogre::GetIsBoss()
{
	return isBoss;
}

const int Ogre::GetEnemyType()
{
	return type;
}

Pheasent::Pheasent() :
MAX_HIT(20),
MIN_HIT(0),
type(15)
{
	mHealth = 10;
	mDamage = 2;
	mLevel = 1;
	isBoss = false;
}

void Pheasent::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int Pheasent::GetEnemyHealth()
{
	return mHealth;
}

void Pheasent::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Pheasent::GetEnemyLevel()
{
	return mLevel;
}

bool Pheasent::GetIsBoss()
{
	return isBoss;
}

const int Pheasent::GetEnemyType()
{
	return type;
}

//Boss
RadDragon::RadDragon() :
MAX_HIT(80),
MIN_HIT(10),
type(16)
{
	mHealth = 150;
	mDamage = 25;
	mLevel = 5;
	isBoss = true;
}

void RadDragon::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		if (randSkill < 15)
		{
			playerHealth = playerHealth - Enemy::FireBreath(mDamage);
		}
		else
		{
			playerHealth = playerHealth - mDamage;
		}
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int RadDragon::GetEnemyHealth()
{
	return mHealth;
}

void RadDragon::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int RadDragon::GetEnemyLevel()
{
	return mLevel;
}

bool RadDragon::GetIsBoss()
{
	return isBoss;
}

const int RadDragon::GetEnemyType()
{
	return type;
}

Rat::Rat() :
MAX_HIT(20),
MIN_HIT(0),
type(17)
{
	mHealth = 5;
	mDamage = 2;
	mLevel = 1;
	isBoss = false;
}

void Rat::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int Rat::GetEnemyHealth()
{
	return mHealth;
}

void Rat::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Rat::GetEnemyLevel()
{
	return mLevel;
}

bool Rat::GetIsBoss()
{
	return isBoss;
}

const int Rat::GetEnemyType()
{
	return type;
}

StoneGolem::StoneGolem() :
MAX_HIT(15),
MIN_HIT(5),
type(18)
{
	mHealth = 40;
	mDamage = 3;
	mLevel = 3;
	isBoss = false;
}

void StoneGolem::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	if (randSkill < 50)
	{
		StoneGolem::SetEnemyHealth(Enemy::Guard(mHealth));
	}
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int StoneGolem::GetEnemyHealth()
{
	return mHealth;
}

void StoneGolem::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int StoneGolem::GetEnemyLevel()
{
	return mLevel;
}

bool StoneGolem::GetIsBoss()
{
	return isBoss;
}

const int StoneGolem::GetEnemyType()
{
	return type;
}

//Boss
StoneGuardian::StoneGuardian() :
MAX_HIT(30),
MIN_HIT(1),
type(19)
{
	mHealth = 50;
	mDamage = 15;
	mLevel = 2;
	isBoss = true;
}

void StoneGuardian::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int StoneGuardian::GetEnemyHealth()
{
	return mHealth;
}

void StoneGuardian::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int StoneGuardian::GetEnemyLevel()
{
	return mLevel;
}

bool StoneGuardian::GetIsBoss()
{
	return isBoss;
}

const int StoneGuardian::GetEnemyType()
{
	return type;
}

TheKing’sRoyalGuard::TheKing’sRoyalGuard() :
MAX_HIT(30),
MIN_HIT(3),
type(20)
{
	mHealth = 70;
	mDamage = 5;
	mLevel = 5;
	isBoss = false;
}

void TheKing’sRoyalGuard::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	if (randSkill < 10)
	{
		TheKing’sRoyalGuard::SetEnemyHealth(Enemy::Guard(mHealth));
	}
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int TheKing’sRoyalGuard::GetEnemyHealth()
{
	return mHealth;
}

void TheKing’sRoyalGuard::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int TheKing’sRoyalGuard::GetEnemyLevel()
{
	return mLevel;
}

bool TheKing’sRoyalGuard::GetIsBoss()
{
	return isBoss;
}

const int TheKing’sRoyalGuard::GetEnemyType()
{
	return type;
}

TheStalker::TheStalker() :
MAX_HIT(110),
MIN_HIT(30),
type(21)
{
	mHealth = 300;
	mDamage = 66;
	mLevel = 0;
	isBoss = true;
}

void TheStalker::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	if (randSkill <= 60)
	{
		return;
	}
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int TheStalker::GetEnemyHealth()
{
	return mHealth;
}

void TheStalker::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int TheStalker::GetEnemyLevel()
{
	return mLevel;
}

bool TheStalker::GetIsBoss()
{
	return isBoss;
}

const int TheStalker::GetEnemyType()
{
	return type;
}

Troll::Troll() :
MAX_HIT(30),
MIN_HIT(5),
type(22)
{
	mHealth = 20;
	mDamage = 5;
	mLevel = 5;
	isBoss = false;
}

void Troll::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int skillRand = rand() % 100 + 1;
	if (skillRand < 50)
	{
	Troll:SetEnemyHealth(Enemy::Regeneration(mHealth));
	}
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int Troll::GetEnemyHealth()
{
	return mHealth;
}

void Troll::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int Troll::GetEnemyLevel()
{
	return mLevel;
}

bool Troll::GetIsBoss()
{
	return isBoss;
}

const int Troll::GetEnemyType()
{
	return type;
}

WarHound::WarHound() :
MAX_HIT(20),
MIN_HIT(8),
type(23)
{
	mHealth = 20;
	mDamage = 4;
	mLevel = 3;
	isBoss = false;
}

void WarHound::Attack(Player* mHero)
{
	srand(time(NULL));
	int hitValue;
	int randSkill = rand() % 100 + 1;
	hitValue = rand() % (MAX_HIT - MIN_HIT) + MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		mDamage = mDamage - mHero->GetPlayerDefense();
		if (mDamage <= 0)
		{
			mDamage = 0;
		}
		int playerHealth = mHero->GetPlayerHealth();
		if (randSkill < 30)
		{
			playerHealth = playerHealth - Enemy::Bite(mDamage);
		}
		else
		{
			playerHealth = playerHealth - mDamage;
		}
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
	}
}

int WarHound::GetEnemyHealth()
{
	return mHealth;
}

void WarHound::SetEnemyHealth(int EnemyHealth)
{
	mHealth = EnemyHealth;
}

int WarHound::GetEnemyLevel()
{
	return mLevel;
}

const int WarHound::GetEnemyType()
{
	return type;
}

bool WarHound::GetIsBoss()
{
	return isBoss;
}

int Enemy::Sting(int mDamage)
{
	mDamage += 3;
	return mDamage;
}
int Enemy::Bite(int mDamage)
{
	mDamage += 2;
	return mDamage;
}
int Enemy::Guard(int mHp)
{
	mHp += 1;
	return mHp;
}
int Enemy::Regeneration(int mHp)
{
	mHp += 2;
	return mHp;
}
int Enemy::Rage(int mDamage)
{
	mDamage += 5;
	return mDamage;

}
int Enemy::FlameBreath(int mDamage)
{
	mDamage += 5;
	return mDamage;
}
void Enemy::Wait()
{

}
//final bosses special attack
int Enemy::FireBreath(int mDamage)
{
	mDamage += 20;
	return mDamage;
}

std::stringstream Enemy::DisplayEnemy(Enemy* enemy)
{
	std::stringstream ss;
	if (enemy->GetEnemyType() == 1)
	{
		ss << "Armored Phesant";
		return ss;
	}
	else if (enemy->GetEnemyType() == 2)
	{
		ss << "Basilisk";
		return ss;
	}
	else if (enemy->GetEnemyType() == 3)
	{
		ss << "Crocodile";
		return ss;
	}
	else if (enemy->GetEnemyType() == 4)
	{
		ss << "Devious Penguin";
		return ss;
	}
	else if (enemy->GetEnemyType() == 5)
	{
		ss << "Dragon";
		return ss;
	}
	else if (enemy->GetEnemyType() == 6)
	{
		ss << "Hornet Queen";
		return ss;
	}
	else if (enemy->GetEnemyType() == 7)
	{
		ss << "Gargoyle";
		return ss;
	}
	else if (enemy->GetEnemyType() == 8)
	{
		ss << "Giant Beetle";
		return ss;
	}
	else if (enemy->GetEnemyType() == 9)
	{
		ss << "Giant Eagle";
		return ss;
	}
	else if (enemy->GetEnemyType() == 10)
	{
		ss << "Giant Rat";
		return ss;
	}
	else if (enemy->GetEnemyType() == 11)
	{
		ss << "Giant Wasp";
		return ss;
	}
	else if (enemy->GetEnemyType() == 12)
	{
		ss << "Gorgon";
		return ss;
	}
	else if (enemy->GetEnemyType() == 13)
	{
		ss << "Minotaur";
		return ss;
	}
	else if (enemy->GetEnemyType() == 14)
	{
		ss << "Ogre";
		return ss;
	}
	else if (enemy->GetEnemyType() == 15)
	{
		ss << "Pheasent";
		return ss;
	}
	else if (enemy->GetEnemyType() == 16)
	{
		ss << "Rad Dragon";
		return ss;
	}
	else if (enemy->GetEnemyType() == 17)
	{
		ss << "Rat";
		return ss;
	}
	else if (enemy->GetEnemyType() == 18)
	{
		ss << "Stone Golem";
		return ss;
	}
	else if (enemy->GetEnemyType() == 19)
	{
		ss << "Stone Guardian";
		return ss;
	}
	else if (enemy->GetEnemyType() == 20)
	{
		ss << "The King’s Royal Guard";
		return ss;
	}
	else if (enemy->GetEnemyType() == 21)
	{
		ss << "The Stalker";
		return ss;
	}
	else if (enemy->GetEnemyType() == 22)
	{
		ss << "Troll";
		return ss;
	}
	else if (enemy->GetEnemyType() == 23)
	{
		ss << "War Hound";
		return ss;
	}
	else
	{
		ss << "error";
		return ss;
	}
}







