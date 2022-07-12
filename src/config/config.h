/*
*	- Separar en namespaces
*/

#ifndef config
#define config

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
*	SPACING
*/

string DEFAULT_LEFT_SPACING = "\t";
string DEFAULT_TOP_SPACING = "\n\n";
string DEFAULT_BOTTOM_SPACING = "\n\n";

string DEFAULT_SPACING = DEFAULT_TOP_SPACING + DEFAULT_LEFT_SPACING;

/*
*	SYSTEM
*/

string DEFAULT_EXIT_MESSAGE = "Nos vemos!";

int DEFAULT_WAIT = 450;

char DEFAULT_SYSTEM_COLOR[] = "color 07";
string DEFAULT_TEXT_COLOR = "[0m\n";

string DEFAULT_COLOR_ERROR = "red";

/*
*	OPTIONS
*/

string DEFAULT_TITLE_SYMBOL = "~";

string OPTION_NUMBER_SEPARATOR = ".";
string OPTION_TREE_SEPARATOR = " / ";

string DEFAULT_OPTION_QUERY = "Ingrese una opcion";

string DEFAULT_NO_OPT_ERROR_MESSAGE = "Opcion invalida. Intente nuevamente..";

/*
*	EXIT / RETURN MENU
*/
string MAIN_EXIT = "Salir";
string MENU_RETURN = "Volver";

/*
*	MAIN MENU
*/
string MAIN_MENU_TITLE = "Algoritmos y Estructura de Datos";

string MAIN_MENU_OPT_1 = "Administracion de grafo";
string MAIN_MENU_OPT_2 = "Algoritmos";
string MAIN_MENU_OPT_3 = "Recorridos";

string MAIN_MENU_OPTIONS[] = {
	MAIN_MENU_OPT_1,
	MAIN_MENU_OPT_2,
	MAIN_MENU_OPT_3
};

int MAIN_MENU_OPTIONS_SIZE = (sizeof(MAIN_MENU_OPTIONS)/sizeof(*MAIN_MENU_OPTIONS));

/*
*	ADMIN MENU
*/
string SUBMENU_ADMIN_ID = MAIN_MENU_OPT_1;

string SUBMENU_ADMIN_TITLE = MAIN_MENU_TITLE + OPTION_TREE_SEPARATOR + SUBMENU_ADMIN_ID;

string SUBMENU_ADMIN_OPT_1 = "Carga De Vertices";
string SUBMENU_ADMIN_OPT_2 = "Carga De Aristas";
string SUBMENU_ADMIN_OPT_3 = "Lista De Adyacencia";
string SUBMENU_ADMIN_OPT_4 = "Tamano Del Grafo";
string SUBMENU_ADMIN_OPT_5 = "Eliminar Vertice";
string SUBMENU_ADMIN_OPT_6 = "Eliminar Arista";
string SUBMENU_ADMIN_OPT_7 = "Crear Monticulo";

string SUBMENU_ADMIN_OPTIONS[] = {
	SUBMENU_ADMIN_OPT_1,
	SUBMENU_ADMIN_OPT_2,
	SUBMENU_ADMIN_OPT_3,
	SUBMENU_ADMIN_OPT_4,
	SUBMENU_ADMIN_OPT_5,
	SUBMENU_ADMIN_OPT_6,
	SUBMENU_ADMIN_OPT_7
};

int SUBMENU_ADMIN_OPTIONS_SIZE = (sizeof(SUBMENU_ADMIN_OPTIONS)/sizeof(*SUBMENU_ADMIN_OPTIONS));

/*
*	ALGORITHMS MENU
*/

string SUBMENU_ALGORITHMS_ID = MAIN_MENU_OPT_2;

string SUBMENU_ALGORITHMS_TITLE = MAIN_MENU_TITLE + OPTION_TREE_SEPARATOR + SUBMENU_ALGORITHMS_ID;

string SUBMENU_ALGORITHMS_OPT_1 = "Prim";
string SUBMENU_ALGORITHMS_OPT_2 = "Dijkstra";
string SUBMENU_ALGORITHMS_OPT_3 = "Kruskal";
string SUBMENU_ALGORITHMS_OPT_4 = "Mejor Camino (Primero El Mejor)";

string SUBMENU_ALGORITHMS_OPTIONS[] = {
	SUBMENU_ALGORITHMS_OPT_1,
	SUBMENU_ALGORITHMS_OPT_2,
	SUBMENU_ALGORITHMS_OPT_3,
	SUBMENU_ALGORITHMS_OPT_4
};

int SUBMENU_ALGORITHMS_OPTIONS_SIZE = (sizeof(SUBMENU_ALGORITHMS_OPTIONS)/sizeof(*SUBMENU_ALGORITHMS_OPTIONS));


/*
*	ROUTES MENU
*/

string SUBMENU_ROUTES_ID = MAIN_MENU_OPT_3;

string SUBMENU_ROUTES_TITLE = MAIN_MENU_TITLE + OPTION_TREE_SEPARATOR + SUBMENU_ROUTES_ID;

string SUBMENU_ROUTES_OPT_1 = "Recorrido Anchura";
string SUBMENU_ROUTES_OPT_2 = "Recorrido Profundidad";

string SUBMENU_ROUTES_OPTIONS[] = {
	SUBMENU_ROUTES_OPT_1,
	SUBMENU_ROUTES_OPT_2
};

int SUBMENU_ROUTES_OPTIONS_SIZE = (sizeof(SUBMENU_ROUTES_OPTIONS)/sizeof(*SUBMENU_ROUTES_OPTIONS));

#endif
