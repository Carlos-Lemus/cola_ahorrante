// Hecho por Carlos Alfonso Lemus Rodezno

//Programa que ingresa, muestra y elimina los datos de un ahorrante atraves de las colas

#include <cstdlib> //libreria que contiene funciones que utilizaremos
#include <iostream> //libreria estandar necesaria
#include <queue> //libreria que contiene funciones y plantillas para la utilizacion de colas
#include <stdio.h> //libreria que contiene funciones que utilizaremos
#include <windows.h> //libreria que contiene funciones que utilizaremos

using namespace std; //espacion a usar estandar, nos permite abreviar el codigo

void gotoxy(int x, int y); //declaracion de funcion que que mueve un texto a cualquier lugar de la pantalla
void error_dato(); //funcion que evita errores de ingreso de datos

struct ahorrante //estructura de datos de ahorrante que contiene los datos del ahorrante
{    //declaracion de variables
    char ticket[4];
    int NumCuenta;
    int edad;
};

int main()
{
    ahorrante aux; //variable auxiliar
    ahorrante *ptr; /*Varaible puntero de tipo ahorrante nos permitira almacenar la direccion de los datos de la cola para
                     para poder imprimirlos*/
    queue<ahorrante> cola; //nodo de tipo ahorrante
    //declaracion de variables
    int opcion;
    char seguir;
    bool continuar =  false;

    do { //ciclo do - while permite seguir en el programa y evita errores de ingreso de datos

        system("color 3E"); //funcion para darle color al texto y fondo de la consola
        system("cls"); //funcion que limpia la pantalla


        do { //ciclo do - while permite evitar errores de ingreso de datos
            //Menu de l programa
            gotoxy(50, 4); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "*************************" << endl;
            gotoxy(50, 5); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "*                       *" << endl;
            gotoxy(50, 6); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "*         Menu          *" << endl;
            gotoxy(50, 7); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "*                       *" << endl;
            gotoxy(50, 8); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "*************************" << endl;

            gotoxy(50, 10); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "Opciones." << endl;
            gotoxy(50, 11); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "1.Agregar ahorrante." << endl;
            gotoxy(50, 12); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "2.Mostrar ahorrante." << endl;
            gotoxy(50, 13); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "3.Eliminar ahorrante." << endl;
            gotoxy(50, 14); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "4.Salir" << endl;

            gotoxy(50, 16); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "Ingrese una opcion: ";
            cin >> opcion;
            error_dato(); //funcion que evita que se ingrese datos incorrectos

        } while (opcion < 1 || opcion > 4 || opcion == cin.fail());

        switch(opcion)
        {
            case 1:

                do { //ciclo do - while permite evitar errores de ingreso de datos

                    system("cls"); //funcion que limpia la pantalla

                    gotoxy(50, 4); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "*************************" << endl;
                    gotoxy(50, 5); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "*                       *" << endl;
                    gotoxy(50, 6); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "*   Ingreso de datos    *" << endl;
                    gotoxy(50, 7); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "*                       *" << endl;
                    gotoxy(50, 8); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "*************************" << endl;

                    do { //ciclo que evita errores de datos
                        system("cls"); //funcion que limpia la pantalla

                        gotoxy(50, 4); //funcion que mueve un texto a cualquier lugar de la pantalla
                        cout << "*************************" << endl;
                        gotoxy(50, 5); //funcion que mueve un texto a cualquier lugar de la pantalla
                        cout << "*                       *" << endl;
                        gotoxy(50, 6); //funcion que mueve un texto a cualquier lugar de la pantalla
                        cout << "*   Ingreso de datos    *" << endl;
                        gotoxy(50, 7); //funcion que mueve un texto a cualquier lugar de la pantalla
                        cout << "*                       *" << endl;
                        gotoxy(50, 8); //funcion que mueve un texto a cualquier lugar de la pantalla
                        cout << "*************************" << endl;
                        //ingreso de datos
                        gotoxy(50, 10); //funcion que mueve un texto a cualquier lugar de la pantalla
                        cout << "Ingrese el ticket: ";
                        cin >> aux.ticket;
                        error_dato(); //funcion que evita errores de ingreso de datos

                        gotoxy(50, 12); //funcion que mueve un texto a cualquier lugar de la pantalla
                        cout << "Ingrese el numero de cuenta: ";
                        cin >> aux.NumCuenta;
                        error_dato(); //funcion que evita errores de ingreso de datos

                        gotoxy(50, 14); //funcion que mueve un texto a cualquier lugar de la pantalla
                        cout << "Ingrese la edad: ";
                        cin >> aux.edad;
                        error_dato(); //funcion que evita errores de ingreso de datos

                    } while (aux.NumCuenta == cin.fail() || aux.edad == cin.fail());

                    cola.push(aux); //se ingresa los datos de aux al nodo colo por medio del metodo push

                    gotoxy(50, 17); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "Quiere ingresar otro ahorrante (y/n): ";
                    cin >> seguir;

                } while ((seguir == 'y' || seguir == 'Y') || (seguir != 'n' && seguir != 'N') || seguir == cin.fail());

                system("PAUSE");

                break;

            case 2:

                system("cls"); //funcion que limpia la pantalla

                gotoxy(50, 4); //funcion que mueve un texto a cualquier lugar de la pantalla
                cout << "**************************" << endl;
                gotoxy(50, 5); //funcion que mueve un texto a cualquier lugar de la pantalla
                cout << "*                         *" << endl;
                gotoxy(50, 6); //funcion que mueve un texto a cualquier lugar de la pantalla
                cout << "*   DATOS DEL AHORRANTE   *" << endl;
                gotoxy(50, 7); //funcion que mueve un texto a cualquier lugar de la pantalla
                cout << "*                         *" << endl;
                gotoxy(50, 8); //funcion que mueve un texto a cualquier lugar de la pantalla
                cout << "**************************" << endl;

                ptr = &cola.front(); //puntero de tipo ahorrante almacena la direccion del primer nodo

                for (int i = 1; i <= cola.size(); i++) {

                    aux = *ptr; //varialbe aux de tipo ahorrante este almacena la direccion del puntero ptr

                    cout << "\n\n\t\t\t\t\t\t\tAhorrante " << i << endl;
                    cout << "\n\n\t\t\t\t\t\t\tTicket: " << aux.ticket;
                    cout << "\n\n\t\t\t\t\t\t\tNumero de cuenta: " << aux.NumCuenta;
                    cout << "\n\n\t\t\t\t\t\t\tEdad: " << aux.edad << endl;

                    ptr++; /* el puntero se incrementa, esto debido al que el puntero almacena la
                            nodo de la cola al incrementarse este avanza ahasta al siguiente nodo
                            hasta el final del ciclo*/
                }

                system("PAUSE");

                break;

            case 3:
                    do { //ciclo do - while permite evitar errores de ingreso de datos

                    system("cls"); //funcion que limpia la pantalla

                    gotoxy(50, 4); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "****************************" << endl;
                    gotoxy(50, 5); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "*                          *" << endl;
                    gotoxy(50, 6); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "*  Eliminar de ahorrante   *" << endl;
                    gotoxy(50, 7); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "*                          *" << endl;
                    gotoxy(50, 8); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "****************************" << endl;

                    cola.pop(); //Metodo pop que permite borrar el primer nodo de la cola

                    gotoxy(35, 11); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "Se ha eliminado exitosamente el primer ahorrante de la cola" << endl;

                    fflush(stdin); //limpia el bujjer
                    gotoxy(43, 14); //funcion que mueve un texto a cualquier lugar de la pantalla
                    cout << "Quiere eliminar otro ahorrante (y/n): ";
                    cin >> seguir;
                    error_dato(); //funcion que evita errores de ingreso de datos


                } while ((seguir == 'y' || seguir == 'Y') || (seguir != 'n' && seguir != 'N'));

                system("PAUSE");
                break;

            case 4:

                system("cls"); //funcion que limpia la pantalla

                gotoxy(48, 8); //funcion que mueve un texto a cualquier lugar de la pantalla
                cout << "¡Gracias por usar el programa!" << endl;
                break;
        }

    } while (opcion == 1 || opcion == 2 || opcion == 3);

    system("PAUSE");
    return 0; //retorna cero
}

/*Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla contiene dos parametros enteros
y es de tipo void por lo que no retorna ningun valor
*/
void gotoxy(int x, int y)
{
	//Estas instrucciones permiticra ubicar un texto en el lugar que se desee en la pantalla
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void error_dato() //funcion que evita que se ingrese datos incorrectos
{
		//Ciclo while paraevitar datos incorrectos
		while(cin.fail()){

		//Limpia el buffer de los datos ingresados
		cin.clear();

		//Ignora los primeros 1000 caracteres o en este caso los numeros
		cin.ignore(1000,'\n');

		}
}
