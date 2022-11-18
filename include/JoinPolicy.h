#pragma once
#include "../include/Party.h"
#include <string>
using std::string;

class JoinPolicy {

    public:
    virtual void join(Party& party,Simulation& sim) = 0;
    virtual string getJoinType() = 0;
    virtual JoinPolicy* clone () = 0;
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
    MandatesJoinPolicy();
    virtual JoinPolicy* clone() override;
    virtual void join(Party& party,Simulation& sim) override; 
    virtual string getJoinType() override;
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
    LastOfferJoinPolicy();
    virtual JoinPolicy* clone() override;
    virtual void join(Party& party,Simulation& sim) override;
    virtual string getJoinType() override;
};