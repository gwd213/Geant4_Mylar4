#ifndef BDCRUNACTION_HH
#define BDCRUNACTION_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "globals.hh"
#include "g4root.hh"

class BDCRunAction : public G4UserRunAction
{
  public:
    BDCRunAction();
    BDCRunAction(const char *);
    virtual ~BDCRunAction();

    // method from the base class
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);

    void SetAnalysis();

  private:
    G4String fName;
};

#endif
