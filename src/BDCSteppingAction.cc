#include "BDCSteppingAction.hh"
#include "BDCEventAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4EventManager.hh"

BDCSteppingAction::BDCSteppingAction()
: G4UserSteppingAction()
{
}

BDCSteppingAction::~BDCSteppingAction()
{
}

void BDCSteppingAction::UserSteppingAction(const G4Step* step)
{
  G4int eventID = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();
  G4int volumeID = step -> GetPreStepPoint() -> GetPhysicalVolume() -> GetCopyNo();
  G4double totalEdep = step -> GetTotalEnergyDeposit();

  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> FillNtupleIColumn(0, eventID);
  analysisManager -> FillNtupleIColumn(1, volumeID);
  analysisManager -> FillNtupleDColumn(2, totalEdep);
  analysisManager -> AddNtupleRow();

  BDCEventAction *eventAction = (BDCEventAction *) G4EventManager::GetEventManager() -> GetUserEventAction();

  if (volumeID == 1)
    eventAction -> AddEnergyDeposit1(totalEdep);
  if (volumeID == 2)
    eventAction -> AddEnergyDeposit2(totalEdep);
  if (volumeID == 3)
    eventAction -> AddEnergyDeposit3(totalEdep);
  if (volumeID == 4)
    eventAction -> AddEnergyDeposit4(totalEdep);

}
