#include "../include/SelectionPolicy.h"

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){

}
void EdgeWeightSelectionPolicy::Select(Simulation& simulation,int partyId,vector<int>& partyIds){
    int maxWeight=0;
    int maxWeightId=-1;
    
    for(int partyIdV: partyIds){
        if(simulation.getGraph().getEdgeWeight(partyId,partyIdV)>maxWeight){
            maxWeight=simulation.getGraph().getEdgeWeight(partyId,partyIdV);
            maxWeightId = partyIdV;
    }
    
    simulation.getParty(maxWeightId).invite(simulation.getCoalition(simulation.getParty(partyId).getCoalition()),simulation.getIterationCounter());//invite the party
    simulation.getCoalition(simulation.getParty(partyId).getCoalition()).addInvite(maxWeightId); // add to coalition the invite
    
}