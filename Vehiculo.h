#ifndef VEHICULO_H
#define VEHICULO_H
#include "Chofer.h"
#include "Sector.h"
#include "Sectores.h"
#include<cstring>

using namespace std;

class Vehiculo{
	private:
		string _placa;
		string _modelo;
		string _marca;
		int _anio;
		Chofer chofer;
		Sector _sectorActual;
		bool _disponible;
	public:
		Vehiculo(){
			_placa = "";
			_modelo = "";
			_marca = "";
			_anio = 0;
			_disponible = false;
		}
		Vehiculo(string placa,string modelo,string marca,int anio,Sector sectorActual,bool disponible){
			_placa = placa;
			_modelo = modelo;
			_marca = marca;
			_anio = anio;
			_sectorActual = sectorActual;
			_disponible = disponible;
		}
		void setPlaca(string placa){
			_placa = placa;
		}
		void setModelo(string modelo){
			_modelo = modelo;
		}
		void setMarca(string marca){
			_marca = marca;
		}
		void setAnio(int anio){
			_anio = anio;
		}
		void setSectorActual(Sector sectorActual){
			_sectorActual = sectorActual;
		}
		void setDisponible(bool disponible){
			_disponible = disponible;
		}
		string getPlaca(){
			return this->_placa;
		}
		string getModelo(){
			return this->_modelo;
		}
		string getMarca(){
			return this->_marca;
		}
		int getAnio(){
			return this->_anio;
		}
		Sector getSectorActual(){
			return this->_sectorActual;
		}
		bool getDisponible(){
			return this->_disponible;
		}
		void AgregarVehiculo(fstream& archivo){
			cout<<"Agregar Vehiculo"<<endl;
			Sectores sectores;
			sectores.DistribuirSectores(&_sectorActual);
			fflush(stdin);
			cout<<"Ingrese la placa del carro: ";
			getline(cin,_placa);
			fflush(stdin);
			cout<<"Ingrese el modelo de carro: ";
			getline(cin,_modelo);
			fflush(stdin);
			cout<<"Ingrese la marca del carro: ";
			getline(cin,_marca);
			fflush(stdin);
			cout<<"Ingrese el anio del carro: ";
			cin>>_anio;
			fflush(stdin);
			cout<<"Esta Disponible? \n1. Si\n2. No\nIngrese su opcion: ";
			int aux;
			cin>>aux;
			
			(aux == 1)? _disponible = true: _disponible = false;
			
			archivo<<getPlaca()<<":"<<getModelo()<<":"<<getMarca()<<":"<<getAnio()<<":"<<":"<<getDisponible()<<","<<getSectorActual().getId()<<":"<<getSectorActual().getNombreSector()<<".";
		}
		
		void ModificarVehiculo(fstream& archivo){
			int opcion = 0;
		    string antiguo,nuevo;

		    cout << "Que quieres modificar?: " << endl;
		    cout << "1. Placa\n2. Modelo\n3. Marca\n4. Anio\n5. Disponible\n6.Sector\nElegir la opcion: ";
		    cin >> opcion;
		
		    switch (opcion) {
		        case 1: {
		            fflush(stdin);
		            cout << "Digite la antigua placa: ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite ela nueva placa: ";
		            getline(cin, nuevo);		
		            break;
		        }
		        case 2: {
		            fflush(stdin);
		            cout << "Digite el antiguo modelo: ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite el nuevo modelo: ";
		            getline(cin, nuevo);
		            break;
		        }
		        case 3: {
		            fflush(stdin);
		            cout << "Digite la antigua marca: ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite la nueva marca: ";
		            getline(cin, nuevo);
		            break;
		        }
		        case 4: {
		            fflush(stdin);
		            cout << "Digite el antiguo anio: ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite el nuevo anio: ";
		            getline(cin, nuevo);
		            break;
		        }
		        case 5: {
		            fflush(stdin);
		            cout << "Digite la antigua disponibilidad (1 para si y 2 para no): ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite la nueva disponibilidad (1 para si y 2 para no): ";
		            getline(cin, nuevo);
		            break;
		        }
		        case 6: {
		            fflush(stdin);
		            cout << "Digite el antiguo sector: ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite el nuevo sector: ";
		            getline(cin, nuevo);
		            break;
		        }
		    }
		    fflush(stdin);
		    modificarElemento(antiguo,nuevo,archivo);
		}
		
		void ConsultarVehiculo(fstream& archivo){
			
		}
		void EliminarVehiculo(fstream& archivo){
			
		}
		void ActualizarUbicacionVehiculo(){
			
		}
		
		private:
			void modificarElemento(string antiguo, string nuevo,fstream& archivo){
				string linea;
			    fstream temp;
			    temp.open("Temporal.txt",ios::in | ios::out | ios::app);
		    
		    	while (getline(archivo, linea)) {
		            size_t pos = linea.find(antiguo);
		            while (pos != string::npos) {
		            	linea.replace(pos, antiguo.length(), nuevo);
		            	pos = linea.find(antiguo, pos + nuevo.length());
		            }
		            linea += "\n";
		            temp<<linea;
		        }
			    archivo.close();
			    temp.close();
			    
			    remove("Datos.txt");
			    rename("Temporal.txt","Datos.txt");
			}
};

#endif
