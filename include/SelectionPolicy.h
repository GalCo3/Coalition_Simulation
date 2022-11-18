#pragma once
#include <vector>
#include "Simulation.h"
#include "Coalition.h"

class SelectionPolicy 
{
    public:
    virtual void Select(Simulation& simulation,int partyId,vector<int>& partyIds) = 0; 
    //party ids after filter partys that someone from coalition already invited
};

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
    void Select(Simulation& simulation,int partyId,vector<int>& partyIds);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{ 
    public:
    void Select(Simulation& simulation,int partyId,vector<int>& partyIds);
};