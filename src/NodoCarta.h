#include "Carta.h"
#include <string>
using namespace std;

#ifndef NODOCARTA_H_
#define NODOCARTA_H_

class NodoCarta {
public:
	NodoCarta();
	virtual ~NodoCarta();
	string nombre;
	int id;
	Carta *carta;
	NodoCarta *siguiente;
	NodoCarta *anterior;
};

#endif /* NODOCARTA_H_ */
