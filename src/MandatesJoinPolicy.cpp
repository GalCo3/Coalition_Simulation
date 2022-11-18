#include  "../include/JoinPolicy.h"


MandatesJoinPolicy::MandatesJoinPolicy() 
{

}

JoinPolicy* MandatesJoinPolicy::clone()
{
    return new MandatesJoinPolicy();
}

void MandatesJoinPolicy::join(Party& party,Simulation& sim){

    party.join(party.getCoalitionIdMostMandates(), sim,1);
}

string MandatesJoinPolicy::getJoinType()
{
    return "M";
}

