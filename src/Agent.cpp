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
    vector<int> potentialNeighbors = sim.getGraph().getPotentialNeighbors(mPartyId);
    vector<int> potentialNeighborsOut;
    Coalition coalition = sim.getCoalition(mCoalitionId);
    for(int newPotential: potentialNeighbors)
    {
        if(!coalition.isInvited(newPotential)){
            potentialNeighborsOut.push_back(newPotential);
        }
    }

    mSelectionPolicy->Select(sim,mPartyId,potentialNeighborsOut);
    // TODO: implement this method


    //chose party from set via Edge/Weight

    // check that you dont alredy ivite this
    // party --> invite
}
