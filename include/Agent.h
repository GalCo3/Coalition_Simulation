#pragma once

#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    int getCoalitonId();

private:
    int mAgentId;
    int mPartyId;
    int mCoalitionId;
    SelectionPolicy *mSelectionPolicy;
    

    
};
