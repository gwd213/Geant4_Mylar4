#include "BDCRunAction.hh"

BDCRunAction::BDCRunAction()
: G4UserRunAction()
{
  fName = "data";
  SetAnalysis();
}

BDCRunAction::BDCRunAction(const char *name)
: G4UserRunAction()
{
  fName = name;
  SetAnalysis();
}

BDCRunAction::~BDCRunAction()
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> Write();
  analysisManager -> CloseFile();

  delete G4AnalysisManager::Instance();
}

void BDCRunAction::BeginOfRunAction(const G4Run*)
{
}

void BDCRunAction::EndOfRunAction(const G4Run*)
{
}

void BDCRunAction::SetAnalysis()
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> OpenFile(fName);

  analysisManager -> CreateNtuple("step", "step");
  analysisManager -> CreateNtupleIColumn("eventID");
  analysisManager -> CreateNtupleIColumn("volumeID");
  analysisManager -> CreateNtupleDColumn("edep");
  analysisManager -> FinishNtuple();

  analysisManager -> CreateNtuple("event", "energy deposit per event in volume-1");
  analysisManager -> CreateNtupleDColumn("edep1");
  analysisManager -> CreateNtupleDColumn("edep2");
  analysisManager -> CreateNtupleDColumn("edep3");
  analysisManager -> CreateNtupleDColumn("edep4");
  analysisManager -> FinishNtuple();
}
