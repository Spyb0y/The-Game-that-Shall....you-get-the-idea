#include "Enemy.h"


Enemy::Enemy(float health, float damage, int level)
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

void ArmoredPhesant::Attack()
{

}

Basilisk::Basilisk() :
MAX_HIT(15),
MIN_HIT(5)
{
	mHealth = 60;
	mDamage = 4;
	mLevel = 5;
}

void Basilisk::Attack()
{

}

Crocodile::Crocodile() : 
MAX_HIT(25),
MIN_HIT(6)
{
	mHealth = 20;
	mDamage = 5;
	mLevel = 4;
}

void Crocodile::Attack()
{
	//do shit
}

DeviousPenguin::DeviousPenguin() :
MAX_HIT(2),
MIN_HIT(1)
{
	mHealth = 10;
	mDamage = 1;
	mLevel = 4;
}

void DeviousPenguin::Attack()
{

}

Dragon::Dragon() :
MAX_HIT(30),
MIN_HIT(6)
{
	mHealth = 50;
	mDamage = 7;
	mLevel = 5;
}

void Dragon::Attack()
{

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

void HornetQueen::Attack()
{

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

void Gargoyle::Attack()
{

}

GiantBeetle::GiantBeetle() :
MAX_HIT(20),
MIN_HIT(0)
{
	mHealth = 4;
	mDamage = 1;
	mLevel = 1;
}

void GiantBeetle::Attack()
{

}

GiantEagle::GiantEagle() :
MAX_HIT(20),
MIN_HIT(6)
{
	mHealth = 20;
	mDamage = 6;
	mLevel = 4;
}

void GiantEagle::Attack()
{

}

GiantRat::GiantRat() :
MAX_HIT(25),
MIN_HIT(5)
{
	mHealth = 10;
	mDamage = 3;
	mLevel = 2;
}

void GiantRat::Attack()
{

}

GiantWasp::GiantWasp() :
MAX_HIT(25),
MIN_HIT(8)
{
	mHealth = 14;
	mDamage = 1;
	mLevel = 2;
}

void GiantWasp::Attack()
{

}

Gorgon::Gorgon() :
MAX_HIT(40),
MIN_HIT(4)
{
	mHealth = 25;
	mDamage = 5;
	mLevel = 3;
}

void Gorgon::Attack()
{

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

void Minotaur::Attack()
{

}

Ogre::Ogre() :
MAX_HIT(30),
MIN_HIT(6)
{
	mHealth = 30;
	mDamage = 6;
	mLevel = 5;
}

void Ogre::Attack()
{

}

Pheasent::Pheasent() :
MAX_HIT(20),
MIN_HIT(0)
{
	mHealth = 10;
	mDamage = 2;
	mLevel = 1;
}

void Pheasent::Attack()
{

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

void RadDragon::Attack()
{

}

Rat::Rat() :
MAX_HIT(20),
MIN_HIT(0)
{
	mHealth = 5;
	mDamage = 2;
	mLevel = 1;
}

void Rat::Attack()
{

}

StoneGolem::StoneGolem() :
MAX_HIT(15),
MIN_HIT(5)
{
	mHealth = 40;
	mDamage = 3;
	mLevel = 3;
}

void StoneGolem::Attack()
{

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

void StoneGuardian::Attack()
{

}

TheKing’sRoyalGuard::TheKing’sRoyalGuard() :
MAX_HIT(30),
MIN_HIT(3)
{
	mHealth = 70;
	mDamage = 5;
	mLevel = 5;
}

void TheKing’sRoyalGuard::Attack()
{

}

TheStalker::TheStalker() :
MAX_HIT(110),
MIN_HIT(30)
{
	mHealth = 300;
	mDamage = 66;
}

void TheStalker::Attack()
{

}

Troll::Troll() :
MAX_HIT(30),
MIN_HIT(5)
{
	mHealth = 20;
	mDamage = 5;
	mLevel = 5;
}

void Troll::Attack()
{

}

WarHound::WarHound() :
MAX_HIT(20),
MIN_HIT(8)
{
	mHealth = 20;
	mDamage = 4;
	mLevel = 3;
}

void WarHound::Attack()
{

}







