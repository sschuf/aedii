#ifndef menuh
#define menuh

#include "../../encabezados/global.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Menu {
	private:
		string TITULO;
		vector<string> OPCIONES;
		string MENU_EXIT;

	public:
		Menu(string, vector<string>);
		~Menu() {}
		OpcionSeleccionada mostrar_menu(int);
};

#endif
