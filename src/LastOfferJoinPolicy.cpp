#include  "../include/JoinPolicy.h"
#include  "../include/Party.h"




JoinPolicy* LastOfferJoinPolicy::clone(){
    return new LastOfferJoinPolicy();
}

void LastOfferJoinPolicy::join(Party& party,Simulation& sim){
    party.join(party.getCoalitionIdLastInvite(), sim,0);
}

string LastOfferJoinPolicy::getJoinType()
{
    return "L";
}

