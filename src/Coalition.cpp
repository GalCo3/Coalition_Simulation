#include "../include/Coalition.h"



Coalition::Coalition(int id, Party& party)
{   
    coalitionId = id;
    mandatesSum = party.getMandates();
    
    partysIds;
    partysIdsInvites;
    partysIds.push_back(party.getId());
}

bool Coalition:: shouldTerminate()
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

    for (int i = 0; i < partysIdsInvites.size(); i++)
    {
        if(partysIdsInvites[i] = partyId)
        return true;
    }
    return false;
}


void Coalition::addParty(Party& party)
{
    mandatesSum = mandatesSum + party.getMandates();
    partysIds.push_back(party.getId());
}

