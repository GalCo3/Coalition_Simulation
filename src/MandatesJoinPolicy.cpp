#include  "../include/JoinPolicy.h"


MandatesJoinPolicy::MandatesJoinPolicy() 
{

}
void MandatesJoinPolicy::join(Party& party,Simulation& sim){
    party.join(party.getCoalitionIdMostMandates(), sim);
}

