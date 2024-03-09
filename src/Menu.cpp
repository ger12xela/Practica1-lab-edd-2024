
#include "Menu.h"

#include "Carta.h"
#include "NodoCarta.h"
#include<stdlib.h>
#include<time.h>

//	Carta segundoPalo[12];
//	Carta tercerPalo[12];
//	Carta cuartoPalo[12];
NodoCarta *MInicial, *MTemporal, *MFinal, *movTemporal;
bool victoria = false;
NodoCarta *ColaSalida, *ColaEntrada;
NodoCarta *pos1, *pos2, *pos3, *pos4, *pos5, *pos6, *pos7;
NodoCarta *orden1, *orden2, *orden3, *orden4;

void MenuPrincipal(){
	cout<<"bienvenido a solitario"<<endl;
	cout<<endl;
	pos1 = new NodoCarta();
	pos2 = new NodoCarta();
	pos3 = new NodoCarta();
	pos4 = new NodoCarta();
	pos5 = new NodoCarta();
	pos6 = new NodoCarta();
	pos7 = new NodoCarta();
	ColaEntrada = new NodoCarta();
	ColaSalida = new NodoCarta();
	orden1 = new NodoCarta();
	orden2 = new NodoCarta();
	orden3 = new NodoCarta();
	orden4 = new NodoCarta();

}

void iniciaJuego(){
	int mov = 0;
	while (!victoria){
		cout<< "Que deseas hacer?"<<endl;
		cout<< "mover carta (1)  destapar carta(2)"<<endl;
		cin>>mov;
		switch (mov) {
			case 1:
				moverCarta();
				break;
			case 2:
				destaparCarta();
				break;
			default:
				break;
		}
		imprimirTablero();
	}
}

void moverCarta(){
	NodoCarta *temp = new NodoCarta;
	int eleccion;
	cout<<"de donde desea mover"<<endl;
	cout<<"de mazo(1)  de Ordenadas(2)   de pilas(3) "<<endl;
	cin>>eleccion;
	switch (eleccion) {
		case 1:
			temp = ScarDMazo(ColaSalida);
			break;
		case 2:
			temp = ScarDOrdenadas();
			break;
		case 3:
			temp = ScarDPilas();
			break;
		default:
			break;
	}

	if(temp != NULL){
		if(temp->carta!=NULL){
			int eleccion2;
			cout<<"donde lo desea colocar"<<endl;
			cout<<"ordenadas(1) pilas(2)"<<endl;
			cin>>eleccion;
			switch (eleccion) {
				case 1:
					cout<<"donde lo desea colocar"<<endl;
					cout<<"ordenada(1) ordenada(2) ordenada(3) ordenada(4)"<<endl;
					cin>>eleccion2;

					switch (eleccion2) {
						case 1:
							orden1 = montarPila(orden1, temp);
							imprimirLista(orden1);
							break;
						case 2:
							montarPila(orden2, temp);
							break;
						case 3:
							montarPila(orden3, temp);
							break;
						case 4:
							montarPila(orden4, temp);
							break;

						default:
							break;
					}
					break;
				default:
					break;
			}

		}
	}


}
NodoCarta *obtener(NodoCarta* pila, int cantidad){
	NodoCarta *Itemp;
	NodoCarta *Ttemp;

	Itemp = new NodoCarta;
	Ttemp = new NodoCarta;

	if (pila->carta==NULL) {
		cout<<"no hay carta que sacar"<<endl;
	}else{
		Itemp = pila;
		Ttemp = pila->siguiente;
		Itemp = Ttemp;
		pila->anterior = NULL;
//		pila = Itemp;
//		Itemp->siguiente = NULL;
//		Itemp->anterior = NULL;

	}
	return Itemp;
}
NodoCarta *ScarDOrdenadas(){
	return NULL;
}

NodoCarta *ScarDPilas(){
	return NULL;
}

NodoCarta *ScarDMazo(NodoCarta *lista){
	NodoCarta *opt = new NodoCarta;

	if(confirmarVacio(lista)){
		ColaSalida = obtener(lista, 0);
		opt = ColaSalida->anterior;
		if(opt !=NULL){
			cout<<"carta"<<opt->carta->nombre<<opt->carta->simbolo<<endl;
		}

	}
	return opt;
}
bool confirmarVacio(NodoCarta *lista){
	bool lleno = false;
	if(lista != NULL){
		if(lista->carta != NULL){
			lleno = true;
		}
	}
	return lleno;
}
void destaparCarta(){
	NodoCarta *temp = new NodoCarta;
		if(ColaEntrada!=NULL){
			temp = SacarPila(ColaEntrada, 0);
			ColaSalida =montarPila(ColaSalida, temp) ;
		}else{
			ColaEntrada = new NodoCarta;
			while (ColaSalida != NULL){
				temp = SacarPilam(ColaSalida, 0);
				ColaEntrada =montarPila(ColaEntrada, temp) ;
			}
			ColaSalida = new NodoCarta;
		}

		if (ColaEntrada == NULL && ColaSalida == NULL){
			cout<<"Sin cartas en el mazo"<<endl;
		}


}

