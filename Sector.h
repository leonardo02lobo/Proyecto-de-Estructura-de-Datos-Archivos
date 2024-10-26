#ifndef SECTOR_H
#define SECTOR_H

class Sector{
	private:
		int _id;
		string _nombreSector;
	public:
		Sector(){
			_id = 0;
			_nombreSector = "";
		}
		Sector(int id,string nombreSector){
			this->_id = id;
			this->_nombreSector = nombreSector;
		}
		void setId(int id){
			this->_id = id;
		}
		void setNombreSector(string nombreSector){
			this->_nombreSector = nombreSector;
		}
		int getId(){
			return this->_id;
		}
		string getNombreSector(){
			return this->_nombreSector;
		}
};
#endif
