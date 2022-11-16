#include "../include/SelectionPolicy.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){

}
void MandatesSelectionPolicy::Select(Simulation& simulation,int partyId,vector<int>& partyIds){
    int maxMandats=0;
    int maxId=-1;
    for(int partyIdV: partyIds){
        if(simulation.getParty(partyIdV).getMandates()>maxMandats){
            maxMandats=simulation.getParty(partyIdV).getMandates();
            maxId=simulation.getParty(partyIdV).getId();
        }
    }

    //invite the party
    // add to coalition the invite
}