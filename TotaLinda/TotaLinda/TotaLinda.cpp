#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>

#define MAX 25
#define VACIO NULL

using namespace std;

//arreglar sistema de asignado de jubilación. 

struct empleado
{
	string DNI;
	string estado; //s="soltero", c="casado", v="viudo"
	string direccion;
	string tel;
	string sexo;
	char nombre[50];
	int edad;
	bool jubilarse=0;
};

	void jubilarse (bool &jubilarse,string sexo,int edad)
	{
	    if (((sexo == "H" || sexo == "h") && edad >= 55) || ((sexo == "m" || sexo == "M") && edad >= 60))
        {
            jubilarse = 1;

        }
        return;
	}


void inicializarVec(empleado e[], empleado jub[])
{
	for (int i = 0; i < MAX; i++)
	{
		(*(e + i)).DNI = "NULL";
		(*(e + i)).nombre[0] = NULL;
		(*(jub + i)).nombre[1] = NULL;

	}
}

void ingresarEmpleado(empleado e[], int& pos, empleado vec[], int& j)
{
	cin.get();
	if (pos < MAX)
	{
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << "Ingrese, con el siguiente formato, el DNI del empleado: xx.xxx.xxx: ";
		getline(cin, e[pos].DNI);

		char nom = NULL;
		cout << endl << "Ingrese el nombre y apellido del empleado: ";
		for (short i = 0; i < 50 && nom != 13; i++)
		{
			nom = _getche();
			if (nom==8 && i>0)
            {
                i--;
                e[pos].nombre[i]=VACIO;
                i--;
            }
            else
                e[pos].nombre[i] = nom;
                if (e[pos].nombre[i]==13)
                {
                    e[pos].nombre[i+1]=13;
                }
		}

		cout<<endl;
		cout << endl << "Ingrese el estado civil del empleado. " << endl << "S: Soltero/a." << endl << "C: Casado/a." << endl << "V: Viudo/a." << endl;
		getline(cin, e[pos].estado);

		cout << endl << "Ingrese la direccion del empleado: ";
		getline(cin, e[pos].direccion);

		cout << endl << "Ingrese el telefono del empleado: ";
		getline(cin, e[pos].tel);

		cout << endl << "Ingrese el sexo del empleado, M=mujer, H=hombre: ";
		getline(cin, e[pos].sexo);
		while (e[pos].sexo!="h" && e[pos].sexo!="H" && e[pos].sexo!="M" && e[pos].sexo!="m")
        {
            cout << endl << "Ingrese el sexo del empleado, M=mujer, H=hombre: ";
            getline(cin, e[pos].sexo);
        }

		cout << endl << "Ingrese la edad del empleado: ";
		cin >> e[pos].edad;
		while (e[pos].edad<=0)
        {
            cout << endl << "Ingrese la edad del empleado, no puede ser menor de cero: ";
            cin >> e[pos].edad;
        }

		cout << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		cout << endl << endl << endl;

        jubilarse(e[pos].jubilarse,e[pos].sexo,e[pos].edad);

		if (e[pos].jubilarse == 1)
		{
			for (int h = 0; h < 50 && e[pos].nombre[h]!=13; h++)
			{
				vec[j].nombre[h] = e[pos].nombre[h];
			}
			j++;
		}

	}
	else
		cout << "Se han ingresado la maxima cantidad de empleados." << endl;

	pos++;
	cin.get();
	return;
}

void datosEmpleado(empleado e[])
{
	cin.get();
	string dni;
	cout << "Ingrese el DNI del empleado, de la siguiente manera: xx.xxx.xxx: ";
	getline(cin, dni);

	cout << endl << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < MAX; i++)
	{
		if (dni.compare(e[i].DNI) == 0)
		{
			cout << "Nombre: ";

			for (int j = 0; j < 50 && e[i].nombre[j] != 13; j++)
			{
				cout << e[i].nombre[j];
			}

			cout << endl << "Estado: " << e[i].estado << endl << "Direccion: " << e[i].direccion << endl << "Telefono: " << e[i].tel << endl << "Sexo: " << e[i].sexo << endl << "Edad: " << e[i].edad << endl;

			cout << "--------------------------------------------------------------------------------" << endl;
			return;
		}
	}
	cout << "No se ha encontrado nadie con ese DNI." << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	return;
}

void edadPromedio(empleado e[], int pos)
{
	cin.get();
	double total = 0;
	for (int i = 0; i < pos + 1; i++)
	{
		total += e[i].edad;
	}
	cout << endl << "--------------------------------------------------------------------------------" << endl;
	cout << "La edad promedio es " << total / (pos) << " anos." << endl;
	cout << endl << "--------------------------------------------------------------------------------" << endl << endl << endl;
}

void ordenar(empleado vec[])
{
	empleado aux;
	for (int j = 0; j < MAX; j++)
	{
		for (int i = 0; i < MAX - j - 1; i++)
		{
			int h=0;
			while (vec[i].nombre[h] == vec[i+1].nombre[h])
			{
				h++;
			}
			if (vec[i + 1].nombre[h] > vec[i].nombre[h])
			{
                aux = vec[i];
				vec[i] = vec[i + 1];
				vec[i + 1] = aux;
			}

			h=0;
		}
	}
	return;
}


void jubilacion(empleado jub[])
{
	ordenar(jub);
	cout<<"-------------------------------------------------------------------------------------------"<<endl;
	for (int i = MAX; i >=0; i--)
	{
		//if (jub[i].nombre[0] == NULL)
        //{
          //  return;
        //}

        if (jub[i].nombre[1] != NULL)
        {
            cout << "Nombre: ";
            for (int j = 0; j < MAX && jub[i].nombre[j] != NULL; j++)
            {
                cout << jub[i].nombre[j];
            }
            cout<<endl<<"-------------------------------------------------------------------------------------------";

        }
	}
	cout << endl<<endl<<endl;
}

void mostrarMenu()
{
	char menu;
	empleado e[MAX];
	int pos = 0;
	int j = 0;
	empleado retirar[MAX];

	inicializarVec(e, retirar);


	do
	{
		cout << "a-Ingresar un empleado." << endl << "b-Datos del empleado." << endl << "c-Edad promedio de los empleados" << endl << "d-Listado de los emmpleados que esten proximos a jubilarse. " << endl <<"ESC- Cerrar el programa."<< endl;
		menu = _getche();
		cout << endl << endl;
		switch (menu)
		{
		case 'a':case 'A':
			ingresarEmpleado(e, pos, retirar, j);
			break;
		case 'b': case 'B':
			datosEmpleado(e);
			break;
		case 'c': case 'C':
			edadPromedio(e, pos);
			break;
		case 'd': case'D':
			jubilacion(retirar);
			break;
		case (char)27:
			break;
		}
	} while (menu != 27);
}

int main()
{
	mostrarMenu();
	return 0;
}
