#ifndef TRASLADO_H
#define TRASLADO_H
#include "Usuario.h"
#include "Vehiculo.h"
#include "Sector.h"

using namespace std;

class Traslado{
	private:
		int _id;
		Usuario _usuario;
	    Vehiculo _vehiculo;
	    Sector _sectorOrigen; 
	    Sector _sectorDestino; 
	    string _fecha;
	    string _estado;
	
	public:
		Traslado(){
			_id = 0;
			_fecha = "";
			_estado = "";
		}
		Traslado(int id, Usuario usuario, Vehiculo vehiculo, Sector sectorOrigen, Sector sectorDestino, std::string fecha, std::string estado) {
	        this->_id = id;
	        _usuario = usuario; 
	        this->_vehiculo = vehiculo; 
	        this->_sectorOrigen = sectorOrigen; 
	        this->_sectorDestino = sectorDestino; 
	        this->_fecha = fecha;
	        this->_estado = estado;
	    }

		void setId(int id){
			this->_id = id;
		}
		void setUsuario(Usuario usuario){
			this->_usuario = usuario;
		}
		void setVehiculo(Vehiculo vehiculo){
			this->_vehiculo = vehiculo;
		}
		void setSectorOrigen(Sector sectorOrigen){
			this->_sectorOrigen = sectorOrigen;
		}
		void setSectorDestino(Sector sectorDestino){
			this->_sectorDestino = sectorDestino;
		}
		void setFecha(string fecha){
			this->_fecha = fecha;
		}
		void setEstado(string estado){
			this->_estado = estado;
		}
		int getId(){
			return this->_id;
		}
		Usuario getUsuario(){
			return this->_usuario;
		}
		Vehiculo getVehiculo(){
			return this->_vehiculo;
		}
		Sector getSectorOrigen(){
			return this->_sectorOrigen;
		}
		Sector getSectorDestino(){
			return this->_sectorDestino;
		}
		void solicitar() {
			
		}
	    void seleccionarVehiculo() {
	    	
		}
	    void finalizar() {
	    	
		}
};
#endif
