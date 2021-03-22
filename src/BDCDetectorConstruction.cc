#include "BDCDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

BDCDetectorConstruction::BDCDetectorConstruction()
	: G4VUserDetectorConstruction()
{
}

BDCDetectorConstruction::~BDCDetectorConstruction()
{
}

G4VPhysicalVolume* BDCDetectorConstruction::Construct()
{  
	G4NistManager* nist = G4NistManager::Instance();
	G4Material* Vacuum;
	G4Element* elN;
	G4Element* elO;
	elN  = new G4Element("Nitrogen", "N",  7,  14.000674*g/mole);
	elO  = new G4Element("Oxygen",   "O",  8,  15.9994*g/mole);

	G4double densityUniverse = 1.e-25*g/CLHEP::cm3;
    G4double tempUniverse= 2.73 *kelvin;
	G4double temperature = tempUniverse;
    G4double density = densityUniverse;
	Vacuum =  new G4Material("Vacuum", density, 2, kStateGas, temperature);
    Vacuum -> AddElement(elO,.3);
    Vacuum -> AddElement(elN,.7);
	// -----------------------------------------------------
	// World

//	G4Material* world_mat = nist -> FindOrBuildMaterial("G4_AIR");

	G4double world_size = 50*mm;

	G4Box* solidWorld =    
		new G4Box("World",                       // its name
				0.5*world_size,                // half x
				0.5*world_size,                // half y
				0.5*world_size);               // half z

	G4LogicalVolume* logicWorld =                         
		new G4LogicalVolume(solidWorld,          //its solid
				Vacuum,           //its material
				"World");            //its name

	G4VPhysicalVolume* physWorld = 
		new G4PVPlacement(0,                     //no rotation
				G4ThreeVector(),       //at (0,0,0)
				logicWorld,            //its logical volume
				"World",               //its name
				0,                     //its mother  volume
				false,                 //no boolean operation
				0,                     //copy number
				true);                 //overlaps checking


	//------------------------------------------------------
	G4Material* detector_mat = nist -> FindOrBuildMaterial("G4_MYLAR");
	G4double detector_size = 5*mm;
	G4double detector_offset_z = 1*mm;
	//---------------Mylar Thick ---------------------------//
	G4double detector_Thick = 50*um;
	// -----------------------------------------------------
	
	//////////////////////////////////////////////
	// Detector(Mylar1)							//
	//////////////////////////////////////////////
	G4Box* solidDetector1 =    
		new G4Box("Detector1",
				0.5*detector_size,
				0.5*detector_size,
				0.5*detector_Thick);

	G4LogicalVolume* logicDetector1 =                         
		new G4LogicalVolume(solidDetector1,
				detector_mat,
				"Detector1");

	new G4PVPlacement(0,
			G4ThreeVector(0,0,detector_offset_z),
			logicDetector1,
			"Detector1",
			logicWorld,
			false,
			1,
			true);
	//////////////////////////////////////////////
	// Detector(Mylar2)							//
	//////////////////////////////////////////////
	G4Box* solidDetector2 =
        new G4Box("Detector2",
                0.5*detector_size,
                0.5*detector_size,
                0.5*detector_Thick);

    G4LogicalVolume* logicDetector2 =
        new G4LogicalVolume(solidDetector2,
                detector_mat,
                "Detector2");

    new G4PVPlacement(0,
            G4ThreeVector(0,0,detector_offset_z+5*mm),
            logicDetector2,
            "Detector2",
            logicWorld,
            false,
            2,
            true);
	//////////////////////////////////////////////
	// Detector(Mylar3)							//
	//////////////////////////////////////////////
	G4Box* solidDetector3 =
        new G4Box("Detector3",
                0.5*detector_size,
                0.5*detector_size,
                0.5*detector_Thick);

    G4LogicalVolume* logicDetector3 =
        new G4LogicalVolume(solidDetector3,
                detector_mat,
                "Detector3");

    new G4PVPlacement(0,
            G4ThreeVector(0,0,detector_offset_z+10*mm),
            logicDetector3,
            "Detector3",
            logicWorld,
            false,
            3,
            true);
	//////////////////////////////////////////////
	// Detector(Mylar4)							//
	//////////////////////////////////////////////
	G4Box* solidDetector4 =
        new G4Box("Detector4",
                0.5*detector_size,
                0.5*detector_size,
                0.5*detector_Thick);

    G4LogicalVolume* logicDetector4 =
        new G4LogicalVolume(solidDetector4,
                detector_mat,
                "Detector4");

    new G4PVPlacement(0,
            G4ThreeVector(0,0,detector_offset_z+15*mm),
            logicDetector4,
            "Detector4",
            logicWorld,
            false,
            4,
            true);

	return physWorld;

}
