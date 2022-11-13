#pragma once

#include "Agent.h"
#include <vector>
class Coalition {

    public:

    Coalition(int id);

    
    vector<int> getIds;
    vector<int> getInvites;

    void addInvite(int partyId);
    void addParty(Party& party);
    
    bool shouldTerminate();
    
    private:

    int coalitionId;
    int mandatesSum;

    
    vector <int> partysIds;
    vector <int> partysIdsInvites;

};