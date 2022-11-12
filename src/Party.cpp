#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{

    // if itteration counter != -1  itteration counter  = start iterraion + 3 --> decide and change color to red

    //else
    

}


//void invite
// start iteration to iterrartion counter ##JUST ONCE##

    // change color if not changed to yellow
    // add invite to set
    // change lastInvite 