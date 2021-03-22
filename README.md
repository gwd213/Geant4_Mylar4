# Geant4_Mylar #


## 필요 Package ##
- CLHEP(2.4.4.1)
- ROOT v.6.22.06
- Geant4 1.10.6
- QT(선택사항)

ROOT의 경우 더 낮은 버전을 사용해도 되나, 문제가 생길 가능성이 있음.(현재 코드상은 괜찮다)

## 실행방법 ##

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

	- **Mylar 두께,사이즈 변경 가능** 

	default : detector_size = 5mm,detector_Thick=50um
	
	- **Mylar 위치 변경 가능**
	
	default : detector_offset_z = 1mm 
	(특별한 일이 없다면,  z축 위치 제외 변경하지 않아도 된다)

	2) BDCPrimaryGeneratorAction.cc
	
	- **Ion 종류 변경 가능**

	default : GetIon(50,132,0) 132Sn

	- **Kinetic Energy 변경 가능**
	
	default : kineticEnergy = 200.MeV

##macro file(myrun)##

	$ ./example myrun -> myrun.root의 파일을 생성
	
	**Runnumber 변경 가능##
	
	$ vi myrun
	$ run/beamOn 200000(number of event)


