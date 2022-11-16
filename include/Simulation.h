#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"
#include "../include/Coalition.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Coalition &getCoalition(int coalitionId);
    Party &getParty(int partyId);
    int getIterationCounter();

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> mCoalition;
    int iterationCounter;
};
