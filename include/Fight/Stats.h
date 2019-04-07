#pragma once

namespace RPGEngine
{
	/**
	 *\brief Statistics for fightable entities
	 */
	struct Stats
	{
		/**
		 *\brief Construct a statistic giving hp and rp
		 *
		 *The goal of this function and its following is to
		 *provide a simple interface to create statistics :
		 *
		 *Stats::basicStats(100, 50)
		 *			.accuracy(100, 100)
		 *			.attack(100, 10, 10, 0)
		 *			.defense(50, 0, 50, 0)
		 *
		 *Please see :
		 *		Stats::accuracy(int, int),
		 *		Stats::attack(int, int, int, int),
		 *		Stats::defense(int, int, int, int)
		 *
		 *\param hp The health points of the entity
		 *\param rp The ressource points of the entity
		 *
		 *\return A newly created Stats
		 */
		static Stats baseStats(int hp, int rp);

		/**
		 *\brief Sets the accuracy stats of the entity
		 *
		 *\param pa The physical accuracy
		 *\param ma The magical accuracy
		 *
		 *\return A reference to the current object
		 */
		Stats& accuracy(int pa, int ma);

		/**
		 *\brief Sets the offensive stats of the entity
		 *
		 *\param pA The physical attack
		 *\param pCrit The physical crit chance
 		 *\param mA The magical attack
		 *\param mCrit The magical crit chance
		 *
		 *\return A reference to the current object
		 */
		Stats& attack(int pA, int pCrit, int mA, int mCrit);
		
		/**
		 *\brief Sets the devensive stats of the entity
		 *
		 *\param pDef The physical defense
		 *\param evade The dodge chance
 		 *\param mDef The magical defense
		 *\param block The block chance
		 *
		 *\return A reference to the current object
		 */
		Stats& defense(int pDef, int evade, int mDef, int block);

		int healthPoints; 		//!< HP of the entity
		int ressourcePoints;    //!< Point that the entity will use
								//!< as ressource (exemple : mana)
		
		int pAccuracy;			//!< Accuracy of physical attacks
		int mAccuracy;			//!< Accuracy of magical attacks

		int pAttack;			//!< Physical attack
		int mAttack;			//!< Magical attack
		int pCrit;				//!< Crit chances of physical attacks
		int mCrit;				//!< Crit chances of magical attacks

		int pDef;			 	//!< Physical defense
		int mDef;				//!< Magical defense
		int evade;				//!< Dodge chances
		int block;				//!< Block chances
	};
}