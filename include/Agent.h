#pragma once

#include <vector>
// #include "SelectionPolicy.h"

class Graph;
class SelectionPolicy;
class Simulation;
class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    virtual ~Agent();
    Agent(const Agent &other);
    Agent(Agent && other) noexcept;
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent && other) noexcept;

    void setId(int id);
    void setPartyId(int partyId);


    int getPartyId() const;
    int getId() const;
    void step(Simulation & sim);
    int getCoalitonId();

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalitionId;
    

    
};
