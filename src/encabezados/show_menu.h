/*
	Falta implementar:
	- delete clases !!
*/

#ifndef showmenu
#define showmenu

#include "../clases/Menu/Menu.h"

#include <iostream>
#include <vector>
#include <string>

OpcionSeleccionada generarOpciones(string opciones[], int cant, string titulo, int nivel) {

	string _opciones[cant];
	
	for (int i=0; i<cant; i++) {
		_opciones[i] = opciones[i];
	}
	
	vector<string> opts(_opciones, _opciones + (sizeof (_opciones) / sizeof (string)));

	Menu* MainMenu = new Menu(titulo, opts);
	OpcionSeleccionada opcionSeleccionada = MainMenu->mostrar_menu(nivel);
	
	return opcionSeleccionada;
}

OpcionSeleccionada mostrar_menu(string desc) {
	OpcionSeleccionada op;

	if (desc == MAIN_MENU_TITLE) {
		op = generarOpciones(MAIN_MENU_OPTIONS, MAIN_MENU_OPTIONS_SIZE, MAIN_MENU_TITLE, 1);
		return op;
	}

	if (desc == SUBMENU_ADMIN_ID) {
		op = generarOpciones(SUBMENU_ADMIN_OPTIONS, (sizeof(SUBMENU_ADMIN_OPTIONS)/sizeof(*SUBMENU_ADMIN_OPTIONS)), SUBMENU_ADMIN_TITLE, 2);
		return op;
	}
	
	if (desc == SUBMENU_ALGORITHMS_ID) {
		op = generarOpciones(SUBMENU_ALGORITHMS_OPTIONS, (sizeof(SUBMENU_ALGORITHMS_OPTIONS)/sizeof(*SUBMENU_ALGORITHMS_OPTIONS)), SUBMENU_ALGORITHMS_TITLE, 2);
		return op;
	}
	
	if (desc == SUBMENU_ROUTES_ID) {
		op = generarOpciones(SUBMENU_ROUTES_OPTIONS, (sizeof(SUBMENU_ROUTES_OPTIONS)/sizeof(*SUBMENU_ROUTES_OPTIONS)), SUBMENU_ROUTES_TITLE, 2);
		return op;
	}

	op.num = 0;
	op.desc = "";

	return op;
}

#endif
