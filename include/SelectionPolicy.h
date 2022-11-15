#pragma once
#include <vector>
#include "Simulation.h"

class SelectionPolicy 
{
    virtual void Select(Simulation& simulation,int partyId,vector<int>& partyIds) = 0; 
    //party ids after filter partys that someone from coalition already invited
};

class MandatesSelectionPolicy: public SelectionPolicy
{
    void Select(Simulation& simulation,int partyId,vector<int>& partyIds);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{ 
    void Select(Simulation& simulation,int partyId,vector<int>& partyIds);
};