#pragma once
#include <string>
#include <vector>
#include "Simulation.h"
#include "JoinPolicy.h"
using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 
    
    virtual ~Party();
    Party(const Party &other);
    Party(Party && other);
    Party& operator=(const Party& other);
    Party& operator=(Party && other);


    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId();
    void invite(Coalition& coalition,int agentId,int i);

    int getCoalition();
    void setCoalition(int coalitionId);

    int getCoalitionIdMostMandates();
    int getCoalitionIdLastInvite();
    void join(int coalitionIdToJoin,Simulation& sim,int which); // if which ==0 --> we select the lastoffer agent else --> we select the mostMandates agent
    

    


private:

    
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;


    int iterrationInvite ;
    int coalition; // agent number 

    int coalitionId_MostMandates;
    int inviteMaxMandats;
    int agentIdMaxMadndates;

    int coalitionIdLastInvite;
    int agentIdLastOffer;
};
