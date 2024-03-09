
#ifndef MENU_H_
#define MENU_H_
#include <iostream>
#include <string.h>

#include "NodoCarta.h"
using namespace std;

void MenuPrincipal();
void CrearMaso();
void Llenarlugares();
void agregarInicial( NodoCarta *temp, int ide);
void ordenar(NodoCarta *lista);

void iniciaJuego();
void moverCarta();
void destaparCarta();

NodoCarta *ScarDMazo(NodoCarta *lista);
NodoCarta *ScarDOrdenadas();
NodoCarta *ScarDPilas();

NodoCarta *obtener(NodoCarta* pila, int cantidad);
NodoCarta *SacarPila(NodoCarta* pila, int cantidad);
NodoCarta *SacarPilam(NodoCarta* pila, int cantidad);

NodoCarta *montarPila(NodoCarta *pila, NodoCarta *montar);
void mostrarArriba(NodoCarta *lista);
void imprimirTablero();
void imprimirLista(NodoCarta *temp);
void LlenarPos17();
void ColaInicial();

bool confirmarVacio(NodoCarta *lista);


#endif /* MENU_H_ */
