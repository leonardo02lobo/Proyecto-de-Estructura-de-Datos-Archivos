#ifndef USUARIO_H
#define USUARIO_H
#include<cstring>
#include<fstream>

using namespace std;

class Usuario{
	private:
		int _cedula;
		string _nombre;
		string _direccion;
	public:
		Usuario(){
			_cedula = 0;
			_nombre = "";
			_direccion = "";
		}
		Usuario(int cedula,string nombre,string direccion){
			this->_cedula = cedula;
			this->_nombre = nombre;
			this->_direccion = direccion;
		}
		void setCedula(int cedula){
			this->_cedula = cedula;
		}
		void setNombre(string nombre){
			this->_nombre = nombre;
		}
		void setDireccion(string direccion){
			this->_direccion = direccion;
		}
		int getCedula(){
			return this->_cedula;
		}
		string getNombre(){
			return this->_nombre;
		}
		string getDireccion(){
			return this->_direccion;
		}
		
		void AgregarUsuario(fstream& archivo){
			cout<<"Agregar Usuario"<<endl<<endl;
			fflush(stdin);
			cout<<"Ingrese su nombre: ";
			getline(cin,_nombre);
			fflush(stdin);
			cout<<"Ingrese su cedula: ";
			cin>>_cedula;
			fflush(stdin);
			cout<<"Ingrese su direccion: ";
			getline(cin,_direccion);
			
			archivo<<getCedula()<<":"<<getNombre()<<":"<<getDireccion()<<",";
		}
		
		void ModificarUsuario(fstream& archivo){
			string linea;
			getline(archivo,linea);
			int opcion;
			
			cout<<"Que quieres modificar?: "<<endl;
			cout<<"1. Nombre\n2. Cedula\n3. Direccion\nElegir la opcion: ";
			cin>>opcion;
			
			switch(opcion){
				case 1:
					//prueba para separar datos
					string cadena = "Luis;Cabrera;luis@ejemplo.com;parzibyte.me";
				    stringstream input_stringstream(cadena);
				    string token;
				
				    while (getline(input_stringstream, token, ';')) {
				        cout << "Token: " << token <<endl;
				    }

					break;
				case 2:
					break;
				case 3:
					break;
			}
		}
		
		void ConsultarUsuario(fstream& archivo){
			
		}
		void EliminarUsuario(fstream& archivo){
			
		}
		
		void mostrar(){
			cout<<_nombre<<"  "<<_cedula<<endl;
		}
};
#endif