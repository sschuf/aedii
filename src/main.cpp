#include "config/config.h"
#include "encabezados/global.h"
#include "utils/console.h"
#include "clases/Grafo/Grafo.h"
#include "encabezados/show_menu.h"

#include "servicios/customizar/opciones.h"
#include "servicios/algoritmos/opciones.h"
#include "servicios/recorridos/opciones.h"

using namespace std;

int main() {

    Grafo G;
    G.Inicializa();
    
    const int wesa = 5;
    
    int num = 0, num2 = 0, temp = 0;

    OpcionSeleccionada opt, opt2, opt3, opt4;

    do {
		opt = mostrar_menu(MAIN_MENU_TITLE);
		
		switch (opt.num) {
			do {
				case 1:
					opt2 = mostrar_menu(opt.desc);
				
					switch (opt2.num) {
						case 1: {
	                        G = customizarOpcion1(G, temp, num);
	                        cin.ignore();
	                        break;
	                    }
	                    case 2: {
	                    	G = customizarOpcion2(G);
	                    	cin.ignore();
							break;
						}
						case 3: {
							G = customizarOpcion3(G);
							cin.ignore();
							break;
						}
						case 4: {
							G = customizarOpcion4(G);
							cin.ignore();
							break;
						}
						case 5: {
							G = customizarOpcion5(G, num);
							cin.ignore();
							break;
						}
						case 6: {
							G = customizarOpcion6(G);
							cin.ignore();
							break;
						}
						case 7: {
							G = customizarOpcion7(G);
							cin.ignore();
							break;
						}
						case 8: break;
						default: {
							noOption();
							break;
						}
					}
			} while(opt2.num != (SUBMENU_ADMIN_OPTIONS_SIZE + 1));
			break;

			case 2:{
				do {
					opt3 = mostrar_menu(opt.desc);

					switch (opt3.num) {
						case 1: {
							G = algoritmosOpcion1(G);
							cin.ignore();
							break;
						}
						case 2: {
							G = algoritmosOpcion2(G);
							cin.ignore();
							break;
						}
						case 3: {
							G = algoritmosOpcion3(G);
							cin.ignore();
							break;
						}
						case 4: {
							G = algoritmosOpcion4(G);
							cin.ignore();
							break;
						}
						case 5: break;
						default: {
							noOption();
							break;
						};
					}

				} while(opt3.num != (SUBMENU_ALGORITHMS_OPTIONS_SIZE + 1));

				break;
			}

			case 3: {
				do {
					opt4 = mostrar_menu(opt.desc);
					
					switch (opt4.num) {
						case 1: {
							G = recorridosOpcion1(G);
							cin.ignore();
							break;
						}
						case 2: {
							G = recorridosOpcion2(G);
							cin.ignore();
							break;
						}
						case 3: break;
						default: {
							noOption();
							break;
						};
					}
				} while(opt4.num != (SUBMENU_ROUTES_OPTIONS_SIZE + 1));
				break;
			}
			case 4: break;
			default: {
				noOption();
				break;
			};
		}
	} while (opt.num != (MAIN_MENU_OPTIONS_SIZE + 1));

	clear();
	print(DEFAULT_EXIT_MESSAGE);
	print(DEFAULT_BOTTOM_SPACING);
	return 0;
}
