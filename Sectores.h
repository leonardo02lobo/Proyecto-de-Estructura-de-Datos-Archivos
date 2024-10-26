#ifndef SECTORES_H
#define SECTORES_H
#include "Sector.h"
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Sectores{
	public:
		vector<string> sectores;
		vector<int> idSectores;
	    int numSectores;
	    
	    Sectores(){
	    	sectores.push_back("Barrio Obrero");
	    	sectores.push_back("Pirineos");
	    	sectores.push_back("Centro");
	    	sectores.push_back("La Concordia");
	    	sectores.push_back("Los Chaguaramos");
	    	sectores.push_back("San Juan");
	    	sectores.push_back("El Cementerio");
	    	sectores.push_back("La Castra");
	    	sectores.push_back("La Popa");
	    	sectores.push_back("Las Acacias");
	    	sectores.push_back("El Estadio");
	    	sectores.push_back("La Florida");
	    	sectores.push_back("Santa Teresa");
	    	sectores.push_back("El Reloj");
	    	
	    	idSectores.push_back(1);
	    	idSectores.push_back(2);
	    	idSectores.push_back(3);
	    	idSectores.push_back(4);
	    	idSectores.push_back(5);
	    	idSectores.push_back(6);
	    	idSectores.push_back(7);
	    	idSectores.push_back(8);
	    	idSectores.push_back(9);
	    	idSectores.push_back(10);
	    	idSectores.push_back(11);
	    	idSectores.push_back(12);
	    	idSectores.push_back(13);
	    	idSectores.push_back(14);
	    	
			numSectores = sectores.size();
		}
    
    void DistribuirSectores(Sector* sector){
    	int random = rand() % numSectores;
    	sector->setNombreSector(sectores[random]);
    	sector->setId(idSectores[random]);
	}
};
#endif
