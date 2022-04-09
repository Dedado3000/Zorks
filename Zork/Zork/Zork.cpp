// Zork.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "utils.h"
#include "world.h"

using namespace std;


#define MACHINECOLOR_ "\033[1;36m"
#define _MACHINECOLOR "\033[0m"


#define ERRORCOLOR_ "\033[4;31m"
#define _ERRORCOLOR "\033[0m"

int main()
{
	char key;
	string player_action;
	vector<string> args;
	args.reserve(10);

	cout << "-------------------------\n";
	cout << MACHINECOLOR_ "Welcome to Zork by David Martin!\n" _MACHINECOLOR;
	cout << "-------------------------\n";

	World world;

	args.push_back("open");

	while (true)
	{
		if (args.size() == 0)
		{
			cin >> player_action;
			Tokenize(player_action, args);

		}




		//Exit Game
		if (args.size() > 0 && (IsEquals(args[0], "quit") || IsEquals(args[0], "exit") || IsEquals(args[0], "salir")))
			break;

		//Loop de juego
		if (world.PerformAction(args) == false)
			cout << ERRORCOLOR_ "\nNo valid action input.\n" _ERRORCOLOR;



		if (args.size() > 0)
		{
			args.clear();
			player_action = "";
			cout << "> ";
		}
	}


	cout << MACHINECOLOR_ "\nThanks for playing my game\n" _MACHINECOLOR;
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
