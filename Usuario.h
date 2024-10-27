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
			
			archivo<<getCedula()<<":"<<getNombre()<<":"<<getDireccion()<<":";
		}
		
		void ModificarUsuario(fstream& archivo) {
		    int opcion = 0;
		    string antiguo,nuevo;

		    cout << "Que quieres modificar?: " << endl;
		    cout << "1. Nombre\n2. Cedula\n3. Direccion\nElegir la opcion: ";
		    cin >> opcion;
		
		    switch (opcion) {
		        case 1: {
		            fflush(stdin);
		            cout << "Digite el antiguo nombre: ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite el nuevo nombre: ";
		            getline(cin, nuevo);		
		            break;
		        }
		        case 2: {
		            fflush(stdin);
		            cout << "Digite la antigua Cedula: ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite la nueva Cedula: ";
		            getline(cin, nuevo);
		            break;
		        }
		        case 3: {
		            fflush(stdin);
		            cout << "Digite la antigua direccion: ";
		            getline(cin, antiguo);
		            
		            fflush(stdin);
		            cout << "Digite la nueva direccion: ";
		            getline(cin, nuevo);
		            break;
		        }
		    }
		    fflush(stdin);
		    modificarElemento(antiguo,nuevo,archivo);
		}
		
		void ConsultarUsuario(){
			cout<<"Datos del Usuario"<<endl;
			cout<<"Nombre: "<<getNombre()<<endl;
			cout<<"Cedula: "<<getCedula()<<endl;
			cout<<"Direccion: "<<getDireccion()<<endl;
		}
		void EliminarUsuario(fstream& archivo){
			
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
