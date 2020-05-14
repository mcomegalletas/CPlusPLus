#include "Banco.h"

Banco::Banco()
{
	codigo = 0;
	pin=0;
}

Banco::Banco(int pcodigo, int ppin)
{
	codigo = pcodigo;
	pin = ppin;
}

Banco::~Banco()
{
}

void Banco::setcodigo(int pcodigo)
{
	codigo = pcodigo;
}

void Banco::setpin(int ppin)
{
	pin = ppin;
}

int Banco::getcodigo()
{
	return codigo;
}

int Banco::getpin()
{
	return pin;
}

void Banco::MostrarDatos()
{
	cout << "\nCODIGO USUARIO: " << getcodigo() << "\nPIN: " << getpin() << "\n\n";
}

long Banco::Depositar(long x)
{
	return 0;
}

long Banco::Retirar(long x)
{
	return 0;
}
