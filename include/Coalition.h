#pragma once

#include "Agent.h"
#include <vector>
class Coalition {

    public:

    Coalition(int agentId, Party& party);

    
    vector<int> getIds;
    vector<int> getInvites;

    void addInvite(int partyId);
    void addParty(Party& party);
    bool isInvited(int partyId);
    bool shouldTerminate() const; 
    int getId();
    int getMandatesSum();
    
    private:

    int coalitionId;
    int mandatesSum;

    
    vector <int> partysIds;
    vector <int> partysIdsInvites;

};