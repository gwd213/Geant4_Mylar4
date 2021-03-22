# Geant4_Mylar #


## �ʿ� Package ##
- CLHEP(2.4.4.1)
- ROOT v.6.22.06
- Geant4 1.10.6
- QT(���û���)

ROOT�� ��� �� ���� ������ ����ص� �ǳ�, ������ ���� ���ɼ��� ����.(���� �ڵ���� ������)

## ������ ##

    $ git clone https://github.com/gwd213/Geant4_Mylar.git
    $ cd Geant4_Mylar
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make -j(core number)
  
  **run with macro file**  
    
    $ ./example myrun

## src directory ##

	1) BDCDetectorConstruction.cc

	- **Mylar �β�,������ ���� ����** 

	default : detector_size = 5mm,detector_Thick=50um
	
	- **Mylar ��ġ ���� ����**
	
	default : detector_offset_z = 1mm 
	(Ư���� ���� ���ٸ�,  z�� ��ġ ���� �������� �ʾƵ� �ȴ�)

	2) BDCPrimaryGeneratorAction.cc
	
	- **Ion ���� ���� ����**

	default : GetIon(50,132,0) 132Sn

	- **Kinetic Energy ���� ����**
	
	default : kineticEnergy = 200.MeV

##macro file(myrun)##

	$ ./example myrun -> myrun.root�� ������ ����
	
	**Runnumber ���� ����##
	
	$ vi myrun
	$ run/beamOn 200000(number of event)


