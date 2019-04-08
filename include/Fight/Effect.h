#pragma once

#include <vector>
#include "Stats.h"

namespace RPGEngine
{
    /**
     *\brief Effects that can be applied to entities
     */
    class Effect
    {
    public:
        /**
         *\brief List of effect types supported
         *
         *NB: This enum is a 'FLAG enum' which means
         *effects may have multiple types. However, it only
         *has ONE duration. 
         *
         *Even though 'MARKED' fields is meant to indicate
         *that an entity has been marked in a certain way,
         *it can be used to add further types of effects.
         *
         *See:
         *  Effect::getEffect
         *  Effect::isDot
         *  Effect::isStun
         *  Effect::isBreak
         *  Effect::isMark
         */
        enum EffectType
        {
            DOT     = 1 << 0, //!< Damage over time
            BREAK   = 1 << 1, //!< Break statistics (lower defence, accuracy, ...)
            STUN    = 1 << 2, //!< Stun
            MARK    = 1 << 3  //!< Marked stats (frozen, burn, ...)
        };

        /**
         *\brief Ctor
         *
         *\param srcE A reference to source statistics (this can be used to apply effect based on the src entity)
         *\param type The type of the effect
         *\param duration The number of time the effect will be applied
         *\param isPositive Tells if the effect is positive or negative to the entity
         *\param markedData Generic marked data. Default is 0
         */
        Effect(const Stats& srcE, EffectType type, int duration, bool isPositive = false, int markedData = 0);

        /**
         *\brief Tells if the Effect is positive for the entity
         *
         *\return True if the Effect is positive, false otherwise
         */
        bool isPositive() const;

        /**
         *\brief Tells if the Effect is over
         *
         *\return True if the Effect is over, false otherwise
         */
        bool isEffectFinish() const;

        /**
         *\brief Returns the duration
         *
         *\return The duration
         */
        int getDuration() const;

        /**
         *\brief Tells if the Effect is a dot effect
         *
         *See:
         *  Effect::getEffect
         *  Effect::isStun
         *  Effect::isBreak
         *  Effect::isMark
         *
         *\return True if the Effect is a dot, false otherwise
         */
        bool isDot() const;

        /**
         *\brief Tells if the Effect is a stun effect
         *
         *See:
         *  Effect::getEffect
         *  Effect::isDot
         *  Effect::isBreak
         *  Effect::isMark
         *
         *\return True if the Effect is a stun, false otherwise
         */
        bool isStun() const;

        /**
         *\brief Tells if the Effect is a break effect
         *
         *See:
         *  Effect::getEffect
         *  Effect::isDot
         *  Effect::isStun
         *  Effect::isMark
         *
         *\return True if the Effect is a break, false otherwise
         */
        bool isBreak()  const;

        /**
         *\brief Tells if the Effect is a marking effect
         *
         *See:
         *  Effect::getEffect
         *  Effect::isDot
         *  Effect::isStun
         *  Effect::isBreak
         *
         *\return True if the Effect is a marking effect, false otherwise
         */
        bool isMark() const;

        /**
         *\brief Return the row type of the effect
         *
         *See:
         *  Effect::isDot
         *  Effect::isStun
         *  Effect::isBreak
         *  Effect::isMark
         *
         *\return The type of the effect
         */
        EffectType getEffect() const;
        
        /**
         *\brief Return the marked data
         *
         *See:
         *  Effect::isMark
         *
         *\return The marked data
         */
        int getMarkedData() const;

        /**
         *\brief Applies the effect to some statistics
         *
         *See:
         *    Effect::applyImpl(Stats&, const std::vector<Effect>&)
         *
         *\param [in, out] stat The statistics to apply the effect on
         *\param currentEffects The current array of effects applied to the Entity
         */
        void apply(Stats& stat, const std::vector<Effect*>& currentEffects);

        /**
         *\brief Dctor
         */
        virtual ~Effect();
    protected:
        /**
         *\brief Applies the effect to some statistics
         *
         *Stats that can be broke are resetted after each tick.
         *This means that you have to keep applying breaks. 
         *
         *This functions is called iff mDuration is positive. 
         *Also, note that 'this' may be present in currentEffects
         *
         *\param [in, out] stat The statistics to apply the effect on
         *\param currentEffects The current vector of effect applied to the Entity
         */
        virtual void applyImpl(Stats& stat, const std::vector<Effect*>& currentEffects) = 0;

        const Stats& mSrc; //!< Source entity statistics
        EffectType mType;  //!< Effect type

        bool mIsPositive;  //!< Indicates if the effect is positive or not

        //Note : Is is stored as an int as no other types are suitable:
        //void* implies a free mecanism unwanted for this class
        //template are not practical since Effect are meant to be stored in arrays
        int mMarkedData;   //!< Marking data
                           
    private:
        int mDuration;     //!< Duration in tick
    };
}