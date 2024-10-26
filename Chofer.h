#ifndef CHOFER_H
#define CHOFER_H
#include<cstring>

using namespace std;

class Chofer{
	private:
		string _nombreConductor;
	public:
		Chofer(){
			_nombreConductor = "";
		}
		Chofer(string nombreConductor){
			_nombreConductor = nombreConductor;
		}
		void setNombreConductor(string nombreConductor){
			_nombreConductor = nombreConductor;
		}
		string getNombreConductor(){
			return _nombreConductor;
		}
		
		void AsginarVehiculo(fstream& archivo){
			
		}
};
#endif
