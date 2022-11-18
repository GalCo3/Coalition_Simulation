#pragma once
#include "../include/Party.h"
#include <string>
using std::string;

class JoinPolicy {

    public:
    virtual void join(Party& party,Simulation& sim) = 0;
    virtual string getJoinType() = 0;

};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
    MandatesJoinPolicy();
    virtual void join(Party& party,Simulation& sim) override; 
    virtual string getJoinType() override;
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
    LastOfferJoinPolicy();
    virtual void join(Party& party,Simulation& sim) override;
    virtual string getJoinType() override;
};