#ifndef BDCSTEPPINGACTION_HH
#define BDCSTEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"
#include "globals.hh"
#include "g4root.hh"

class BDCSteppingAction : public G4UserSteppingAction
{
  public:
    BDCSteppingAction();
    virtual ~BDCSteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);
};

#endif
