#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::getCoalitonId()
{
    return mCoalitionId;
}

void Agent::step(Simulation &sim)
{
    // TODO: implement this method

    //chose party from set via Edge/Weight

    // check that you dont alredy ivite this
    // party --> invite
}
