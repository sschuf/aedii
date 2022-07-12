#include "../../encabezados/global.h"
#include "Menu.h"

#include <string>
#include <vector>

extern string OPTION_NUMBER_SEPARATOR, MENU_RETURN, MAIN_EXIT, DEFAULT_SPACING, DEFAULT_TITLE_SYMBOL, DEFAULT_OPTION_QUERY;
extern void clear(), paddingLeft(), print();
extern int get_int();

/*
*	Mostrar Men�
*	Devuelve un entero - Opcion ingresada por el usuario
*/

Menu::Menu(string titulo, vector<string> opciones) {
	this->TITULO = titulo;
	this->OPCIONES = opciones;
}

OpcionSeleccionada Menu::mostrar_menu(int level) {
	int t = OPCIONES.size();
	OpcionSeleccionada opt;

	clear(); paddingLeft();
	
	cout << DEFAULT_TITLE_SYMBOL << " " << TITULO << " " << DEFAULT_TITLE_SYMBOL;
	cout << endl << endl;

	for (int i = 0; i < t; i++) {
		paddingLeft();
		cout << (i+1) << OPTION_NUMBER_SEPARATOR << " " << OPCIONES[i] << endl;
	}

	cout << endl; paddingLeft();
	if (level == 1) cout << (t + 1) << OPTION_NUMBER_SEPARATOR << " " << MAIN_EXIT << endl;
	else cout << (t + 1) << OPTION_NUMBER_SEPARATOR << " " << MENU_RETURN << endl;

	cout << endl; paddingLeft();
	cout << DEFAULT_OPTION_QUERY << ": ";

	opt.num = get_int();

	if (opt.num > 0 && opt.num <= t) opt.desc = OPCIONES[opt.num-1];
	else opt.desc = "";

	return opt;
};
