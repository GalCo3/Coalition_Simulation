#include "../include/Party.h"
#include "../include/Coalition.h"
#include "../include/JoinPolicy.h"
#include  "../include/Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) ,iterrationInvite(-1),coalition(-1),
coalitionId_MostMandates(-1),inviteMaxMandats(-1),agentIdMaxMadndates(-1),coalitionIdLastInvite(-1),agentIdLastOffer(-1)
{

}

Party::~Party() //destructor
{
    if (mJoinPolicy)
    {
        delete mJoinPolicy;
    }
    
}

Party::Party(const Party& other) : 
    mId(other.mId),mName(other.mName),mMandates(other.mMandates),

    mJoinPolicy(other.mJoinPolicy->clone()),mState(other.mState),iterrationInvite(other.iterrationInvite),

    coalition(other.coalition),coalitionId_MostMandates(other.coalitionId_MostMandates), 

    inviteMaxMandats(other.inviteMaxMandats),agentIdMaxMadndates(other.agentIdMaxMadndates),coalitionIdLastInvite(other.coalitionIdLastInvite),//copy constructor
    agentIdLastOffer(other.agentIdLastOffer)
{

}

 //move constructor
Party::Party(Party && other) noexcept:

    mId(other.mId),mName(other.mName),mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy),mState(other.mState),iterrationInvite(other.iterrationInvite),

    coalition(other.coalition),coalitionId_MostMandates(other.coalitionId_MostMandates),inviteMaxMandats(other.inviteMaxMandats),agentIdMaxMadndates(other.agentIdMaxMadndates),coalitionIdLastInvite(other.coalitionIdLastInvite),agentIdLastOffer(other.agentIdLastOffer)
    
{
    other.mJoinPolicy = nullptr;
}


Party& Party::operator=(const Party& other)
{
    mId = other.mId;
    mName = other.mName; 
    mMandates = other.mMandates;
    mState = other.mState;
    iterrationInvite = other.iterrationInvite;
    coalition = other.coalition;
    coalitionId_MostMandates = other.coalitionId_MostMandates;
    inviteMaxMandats = other.inviteMaxMandats;
    coalitionIdLastInvite = other.coalitionIdLastInvite;
    

    string temp = other.mJoinPolicy->getJoinType();

    if (mJoinPolicy->getJoinType()!= temp)
    {
        delete mJoinPolicy;
        if (temp == "M")
        {
            mJoinPolicy = new MandatesJoinPolicy();
        }
        else
        {
            mJoinPolicy = new LastOfferJoinPolicy();
        }
        
    }
    return *this;
}

Party& Party::operator=(Party && other) noexcept
{
    mId = other.mId;
    mName = other.mName; 
    mMandates = other.mMandates;
    mState = other.mState;
    iterrationInvite = other.iterrationInvite;
    coalition = other.coalition;
    coalitionId_MostMandates = other.coalitionId_MostMandates;
    inviteMaxMandats = other.inviteMaxMandats;
    coalitionIdLastInvite = other.coalitionIdLastInvite;
    

    delete mJoinPolicy;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy=nullptr;
    
    return *this;
}









State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{

    // if itteration counter != -1  itteration counter  = start iterraion + 3 --> decide and change color to red
    if(iterrationInvite!=-1){
        if(s.getIterationCounter()-iterrationInvite==3){
            mJoinPolicy ->join(*this,s);
        }
        else{
        // iterrationInvite++;
        }
    }
    

}

int Party::getId()
{
    return mId;
}

void Party::invite(Coalition& coalition,int agentId, int i)
// start iteration to iterrartion counter ##JUST ONCE##
{
    if(iterrationInvite==-1){
        iterrationInvite=i;
        mState=CollectingOffers; // change color if not changed to yellow
    }
    coalitionIdLastInvite=coalition.getId();// change lastInvite 
    agentIdLastOffer = agentId;

    if(inviteMaxMandats<coalition.getMandatesSum()||(inviteMaxMandats==coalition.getMandatesSum()&& coalitionId_MostMandates>coalition.getId()) ){
        inviteMaxMandats=coalition.getMandatesSum();
        coalitionId_MostMandates= coalition.getId();
        agentIdMaxMadndates = agentId;
    }
    
 
}

int Party::getCoalition()
{
    return coalition;
}

void Party::setCoalition(int coalitionId)
{
    if(coalition == -1)
        coalition = coalitionId;
}


void Party::join(int coalitionIdToJoin, Simulation& sim,int which){

    sim.getCoalition(coalitionIdToJoin).addParty(*this);
    coalition = coalitionIdToJoin;
    setState(State::Joined);
    
    if (which == 0)
    {
        sim.newAgent(agentIdLastOffer,mId);
    }

    else
    {
        sim.newAgent(agentIdMaxMadndates,mId);
    }
    
}


int Party::getCoalitionIdLastInvite(){
    return coalitionIdLastInvite;
}
int Party::getCoalitionIdMostMandates(){
    return coalitionId_MostMandates;
}
