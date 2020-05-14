#include "Cuenta.h"

Cuenta::Cuenta(): Cliente()
{
	numCuenta = 0;
		saldo = 0;
}

Cuenta::Cuenta(int pcodigo, int ppin, string pnombre, string pdireccion, int pedad, long pcedula, long pnumtarjeta, long long pnumCuenta, long long psaldo) 
	: Cliente(pcodigo, ppin, pnombre,  pdireccion, pedad, pcedula, pnumtarjeta)
{
	numCuenta = pnumCuenta;
	saldo = psaldo;
}

Cuenta::~Cuenta()
{
}

void Cuenta::setnumCuenta(long long pnumCuenta)
{
	numCuenta = pnumCuenta;
}

void Cuenta::setsaldo(long long psaldo)
{
	saldo = psaldo;
}

long long Cuenta::getnumCuenta()
{
	return numCuenta;
}

long long Cuenta::getsaldo()
{
	return saldo;
}

long Cuenta::Depositar(long x)
{
	long valor=0;
	Banco::Depositar(x);
	valor = getsaldo() + x;
	setsaldo(valor);
	return getsaldo();
}

long Cuenta::Retirar(long x)
{
	long valor = 0;
	Banco::Retirar(x);
	valor = getsaldo() + (-1*x);
	setsaldo(valor);
	return getsaldo();
}

void Cuenta::MostrarDatos()
{
	Banco::MostrarDatos();
	Cliente::MostrarDatos();
	cout << "\nNUMERO DE CUENTA: " << getnumCuenta() << "\nSALDO: $" << getsaldo()<< endl;
	system("pause");
}
