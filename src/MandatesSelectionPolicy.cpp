#include "../include/SelectionPolicy.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){

}
void MandatesSelectionPolicy::Select(Simulation& simulation,int partyId,vector<int>& partyIds){
    int maxMandats=0;
    int maxId=-1;
    for(int partyIdV: partyIds){
        if(simulation.getParty(partyIdV).getMandates()>maxMandats){
            maxMandats=simulation.getParty(partyIdV).getMandates();
            maxId=partyIdV;
        }
    }
    simulation.getParty(maxId).invite(simulation.getCoalition(simulation.getParty(partyId).getCoalition()),simulation.getIterationCounter());//invite the party
    simulation.getCoalition(simulation.getParty(partyId).getCoalition()).addInvite(maxId); // add to coalition the invite
    
}