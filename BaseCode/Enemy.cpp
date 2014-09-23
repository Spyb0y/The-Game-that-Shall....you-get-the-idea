#include "Enemy.h"


Enemy::Enemy(float health, int damage, int level)
{
}


Enemy::~Enemy()
{
}

ArmoredPhesant::ArmoredPhesant() :
MAX_HIT(25),
MIN_HIT(5)
{
	mHealth = 15;
	mDamage = 3;
	mLevel = 2;
}

void ArmoredPhesant::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

Basilisk::Basilisk() :
MAX_HIT(15),
MIN_HIT(5)
{
	mHealth = 60;
	mDamage = 4;
	mLevel = 5;
}

void Basilisk::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
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

Crocodile::Crocodile() : 
MAX_HIT(25),
MIN_HIT(6)
{
	mHealth = 20;
	mDamage = 5;
	mLevel = 4;
}

void Crocodile::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
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

DeviousPenguin::DeviousPenguin() :
MAX_HIT(2),
MIN_HIT(1)
{
	mHealth = 10;
	mDamage = 1;
	mLevel = 4;
}

void DeviousPenguin::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

Dragon::Dragon() :
MAX_HIT(30),
MIN_HIT(6)
{
	mHealth = 50;
	mDamage = 7;
	mLevel = 5;
}

void Dragon::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
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

//Boss
HornetQueen::HornetQueen() :
MAX_HIT(50),
MIN_HIT(5)
{
	mHealth = 100;
	mDamage = 25;
	mLevel = 4;
}

void HornetQueen::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

//Boss
Gargoyle::Gargoyle() :
MAX_HIT(50),
MIN_HIT(1)
{
	mHealth = 75;
	mDamage = 20;
	mLevel = 3;
}

void Gargoyle::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

GiantBeetle::GiantBeetle() :
MAX_HIT(20),
MIN_HIT(0)
{
	mHealth = 4;
	mDamage = 1;
	mLevel = 1;
}

void GiantBeetle::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

GiantEagle::GiantEagle() :
MAX_HIT(20),
MIN_HIT(6)
{
	mHealth = 20;
	mDamage = 6;
	mLevel = 4;
}

void GiantEagle::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
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

GiantRat::GiantRat() :
MAX_HIT(25),
MIN_HIT(5)
{
	mHealth = 10;
	mDamage = 3;
	mLevel = 2;
}

void GiantRat::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
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

GiantWasp::GiantWasp() :
MAX_HIT(25),
MIN_HIT(8)
{
	mHealth = 14;
	mDamage = 1;
	mLevel = 2;
}

void GiantWasp::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
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

Gorgon::Gorgon() :
MAX_HIT(40),
MIN_HIT(4)
{
	mHealth = 25;
	mDamage = 5;
	mLevel = 3;
}

void Gorgon::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
		mHero->SetPlayerHealth(playerHealth);
	}
	else
	{
		return;
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

//Boss
Minotaur::Minotaur() :
MAX_HIT(25),
MIN_HIT(1)
{
	mHealth = 30;
	mDamage = 10;
	mLevel = 1;
}

void Minotaur::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

Ogre::Ogre() :
MAX_HIT(30),
MIN_HIT(6)
{
	mHealth = 30;
	mDamage = 6;
	mLevel = 5;
}

void Ogre::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
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

Pheasent::Pheasent() :
MAX_HIT(20),
MIN_HIT(0)
{
	mHealth = 10;
	mDamage = 2;
	mLevel = 1;
}

void Pheasent::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

//Boss
RadDragon::RadDragon() :
MAX_HIT(80),
MIN_HIT(10)
{
	mHealth = 150;
	mDamage = 25;
	mLevel = 5;
}

void RadDragon::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
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

Rat::Rat() :
MAX_HIT(20),
MIN_HIT(0)
{
	mHealth = 5;
	mDamage = 2;
	mLevel = 1;
}

void Rat::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

StoneGolem::StoneGolem() :
MAX_HIT(15),
MIN_HIT(5)
{
	mHealth = 40;
	mDamage = 3;
	mLevel = 3;
}

void StoneGolem::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

//Boss
StoneGuardian::StoneGuardian() :
MAX_HIT(30),
MIN_HIT(1)
{
	mHealth = 50;
	mDamage = 15;
	mLevel = 2;
}

void StoneGuardian::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

TheKing’sRoyalGuard::TheKing’sRoyalGuard() :
MAX_HIT(30),
MIN_HIT(3)
{
	mHealth = 70;
	mDamage = 5;
	mLevel = 5;
}

void TheKing’sRoyalGuard::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

TheStalker::TheStalker() :
MAX_HIT(110),
MIN_HIT(30)
{
	mHealth = 300;
	mDamage = 66;
}

void TheStalker::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

Troll::Troll() :
MAX_HIT(30),
MIN_HIT(5)
{
	mHealth = 20;
	mDamage = 5;
	mLevel = 5;
}

void Troll::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
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

WarHound::WarHound() :
MAX_HIT(20),
MIN_HIT(8)
{
	mHealth = 20;
	mDamage = 4;
	mLevel = 3;
}

void WarHound::Attack(Player* mHero)
{
	int hitValue;
	hitValue = rand() % (MAX_HIT - MIN_HIT) - MIN_HIT;
	if (hitValue > mHero->GetPlayerEvade())
	{
		int playerHealth = mHero->GetPlayerHealth();
		playerHealth = playerHealth - mDamage;
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







