#include <string>
using namespace std;
#ifndef CARTA_H_
#define CARTA_H_

class Carta {
public:
	Carta();
	virtual ~Carta();
	bool vista = false;
	string nombre;
	string color;
	string simbolo;


};

#endif /* CARTA_H_ */
