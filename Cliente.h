#include "Banco.h"
#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente:public Banco
{
	private:
		string nombre, direccion;
		int edad;
		long numtarjeta, cedula;

	public:
		Cliente();
		Cliente(int pcodigo, int ppin, string pnombre, string pdireccion, int pedad, long pcedula, long pnumtarjeta);
		~Cliente();
		void setnombre(string pnombre);
		void setdireccion(string pdireccion);
		void setedad(int pedad);
		void setcedula(long pcedula);
		void setnumtarjeta(long pnumtarjeta);
		string getnombre();
		string getdireccion();
		int getedad();
		long getcedula();
		long getnumtarjeta();

		void MostrarDatos();

};
#endif
