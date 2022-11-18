#include  "../include/JoinPolicy.h"


LastOfferJoinPolicy::LastOfferJoinPolicy() 
{

}

JoinPolicy* LastOfferJoinPolicy::clone(){
    return new LastOfferJoinPolicy();
}

void LastOfferJoinPolicy::join(Party& party,Simulation& sim){
    party.join(party.getCoalitionIdLastInvite(), sim);
}

string LastOfferJoinPolicy::getJoinType()
{
    return "L";
}

