#pragma once
#include <string>
#include "Party.h"
#include "Simulation.h"
using std::string;

class Party;
class Simulation;

class JoinPolicy {

    public:
    virtual void join(Party& party,Simulation& sim) = 0;
    virtual ~JoinPolicy();
    virtual string getJoinType() = 0;
    virtual JoinPolicy* clone () = 0;
};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
    MandatesJoinPolicy();
    virtual ~MandatesJoinPolicy();
    virtual JoinPolicy* clone() override;
    virtual void join(Party& party,Simulation& sim) override; 
    virtual string getJoinType() override;
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
    LastOfferJoinPolicy();
    virtual ~LastOfferJoinPolicy();
    virtual JoinPolicy* clone() override;
    virtual void join(Party& party,Simulation& sim) override;
    virtual string getJoinType() override;
};