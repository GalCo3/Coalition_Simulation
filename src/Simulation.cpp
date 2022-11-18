#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
    iterationCounter = 0;
    mCoalition;

    for (int i = 0; i < mAgents.size(); i++)
    {
        mCoalition.push_back(Coalition(mAgents[i].getId(),getParty(mAgents[i].getPartyId())));
    }
    
}

void Simulation::step()
{
    
    mGraph.stepGraph(*this); //step for partys -- because this is a private field in graph

    for(Agent& agent : mAgents)
    {
        agent.step(*this);
    }
}

void Simulation::newAgent(int agentId,int partyId)
{
    mAgents.push_back(Agent(mAgents[agentId]));
    mAgents[mAgents.size()-1].setId(mAgents.size()-1);
    mAgents[mAgents.size()-1].setPartyId(partyId);
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method

    // check if coalition has 61 mandated or everyone join
    for(const Coalition& coalition : mCoalition)
    {
        if(coalition.shouldTerminate());
            {return true;}
    }

    
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph &Simulation::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party &Simulation::getParty(int partyId)
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}

Coalition& Simulation::getCoalition(int coalitionId)
{
    return mCoalition[coalitionId];
}

int Simulation::getIterationCounter(){
    return iterationCounter;
}

