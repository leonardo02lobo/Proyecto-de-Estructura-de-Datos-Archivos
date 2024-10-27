#include <iostream>
#include <windows.h>
#include <fstream> 
#include <vector>
#include <string>
#include "Usuario.h"
#include "Vehiculo.h"
#include "Chofer.h"
#include "Sector.h"
#include "Traslado.h"
#include "Estadisticas.h"
#include "Sectores.h"
 
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 

using namespace std;

void Menu();
void MenuGestion();
void MenuServicios(); 
void MenuModificarDatos(Usuario u, Vehiculo v);
fstream archivo("Datos.txt",ios::in | ios::out | ios::app);

int main(int argc, char** argv) {
	if(!archivo.is_open()){
		cout<<"Error al abrir el archivo"<<endl;
	}
	Menu();
	return 0;
}

void Menu(){
	int opcion = 0;
	do{
		do{
			fflush(stdin);
			gotoxy(40,2);
			cout<<"Cual opcion quiere elegir"<<endl;
			gotoxy(40,4);
			cout<<"1. Gestion de Datos"<<endl;
			gotoxy(40,6);
			cout<<"2. Servicios Diarios"<<endl;
			gotoxy(40,8);
			cout<<"Ingrese la opcion: "<<endl;
			gotoxy(40,10);
			cin>>opcion;

			if(opcion < 1 || opcion > 3){
				gotoxy(40,12);
				cout<<"La opcion ingresa es invalida"<<endl;
				system("pause");
			}	
			system("cls");
		}while(opcion < 1 || opcion > 3);
		switch(opcion){
			case 1:
				MenuGestion();
				break;
			case 2:
				MenuServicios();
				break;
			case 3:
				cout<<"Hasta luego"<<endl;
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 3);
}

void MenuGestion(){
	int opcion = 0;
	Usuario usuario;
	Vehiculo vehiculo;
	do{
		do{
			fflush(stdin);
			gotoxy(40,2);
			cout<<"Cual opcion quiere elegir"<<endl;
			gotoxy(40,4);
			cout<<"1. Agregar Datos"<<endl;
			gotoxy(40,6);
			cout<<"2. Modificar Datos"<<endl;
			gotoxy(40,8);
			cout<<"3. Consultar Datos"<<endl;
			gotoxy(40,10);
			cout<<"4. Eliminar Datos"<<endl;
			gotoxy(40,12);
			cout<<"5. Salir"<<endl;
			gotoxy(40,14);
			cout<<"Ingrese la opcion: "<<endl;
			gotoxy(40,16);
			cin>>opcion;

			if(opcion < 1 || opcion > 5){
				gotoxy(40,18);
				cout<<"La opcion ingresa es invalida"<<endl;
				system("pause");	
			}
			system("cls");	
		}while(opcion < 1 || opcion > 5);
		switch(opcion){
			case 1:	
					usuario.AgregarUsuario(archivo);
					vehiculo.AgregarVehiculo(archivo);
					archivo<<"\n";
					archivo.close();
				break;
				
			case 2:
				MenuModificarDatos(usuario,vehiculo);
				break;
			
			case 3: {
				string cedula;
				bool band = false;
				char* datos;
				fflush(stdin);
				cout<<"Ingrese la cedula a consultar los datos: ";
				getline(cin,cedula);
				
				string cedulaRegistrada;
				archivo.seekp(0);
				while(getline(archivo,cedulaRegistrada)){
					char* cedulaRegistradaCStr = const_cast<char*>(cedulaRegistrada.c_str());
					datos = strtok(cedulaRegistradaCStr,":");
					if(cedula == datos){
						band = true;
						break;
					}
				}
				
				if(band){
					cout<<"\nDatos encontrados\n"<<endl;
					usuario.setCedula(atoi(datos));
					datos = strtok(NULL,":");
					usuario.setNombre(datos);
					datos = strtok(NULL,":");
					usuario.setDireccion(datos);
					usuario.ConsultarUsuario();
					cout<<endl;
					datos = strtok(NULL,":");
					vehiculo.setPlaca(datos);
					datos = strtok(NULL,":");
					vehiculo.setModelo(datos);
					datos = strtok(NULL,":");
					vehiculo.setMarca(datos);
					datos = strtok(NULL,":");
					vehiculo.setAnio(atoi(datos));
					datos = strtok(NULL,":");
					bool disponible = (atoi(datos) == 1) ? true : false;
					vehiculo.setDisponible(disponible);
					datos = strtok(NULL,":");
					string idSector = datos;
					datos = strtok(NULL,":");
					string nombreSector = datos;
					vehiculo.setSectorActual(Sector(atoi(idSector.c_str()),nombreSector));
					vehiculo.ConsultarVehiculo();
				}else{
					cout<<"La cedula no coincide con ninguna de las registradas"<<endl;
				}
				break;
			}				
			case 4:{
					string cedula;
					string linea;
				    fstream temp;
				    bool encontrado = false;
				    temp.open("Temporal.txt",ios::in | ios::out | ios::app);
	
					fflush(stdin);
					cout<<"Ingrese la cedula para eliminar los datos: ";
					getline(cin,cedula);
			    
			    	while (getline(archivo, linea)) {
			    		char* cedulaRegistradaCStr = const_cast<char*>(linea.c_str());
						char* datos = strtok(cedulaRegistradaCStr,":");
						if(datos != cedula){
							temp<<linea<<endl;
						}else{
							encontrado = true;
						}
			        }
				    archivo.close();
				    temp.close();
				    
				    remove("Datos.txt");
				    rename("Temporal.txt","Datos.txt");
				    if (encontrado) {
				        cout << "Registro eliminado." << endl;
				    } else {
				        cout << "Registro no encontrado." << endl;
				    }
				break;
			}
			case 5:
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 5);
}

void MenuServicios(){
	int opcion = 0;
	do{
		do{
			fflush(stdin);
			gotoxy(40,2);
			cout<<"Cual opcion quiere elegir"<<endl;
			gotoxy(40,4);
			cout<<"1.Actualizar Ubicacion Vehiculo"<<endl;
			gotoxy(40,6);
			cout<<"2. Solicitar Traslado"<<endl;
			gotoxy(40,8);
			cout<<"3. Seleccionar vehiculo"<<endl;
			gotoxy(40,10);
			cout<<"4. Finalizar Traslado"<<endl;
			gotoxy(40,12);
			cout<<"5. Salir"<<endl;
			gotoxy(40,14);
			cout<<"Ingrese la opcion: "<<endl;
			gotoxy(40,16);
			cin>>opcion;

			if(opcion < 1 || opcion > 5){
				gotoxy(40,18);
				cout<<"La opcion ingresa es invalida"<<endl;
				system("pause");	
			}	
			system("cls");
		}while(opcion < 1 || opcion > 5);
		switch(opcion){
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
		}
		system("pause");
		system("cls");
	}while(opcion != 5);
}

void MenuModificarDatos(Usuario u, Vehiculo v){
	int opcion = 0;
	do{
		do{
			fflush(stdin);
			gotoxy(40,2);
			cout<<"Cual opcion quiere elegir"<<endl;
			gotoxy(40,4);
			cout<<"1. Modificar Datos Personales"<<endl;
			gotoxy(40,6);
			cout<<"2. Modificar Datos del Vehiculo"<<endl;
			gotoxy(40,8);
			cout<<"3. Salir"<<endl;
			gotoxy(40,10);
			cout<<"Ingrese la opcion: "<<endl;
			gotoxy(40,12);
			cin>>opcion;

			if(opcion < 1 || opcion > 3){
				gotoxy(40,14);
				cout<<"La opcion ingresa es invalida"<<endl;
				system("pause");	
			}	
			system("cls");
		}while(opcion < 1 || opcion > 3);
		switch(opcion){
			case 1:
				u.ModificarUsuario(archivo);
				break;
			case 2:
				v.ModificarVehiculo(archivo);
				break;
			case 3:
				cout<<"Volver al menu anterior..."<<endl;
				break; 
		}
		system("pause");
		system("cls");
	}while(opcion != 3);
}
