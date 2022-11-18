#include "../include/Coalition.h"
#include "../include/Party.h"


Coalition::Coalition(int id, Party& party): coalitionId(id),mandatesSum(party.getMandates()),partysIds(),partysIdsInvites()
{   
    partysIds.push_back(party.getId());
    party.setState(State::Joined);
    party.setCoalition(coalitionId);
}

bool Coalition:: shouldTerminate() const
{
    return mandatesSum>= 61;
}

void Coalition::addInvite(int partyId)
{
    partysIdsInvites.push_back(partyId);
}


bool Coalition::isInvited(int partyId)
{
    // return true if the party is alredy invited

    for(int partyIdV:partysIdsInvites)
    {
        if (partyIdV == partyId)
        {
            return true;
        }
        
    }
    return false;
}


void Coalition::addParty(Party& party)
{
    mandatesSum = mandatesSum + party.getMandates();
    partysIds.push_back(party.getId());
    party.setCoalition(coalitionId);
}
int Coalition::getId(){
    return coalitionId;
}
int Coalition::getMandatesSum(){
    return mandatesSum;
}
