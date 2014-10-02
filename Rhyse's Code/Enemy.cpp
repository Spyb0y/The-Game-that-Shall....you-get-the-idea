#include "Enemy.h"
#include "Player.h"

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

Basilisk::Basilisk() :
MAX_HIT(15),
MIN_HIT(5)
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

Crocodile::Crocodile() :
MAX_HIT(25),
MIN_HIT(6)
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

DeviousPenguin::DeviousPenguin() :
MAX_HIT(2),
MIN_HIT(1)
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

Dragon::Dragon() :
MAX_HIT(30),
MIN_HIT(6)
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

//Boss
HornetQueen::HornetQueen() :
MAX_HIT(50),
MIN_HIT(5)
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

//Boss
Gargoyle::Gargoyle() :
MAX_HIT(50),
MIN_HIT(1)
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

GiantBeetle::GiantBeetle() :
MAX_HIT(20),
MIN_HIT(0)
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

GiantEagle::GiantEagle() :
MAX_HIT(20),
MIN_HIT(6)
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

GiantRat::GiantRat() :
MAX_HIT(25),
MIN_HIT(5)
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

GiantWasp::GiantWasp() :
MAX_HIT(25),
MIN_HIT(8)
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

Gorgon::Gorgon() :
MAX_HIT(40),
MIN_HIT(4)
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

//Boss
Minotaur::Minotaur() :
MAX_HIT(25),
MIN_HIT(1)
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

Ogre::Ogre() :
MAX_HIT(30),
MIN_HIT(6)
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

Pheasent::Pheasent() :
MAX_HIT(20),
MIN_HIT(0)
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

//Boss
RadDragon::RadDragon() :
MAX_HIT(80),
MIN_HIT(10)
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

Rat::Rat() :
MAX_HIT(20),
MIN_HIT(0)
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

StoneGolem::StoneGolem() :
MAX_HIT(15),
MIN_HIT(5)
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

//Boss
StoneGuardian::StoneGuardian() :
MAX_HIT(30),
MIN_HIT(1)
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

TheKing’sRoyalGuard::TheKing’sRoyalGuard() :
MAX_HIT(30),
MIN_HIT(3)
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

TheStalker::TheStalker() :
MAX_HIT(110),
MIN_HIT(30)
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

Troll::Troll() :
MAX_HIT(30),
MIN_HIT(5)
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

WarHound::WarHound() :
MAX_HIT(20),
MIN_HIT(8)
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







