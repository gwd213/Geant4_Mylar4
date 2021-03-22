#include "BDCEventAction.hh"

BDCEventAction::BDCEventAction()
: G4UserEventAction()
{
}

BDCEventAction::~BDCEventAction()
{
}

void BDCEventAction::BeginOfEventAction(const G4Event*)
{
  edep1 = 0.;
  edep2 = 0.;
  edep3 = 0.;
  edep4 = 0.;
}

void BDCEventAction::EndOfEventAction(const G4Event*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

  analysisManager -> FillNtupleDColumn(1, 0, edep1);
  analysisManager -> FillNtupleDColumn(1, 1, edep2);
  analysisManager -> FillNtupleDColumn(1, 2, edep3);
  analysisManager -> FillNtupleDColumn(1, 3, edep4);
  analysisManager -> AddNtupleRow(1);
}
