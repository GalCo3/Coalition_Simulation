#include  "../include/JoinPolicy.h"


LastOfferJoinPolicy::LastOfferJoinPolicy() 
{

}
void LastOfferJoinPolicy::join(Party& party,Simulation& sim){
    party.join(party.getCoalitionIdLastInvite(), sim);
}

string LastOfferJoinPolicy::getJoinType()
{
    return "L";
}

