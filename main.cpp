#include "Banco.h"
#include "Cliente.h"
#include "Cuenta.h"
#include <time.h>

int main()
{
	Banco *pObjBan [10];
	Cliente *pObjCliente[10];
	Cuenta *pObjCuenta[10];

	setlocale(LC_CTYPE, "Spanish");
	int edad;
	string  nombre[10], direccion;
	string *pnombre = &nombre[0];
	long numtarjeta, valor, cedula;
	int codigo[10], pin[10];
	int *pcodigo = &codigo[0], *ppin =&pin[0];
	long long numCuenta[10], saldo[10];
	long long *pnumCuenta = &numCuenta[0], *psaldo = &saldo[0];
	int existe = -1, veripin, opcion = 0, opcionuser = 0, i = 0, tempusuario, transaccion, vericontra;
	do
	{
		srand(time(NULL));
		system("cls");
		cout << "\t ~ ~ ~ BANCOYA ~ ~ ~" << endl;
		cout << "\n1. CREAR UN USUARIO\n2. INGRESAR USUARIO\n3. SALIR\n\n";
		cout << "Por favor, ingrese una opción: ";
		cin >> opcion;
		switch (opcion)
		{

		case 1:
		{
			if (i == 10)
			{
				cout << "Lo sentimos, no pueden crearse más cuentas.\n";
				break;
			}
			cout << "\nA continuación se creará una cuenta.\n\n";
			cout << "NOMBRE PROPIETARIO: ";
			rewind(stdin);
			getline(cin, nombre[i]);
			cout << "EDAD: ";
			cin >> edad;
			cout << "CIUDAD: ";
			rewind(stdin);
			getline(cin, direccion);
			cout << "NUMERO IDENTIFICACION: ";
			rewind(stdin);
			cin >> cedula;
			cout << "\nPIN TARJETA [CUATRO DIGITOS]: ";
			cin >> pin[i];
			cout << "VERIFICAR PIN: ";
			cin >> veripin;
			while (pin[i] != veripin)
			{
				cout << "ERROR: PINES INGRESADOS NO CONCUERDAN...\n";
				cout << "PIN: ";
				cin >> pin[i];
				cout << "VERIFICAR PIN: ";
				cin >> veripin;
			}
			numtarjeta = rand() * 12345;
			numCuenta[i] = rand() * 12345;
			codigo[i] = rand();
			if (codigo[i] >= 9999)
			{
				
				codigo[i] = codigo[i] % 10000;
			}
			else if (codigo[i] < 1000)
			{
				codigo[i] = codigo[i] * 7;
			}
			saldo[i] = 500000;
			system("cls");
			cout << "\n¡USUARIO CREADO!\n\n";
			pObjBan[i] = new Cliente(codigo[i], pin[i], nombre[i], direccion, edad, cedula, numtarjeta);
			pObjBan[i] = new Cuenta(codigo[i], pin[i], nombre[i], direccion, edad, cedula, numtarjeta, *(pnumCuenta+i), *(psaldo+i));
			pObjBan[i]->MostrarDatos();
			i++;
			break;
		}
		case 2:
			{
				if (i==0)
				{
					cout << "ERROR: No hay usuarios en el sistema. ";
					system("pause");
					break;
				}
					cout << "CODIGO USUARIO: ";
					cin >> tempusuario;
					for (int j = 0; j <= i; j++)
					{
						if ( tempusuario == (*(pcodigo+j)))
						{
							existe = j;
						}
					}
					if (existe == -1)
					{
						cout << "EL CODIGO INGRESADO NO EXISTE.\nSerá redirigido al menu principal.";
						system("pause");
						break;
					}
				cout << "CONTRASEÑA: ";
				cin >> vericontra;
				while ((pObjBan[existe]->getpin()) != vericontra)
				{
					cout << "CONTRASEÑA INCORRECTA. Intente de nuevo: ";
					cin >> vericontra;
				}
				do {
					cout << "\n\n ~ ~ ~ BANCOYA ~ ~ ~\n\n" << endl;
					cout << "Bienvenido, " << *(pnombre+existe) << endl;
					cout << "\n1.DEPOSITAR/ RETIRAR \n2. SOBRE EL USUARIO \n3. SALIR DE LA CUENTA\n\n";
					cout << "Por favor, ingrese una opción: ";
					cin >> opcionuser;
					switch (opcionuser)
					{	
						case 1:
						{
							cout << "\n\nTRANSACCIONES CUENTA\n\n1.DEPOSITAR\n2. RETIRAR\n3. VOLVER\n\n";
							cout << "Por favor, ingrese una opción: ";
							cin >> transaccion;
							if (transaccion == 1)
							{
								cout << "Ingrese el valor a depositar: $";
								cin >> valor;
								cout << "TRANSACCION FINALIZADA.\nSALDO ACTUAL: $" << pObjBan[existe]->Depositar(valor) << endl;
							}
							else if (transaccion == 2)
							{
								cout << "Ingrese el valor a retirar: $";
								cin >> valor;

								if (valor > *(psaldo+existe))
								{
									cout << "Lo sentimos, no tiene saldo suficiente para hacer este proceso.\n Será redirigido al menu principal. ";
									system("pause");
									break;
								}
								cout << "TRANSACCION FINALIZADA.\nSALDO ACTUAL: $" << pObjBan[existe]->Retirar(valor) << endl;	
							}
							system("pause");
							break;
						}

						case 2:
						{
							system("cls");
							cout << "\tINFORMACION DE LA CUENTA\n\n\n";
							pObjBan[existe]->MostrarDatos();
							break;
						}
					}
				} while (opcionuser!=3);
				existe = -1;
			}
		}
	} while (opcion!=3);
	cout << endl << endl;
	system("pause");
	return 0;
}