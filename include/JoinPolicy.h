#pragma once
#include "../include/Party.h"

class JoinPolicy {


    virtual void join(Party& party) = 0;

};

class MandatesJoinPolicy : public JoinPolicy 
{
    public:
    MandatesJoinPolicy();
    void join(Party& party);
};

class LastOfferJoinPolicy : public JoinPolicy 
{
    public:
    LastOfferJoinPolicy();
    void join(Party& party);

};