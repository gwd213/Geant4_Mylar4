#include "BDCPrimaryGeneratorAction.hh"
#include "globals.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

BDCPrimaryGeneratorAction::BDCPrimaryGeneratorAction()
	: G4VUserPrimaryGeneratorAction()
{
	G4int n_particle = 1;
	fParticleGun = new G4ParticleGun(n_particle);
}


void BDCPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	//this function is called at the begining of each event
	G4IonTable* ionTable = G4IonTable::GetIonTable();
	G4ParticleDefinition* ion
		= ionTable -> GetIon(50,132,0); //(Z,A,0)
	kineticEnergy = 200.*MeV; //Kinetic Energy of the ion
	fParticleGun -> GeneratePrimaryVertex(anEvent);
	fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));


	fParticleGun -> SetParticleDefinition(ion);
	fParticleGun -> SetParticleEnergy(kineticEnergy);
}

BDCPrimaryGeneratorAction::~BDCPrimaryGeneratorAction()
{
	delete fParticleGun;
}
