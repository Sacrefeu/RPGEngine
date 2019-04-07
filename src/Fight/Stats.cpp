#include "Fight/Stats.h"

namespace RPGEngine
{
	Stats Stats::baseStats(int hp, int rp)
	{
		Stats st;

		st.healthPoints 	= hp;
		st.ressourcePoints  = rp;

		return st;
	}

	Stats& Stats::accuracy(int pa, int ma)
	{
		pAccuracy = pa;
		mAccuracy = ma;

		return *this;
	}

	Stats& Stats::attack(int pA, int pCrit, int mA, int mCrit)
	{
		pAttack = pA;
		mAttack = mA;

		this->pCrit = pCrit;
		this->mCrit = mCrit;

		return *this;
	}

	Stats& Stats::defense(int pDef, int evade, int mDef, int block)
	{
		this->pDef = pDef;
		this->mDef = mDef;

		this->evade	= evade;
		this->block = block;

		return *this;
	}
};