#ifndef BDCDETECTORCONSTRUCTION_HH
#define BDCDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class BDCDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    BDCDetectorConstruction();
    virtual ~BDCDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
};

#endif
