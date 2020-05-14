#include "Cliente.h"

class Cuenta: public Cliente
{
	private:
		long long numCuenta = 0, saldo = 0; 
	public:
		Cuenta();
		Cuenta(int pcodigo, int ppin, string pnombre, string pdireccion, int pedad, long pcedula, long pnumtarjeta, long long pnumCuenta, long long psaldo);
		~Cuenta();

		void setnumCuenta(long long pnumCuenta);
		void setsaldo(long long psaldo);

		long long getnumCuenta();
		long long getsaldo();

		long Depositar(long x);
		long Retirar(long x);
		void MostrarDatos();


};

