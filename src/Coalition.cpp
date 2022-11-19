#include "../include/Coalition.h"
#include "../include/Party.h"
// #include <iostream>
// #include <vector>
// #include <algorithm>


Coalition::Coalition(int id, Party& party): coalitionId(id),mandatesSum(party.getMandates()),partysIds(),partysIdsInvites()
{   
    partysIds.push_back(party.getId());
    // partysIdsInvites.push_back(-1);
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

 void Coalition::getIds(vector<int>& v) const
{

    for(int a :partysIds)
    {
        v.push_back(a);
    }
}


bool Coalition::isInvited(int partyId)
{
    


    auto it = partysIdsInvites.begin();

    while (it != partysIdsInvites.end())
    {
        if (*it == partyId)
        {
            return true;
        }
        it++;
        /* code */
    }
    
    // for(const int& partyIdV:partysIdsInvites)
    // {
        
    //     if (partyIdV == partyId)
    //     {
    //         return true;
    //         // partysIdsInvites.
    //     }
        
    // }
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