NodoCarta *SacarPila(NodoCarta* pila, int cantidad){

	NodoCarta *temp = new NodoCarta;

	if (pila->carta==NULL) {
		cout<<"no hay carta que sacar"<<endl;
	}else{
		temp = pila;
		if (cantidad > 0) {
			for (int i = 0; i <= cantidad; ++i) {
				temp = temp->siguiente;
			}

		}
		ColaEntrada = pila->siguiente;
		temp->siguiente = NULL;
		temp->anterior = NULL;
	}
	return temp;
}

NodoCarta *SacarPilam(NodoCarta* pila, int cantidad){

	NodoCarta *temp = new NodoCarta;

	if (pila->carta==NULL) {
		cout<<"no hay carta que sacar"<<endl;
	}else{
		temp = pila;
		if (cantidad > 0) {
			for (int i = 0; i <= cantidad; ++i) {
				temp = temp->siguiente;
			}

		}
		ColaSalida = pila->siguiente;
		temp->siguiente = NULL;
		temp->anterior = NULL;
	}
	return temp;
}

NodoCarta *montarPila(NodoCarta *pila, NodoCarta *montar){
	if (pila->carta==NULL) {
		pila= montar;
	}else{
		montar->siguiente = pila;
		pila->anterior = montar;
		pila = montar;
		pila->id= pila->siguiente->id++;
	}
	return pila;

}

void CrearMaso(){
	int num=0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 13; ++j) {
			MTemporal= new NodoCarta();
			Carta *T = new Carta();
			T->nombre = to_string(j+1);
			switch (j) {
				case 0:
					T->nombre = "As";
					break;
				case 10:
					T->nombre = "J";
					break;
				case 11:
					T->nombre = "Q";
					break;
				case 12:
					T->nombre = "K";
					break;
				default:
					break;
			}
			switch (i) {
				case 0:
				T->color = "negro";
				T->simbolo = "espada";
					break;
				case 1:
				T->color = "negro";
				T->simbolo = "trebol";
					break;
				case 2:
				T->color = "rojo";
				T->simbolo = "corazon";
					break;
				case 3:
				T->color = "rojo";
				T->simbolo = "diamante";
					break;
				default:
					break;
			}
			MTemporal->carta=T;
			MTemporal->id = num;
			if (MInicial == NULL) {
				MInicial = MTemporal;
			}else {
				MFinal->siguiente = MTemporal;
				MTemporal->anterior = MFinal;
			}
			MFinal = MTemporal;
			num++;
		}
	}
}


NodoCarta *SacarMaso(int pos){
	bool encontrado = true;
	if (MInicial == NULL){
		cout<<"El maso esta vacio"<<endl;
	}else {
		MTemporal = MInicial;
		while(MTemporal != NULL){

			if(MTemporal->id == pos ){
					movTemporal = MTemporal;
					encontrado = false;
					if (MTemporal->anterior != NULL) {
						MTemporal->anterior->siguiente= MTemporal->siguiente;

					}
					if (MTemporal->siguiente != NULL) {
						MTemporal->siguiente->anterior = MTemporal->anterior;
					}
			}
			MFinal = MTemporal;
			MTemporal =MTemporal->siguiente;
		}
		ordenar(MInicial);
	}
		if (encontrado) {
			movTemporal = MFinal;
				MFinal->anterior->siguiente = NULL;
			ordenar(MInicial);
		}
	return movTemporal;
}
void ordenar(NodoCarta *lista){
	NodoCarta *temporden = lista;
	int fe=0;
	if (lista != NULL){
			temporden->id = 0;
			temporden = temporden->siguiente;
		while(temporden !=NULL){
			temporden->id = fe;
			temporden = temporden->siguiente;
			fe++;

		}
	}
}

void Llenarlugares(){
	LlenarPos17();
	ColaInicial();

}
void LlenarPos17(){
	int ide = 1;
	int aun = 53;
	while (aun > 25){
		srand(time(NULL));
		int num=1+rand()%(aun-1);
		NodoCarta *op = SacarMaso(num);
		op->id = ide;
		if(op!= NULL)agregarInicial(op, ide);
		aun--;
		ide++;
	}
}

