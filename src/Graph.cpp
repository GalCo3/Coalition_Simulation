#include "../include/Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

void Graph::getPotentialNeighbors(int partyId,vector<int>& vec)
{
    

    for (Party party:mVertices)
    {
        if (!(party.getId() == partyId) & !(mEdges[partyId][party.getId()] == 0) )
        {
            if (mVertices[party.getId()].getState()!=State::Joined)
            {
                vec.push_back(party.getId());
            }
            
        }
        
    }
    
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party &Graph::getParty(int partyId)
{
    return mVertices[partyId];
}

void Graph::stepGraph(Simulation& sim)
{
    for(Party& party : mVertices)
    {
        party.step(sim);
    }
}


bool Graph::everyOne_Red() const{
    for(const Party& party: mVertices){
        if(party.getState()!=State::Joined)
            return false;
    }
    return true;
}