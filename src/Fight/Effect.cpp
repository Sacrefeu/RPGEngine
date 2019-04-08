#include "Fight/Effect.h"

namespace RPGEngine 
{
    Effect::Effect(const Stats& srcE, Effect::EffectType type, int duration, bool isPositive, void* markedData) :
        mSrc        {    srcE    }
        mType       {   effect   },
        mDuration   {  duration  },
        mIsPositive { isPositive },
        mMarkedData { markedData }
    {
    }

    void Effect::apply(Stats& stat, const std::vector<Effect*>& currentEffects)
    {
        if(!isEffectFinish())
            applyImpl(stat, currentEffects);

        mDuration --;
    }

    bool Effect::isEffectFinish() const
    {
        return mDuration <= 0;
    }

    int Effect::getDuration() const
    {
        return mDuration;
    }

    bool Effect::isDot() const
    {
        return mType & Effect::EffectType::DOT;
    }

    bool Effect::isStun() const
    {
        return mType & Effect::EffectType::STUN;
    }

    bool Effect::isBreak() const
    {
        return mType & Effect::EffectType::BREAK;
    }

    bool Effect::isMark() const
    {
        return mType & Effect::EffectType::MARK;
    }

    Effect::EffectType Effect::getEffect() const
    {
        return mType;
    }
    
    int Effect::getMarkedData() const
    {
        return mMarkedData;
    }

    bool Effect::isPositive() const
    {
        return mIsPositive;
    }

    Effect::~Effect()
    {

    }

};