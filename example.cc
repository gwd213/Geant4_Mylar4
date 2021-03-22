#include "globals.hh"

#include "G4RunManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"

#include "QGSP_BERT.hh"
#include "BDCDetectorConstruction.hh"
#include "BDCPrimaryGeneratorAction.hh"
#include "BDCRunAction.hh"
#include "BDCEventAction.hh"
#include "BDCSteppingAction.hh"

int main(int argc, char** argv)
{
  G4RunManager* runManager = new G4RunManager;

  G4VModularPhysicsList* physicsList = new QGSP_BERT;
  runManager -> SetUserInitialization(physicsList);
  runManager -> SetUserInitialization(new BDCDetectorConstruction());
  runManager -> SetUserAction(new BDCPrimaryGeneratorAction());
  if (argc != 1)
    runManager -> SetUserAction(new BDCRunAction(argv[1]));
  else
    runManager -> SetUserAction(new BDCRunAction());

  runManager -> SetUserAction(new BDCEventAction());
  runManager -> SetUserAction(new BDCSteppingAction());
  runManager -> Initialize();
  
  G4VisManager* visManager = new G4VisExecutive;
  visManager -> Initialize();

  G4UImanager* UImanager = G4UImanager::GetUIpointer();
  if (argc != 1) 
  {
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager -> ApplyCommand(command+fileName);
  }
  else 
  {
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    UImanager -> ApplyCommand("/control/execute vis.mac"); 
    ui -> SessionStart();
    delete ui;
  }

  delete visManager;
  delete runManager;

  return 0;
}
