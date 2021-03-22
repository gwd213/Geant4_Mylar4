#ifndef BDCEVENTACTION_HH
#define BDCEVENTACTION_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "globals.hh"
#include "g4root.hh"

class BDCEventAction : public G4UserEventAction
{
  public:
    BDCEventAction();
    virtual ~BDCEventAction();

    // method from the base class
    virtual void BeginOfEventAction(const G4Event *);
    virtual void EndOfEventAction(const G4Event *);

    void AddEnergyDeposit1(G4double edep) { edep1 += edep; }
	void AddEnergyDeposit2(G4double edep) { edep2 += edep; }
	void AddEnergyDeposit3(G4double edep) { edep3 += edep; }
	void AddEnergyDeposit4(G4double edep) { edep4 += edep; }
  private:
    G4double edep1;
	G4double edep2;
	G4double edep3;
	G4double edep4;
};

#endif
