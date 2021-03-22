#ifndef BDCPRIMARYGENERATORACTION_HH
#define BDCPRIMARYGENERATORACTION_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "globals.hh"

class BDCPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    BDCPrimaryGeneratorAction();    
    virtual ~BDCPrimaryGeneratorAction();
	G4double kineticEnergy, ionCharge;
    // method from the base class
    virtual void GeneratePrimaries(G4Event*);         

	const G4ParticleGun* GetParticleGun() const { return fParticleGun; }
  private:
    G4ParticleGun* fParticleGun;
};

#endif
