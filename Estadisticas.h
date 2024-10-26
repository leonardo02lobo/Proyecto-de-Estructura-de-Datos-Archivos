#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

using namespace std;

class Estadisticas {
	private:
	    int _vehiculosUsados; 
	    int _usuariosActivos; 

	public:
	    Estadisticas() {
	    	_vehiculosUsados = 0;
	    	_usuariosActivos = 0;
		}
		Estadisticas(int vehiculosUsados,int usuariosActivos) {
	    	this->_vehiculosUsados = vehiculosUsados;
	    	this->_usuariosActivos = usuariosActivos;
		}
	
	    void setVehiculosUsados(int vehiculosUsados){
	    	this->_vehiculosUsados = vehiculosUsados;
		}
		
		void setUsuariosActivos(int usuariosActivos){
	    	this->_usuariosActivos = usuariosActivos;
		}
		
	    int getVehiculosUsados() { 
			return this->_vehiculosUsados; 
		}
		
	    int getUsuariosActivos() {
	    	return this->_usuariosActivos;
		}
	    void generarReporte() {
		
		}
};
#endif
