#pragma once
#include <string>
#include <vector>
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

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId();
    void invite(int partyId,int i);

    int getCoalition();
    void setCoalition(int coalitionId);

    int getPartyIdMostMandates();
    int getPartyIdLastInvite();

    


private:

    
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;


    int iterrationInvite ;
    int coalition; // agent number 

    int coalitionId_MostMandates;
    int inviteMaxMaandat;
    int coalitionIdLastInvite;
};
