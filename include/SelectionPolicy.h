#pragma once
#include <vector>
#include "Simulation.h"
#include "Coalition.h"

class SelectionPolicy 
{
    public:
    virtual void Select(Simulation& simulation,int partyId,vector<int>& partyIds,int agentId) = 0; 
    //party ids after filter partys that someone from coalition already invited
    virtual string getSelectionType() = 0;
    virtual SelectionPolicy* clone () = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy
{
    public:
    void Select(Simulation& simulation,int partyId,vector<int>& partyIds,int agentId);
    virtual string getSelectionType() override;
    virtual SelectionPolicy* clone() override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{ 
    public:
    void Select(Simulation& simulation,int partyId,vector<int>& partyIds,int agentId);
    virtual string getSelectionType() override;
    virtual SelectionPolicy* clone() override;
};