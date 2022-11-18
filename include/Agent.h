#pragma once

#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~Agent();
    Agent(const Agent &other);
    Agent(Agent && other);
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent && other);



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