void ColaInicial(){

	int aun = 24;
	while (aun > 1){
		srand(time(NULL));
		int num=1+rand()%(aun-1);
		NodoCarta *op= SacarMaso(num);
		op->id=1;
		op->siguiente = NULL;
		op->anterior = NULL;
		ColaEntrada = montarPila(ColaEntrada, op);
		ordenar(ColaEntrada);
		aun--;
	}
	ColaEntrada = montarPila(ColaEntrada, MInicial);

	MInicial = NULL;

}

NodoCarta *ultimo;
NodoCarta *postemp;

void agregarInicial(NodoCarta *temp, int ide){
	temp->id=1;
	temp->anterior=NULL;
	temp->siguiente = NULL;

	if (ide == 1) {
		pos1 = montarPila(pos1, temp);
		pos1->nombre="pila 1";
		postemp = pos1;
	}
	if (ide > 1 && ide <=3) {
		pos2 = montarPila(pos2, temp);
		pos2->nombre="pila 2";
		postemp = pos2;

	}
	if (ide>3 && ide <=6){
		pos3 = montarPila(pos3, temp);
		pos3->nombre="pila 3";
		postemp = pos3;

	}
	if (ide>6 && ide <=10){
		pos4 = montarPila(pos4, temp);
		pos4->nombre="pila 4";
		postemp = pos4;

	}
	if (ide>10 && ide <=15){
		pos5 = montarPila(pos5, temp);
		pos5->nombre="pila 5";
		postemp = pos5;

	}
	if (ide>15 && ide <=21){
		pos6 = montarPila(pos6, temp);
		pos6->nombre="pila 6";
		postemp = pos6;

	}
	if (ide>21 && ide <=28){
		pos7 = montarPila(pos7, temp);
		pos7->nombre="pila 7";
		postemp = pos7;

	}
}
//parte de imprimir
//

void imprimirTablero(){
	cout<<"    MASO                                              PILAS ORDENADAS   "<<endl;
	cout<<"                                                     1       2      3       4  "<<endl;
	if(ColaEntrada != NULL){
		cout << "[hay cartas]";
	}
	else{
		cout << "[reinicia  ]";
	}

	if(ColaSalida->carta!=NULL){
		cout << ColaSalida->carta->nombre<<ColaSalida->carta->simbolo;
	}else{
		cout<<"[      ]";
	}

	cout<<"                             ";
	if(orden1->carta!=NULL){
		cout << orden1->carta->nombre<<orden1->carta->simbolo;
	}else{
		cout<<"[      ]";
	}
	if(orden2->carta!=NULL){
		cout << orden2->carta->nombre<<orden2->carta->simbolo;
	}else{
		cout<<"[      ]";
	}
	if(orden3->carta!=NULL){
		cout << orden3->carta->nombre<<orden3->carta->simbolo;
	}else{
		cout<<"[      ]";
	}
	if(orden4->carta!=NULL){
		cout << orden4->carta->nombre<<orden4->carta->simbolo;
	}else{
		cout<<"[      ]";
	}

	cout<<endl;
	cout<<"PILAS COMUNES"<<endl;
	cout<<endl;

	if(pos1 !=NULL){
		imprimirLista(pos1);
	}else{
		cout <<"libre"<<endl;
	}
	if(pos2 !=NULL){
		imprimirLista(pos2);
	}else{
		cout <<"libre"<<endl;
	}
	if(pos3 !=NULL){
		imprimirLista(pos3);
	}else{
		cout <<"libre"<<endl;
	}
	if(pos4 !=NULL){
		imprimirLista(pos4);
	}else{
		cout <<"libre"<<endl;
	}
	if(pos5 !=NULL){
		imprimirLista(pos5);
	}else{
		cout <<"libre"<<endl;
	}
	if(pos6 !=NULL){
		imprimirLista(pos6);
	}else{
		cout <<"libre"<<endl;
	}
	if(pos6 !=NULL){
		imprimirLista(pos7);
	}else{
		cout <<"libre"<<endl;
	}
}
void imprimirLista(NodoCarta *temp){
	if (temp != NULL){
		int maximoA= 0;
		cout<<temp->nombre<<"__>";
		while (temp->siguiente != NULL){
			if(temp->carta->vista){
				cout<<temp->carta->nombre;
				cout<<temp->carta->simbolo;
				cout<<"-->";
				temp = temp->siguiente;
			}else{
				cout<<"oculto";
				cout<<"-->";
				temp = temp->siguiente;

			}
			maximoA++;
		}
			temp->carta->vista= true;
			cout<<temp->carta->nombre;
			cout<<temp->carta->simbolo<<endl;

	}else{
		cout<<"[      ]"<<endl;
	}
}




