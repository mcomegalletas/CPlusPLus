#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <string>

using namespace std;

class Banco
{
	protected:
		int	codigo, pin;

	public:
		Banco();
		Banco(int pcodigo, int ppin);
		~Banco();

		void setcodigo(int pcodigo);
		void setpin(int ppin);
		int getcodigo();
		int getpin();

		virtual void MostrarDatos();
		virtual long Depositar(long x);
		virtual long Retirar(long x);

};
#endif // !BANCO_H
