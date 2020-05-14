#include "Cliente.h"

Cliente::Cliente(): Banco()
{
	nombre = "";
	direccion = "";
	edad = 0;
	cedula = 0;
	numtarjeta = 0;
}

Cliente::Cliente(int pcodigo, int ppin, string pnombre, string pdireccion, int pedad, long pcedula, long pnumtarjeta) : Banco(pcodigo, ppin)
{
	nombre = pnombre;
	direccion = pdireccion;
	edad = pedad;
	cedula = pcedula;
	numtarjeta = pnumtarjeta;
}

Cliente::~Cliente()
{
}

void Cliente::setnombre(string pnombre)
{
	nombre = pnombre;
}

void Cliente::setdireccion(string pdireccion)
{
	direccion = pdireccion;
}

void Cliente::setedad(int pedad)
{
	edad = pedad;
}

void Cliente::setcedula(long pcedula)
{
	cedula = pcedula;
}

void Cliente::setnumtarjeta(long pnumtarjeta)
{
	numtarjeta = pnumtarjeta;
}

string Cliente::getnombre()
{
	return nombre;
}

string Cliente::getdireccion()
{
	return direccion;
}

int Cliente::getedad()
{
	return edad;
}

long Cliente::getcedula()
{
	return cedula;
}

long Cliente::getnumtarjeta()
{
	return numtarjeta;
}

void Cliente::MostrarDatos()
{
	cout << "NOMBRE USUARIO: " << getnombre() << "\nEDAD: " << getedad() << "\nCIUDAD: " << getdireccion() << endl;
	cout << "\nDOCUMENTO DE IDENTIFICACION: " << getcedula() << "\nNUMERO TARJETA: " << getnumtarjeta() <<endl ;
}


