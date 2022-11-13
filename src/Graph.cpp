#include "Graph.h"

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

vector<int> Graph::getPotentialNeighbors(int partyId)
{
    vector<int> partyNeighbors;
    for(int i = 0;i< mVertices.size() ; i++){

        if (i!= partyId & mEdges[partyId][i]!=0)
        {
                if (mVertices[i].getState() != State::Joined)
            {
                partyNeighbors.push_back(i);
            }
            
        }
        
    }

}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}