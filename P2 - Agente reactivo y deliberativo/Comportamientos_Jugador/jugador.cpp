#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>

// Dado el código en carácter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla){
	if (casilla=='P' or casilla=='M' or casilla =='D')
		return true;
	else
		return false;
}

// Este es el método principal que debe contener los 4 Comportamientos_Jugador
// que se piden en la práctica. Tiene como entrada la información de los
// sensores y devuelve la acción a realizar.
Action ComportamientoJugador::think(Sensores sensores) {
	Action accion = actIDLE;

	destino.fila = sensores.destinoF;
	destino.columna = sensores.destinoC;

	if (sensores.nivel != 4){
		if (sensores.mensajeF != -1){
			fil = sensores.mensajeF;
			col = sensores.mensajeC;
			brujula = 0; // 0 corresponde con Norte

			actual.fila = fil;
			actual.columna = col;
			actual.orientacion = brujula;
		}

		if(!hay_plan)
			hay_plan = pathFinding(sensores.nivel, actual, destino, plan);
		else{
			accion = plan.front();
			plan.pop_front();
		}
	}
	else{
		if(!sensores.reset){
			if(sensores.terreno[0] == 'K' && !referenciaecontrada){
				referenciaecontrada = true;
				actual.fila = sensores.mensajeF;
				actual.columna = sensores.mensajeC;
				VolcarMapaReactivo();
			}

			if(sensores.terreno[1] == 'K' && !referenciaecontrada && !EsObstaculo(2)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actTURN_L);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[5] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_L);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[4] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6) && !EsObstaculo(5)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_L);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[11] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6) && !EsObstaculo(12)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_L);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[10] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6) && !EsObstaculo(12) && !EsObstaculo(11)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_L);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[10] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6) && !EsObstaculo(12) && !EsObstaculo(11) && !EsObstaculo(10)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_L);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[3] == 'K' && !referenciaecontrada && !EsObstaculo(2)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actTURN_R);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[7] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_R);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[8] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6) && !EsObstaculo(7)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_R);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[13] == 'K' && !referenciaecontrada &&  !EsObstaculo(2) && !EsObstaculo(6) && !EsObstaculo(12)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_R);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[14] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6) && !EsObstaculo(12) && !EsObstaculo(13)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_R);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
			}else if(sensores.terreno[15] == 'K' && !referenciaecontrada && !EsObstaculo(2) && !EsObstaculo(6) && !EsObstaculo(12) && !EsObstaculo(13) && !EsObstaculo(14)){
				while(!acciones.empty())
					acciones.pop();

				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actTURN_R);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
				acciones.push(actFORWARD);
			}

			if(!referenciaecontrada){
				if(acciones.empty()){
					if((EsObstaculo(sensores.terreno[6]) && EsObstaculo(sensores.terreno[1])) && !EsObstaculo(sensores.terreno[2])){
						acciones.push(actFORWARD);
						acciones.push(actTURN_R);
						acciones.push(actFORWARD);
						acciones.push(actTURN_R);
					}else if((EsObstaculo(sensores.terreno[6]) && EsObstaculo(sensores.terreno[3])) && !EsObstaculo(sensores.terreno[2])){
						acciones.push(actFORWARD);
						acciones.push(actTURN_L);
						acciones.push(actFORWARD);
						acciones.push(actTURN_L);
					}else if(EsObstaculo(sensores.terreno[6]) || EsObstaculo(sensores.terreno[2])){
						if(!(EsObstaculo(sensores.terreno[2])))
							acciones.push(actFORWARD);
						if(girarizq){
							acciones.push(actTURN_L);
							acciones.push(actFORWARD);
							acciones.push(actTURN_L);
						}else{
							acciones.push(actTURN_R);
							acciones.push(actFORWARD);
							acciones.push(actTURN_R);
						}

						girarizq = !girarizq;
					}else
						acciones.push(actFORWARD);
				}
				if(sensores.superficie[2] != 'a'){
					accion = acciones.front();
					accionesreactivo.push(accion);
					mapareactivo.push_back(sensores.terreno);

					if(accion == actTURN_R)
						actual.orientacion = (actual.orientacion + 1)%4;
					else if(accion == actTURN_L)
						actual.orientacion = (actual.orientacion + 3)%4;

					acciones.pop();
				}else
					accion = actIDLE;
			}else{
				Explorar(actual, sensores.terreno);
				if(!plan.empty() && plan.front() == actFORWARD && EsObstaculo(sensores.terreno[2])){
					plan.clear();
					accion = actIDLE;
				}

				if(plan.empty())
					hay_plan = false;

				if(!hay_plan)
					hay_plan = pathFinding(sensores.nivel, actual, destino, plan);
				else{
					if(sensores.superficie[2] == 'a' && plan.front() == actFORWARD)
						accion = actIDLE;
					else{
						accion = plan.front();
						plan.pop_front();
					}
				
					if(accion == actFORWARD)
						switch (actual.orientacion){
							case 0: actual.fila--; break;
							case 1: actual.columna++; break;
							case 2: actual.fila++; break;
							case 3: actual.columna--; break;
						}
					else if(accion == actTURN_L)
						actual.orientacion = (actual.orientacion + 3)%4;
					else if(accion == actTURN_R)
						actual.orientacion = (actual.orientacion + 1)%4;
				}
			}
		}
	}

  return accion;
}

void ComportamientoJugador::VolcarMapaReactivo(){
	estado st = actual;
	Action accion;
	for(int i = 0; i < mapareactivo.size(); ++i){
		accion = accionesreactivo.top();
		accionesreactivo.pop();

		if(accion == actFORWARD)
			switch (st.orientacion){
				case 0: st.fila++; break;
				case 1: st.columna--; break;
				case 2: st.fila--; break;
				case 3: st.columna++; break;
			}
		else if(accion == actTURN_L)
			st.orientacion = (st.orientacion + 1)%4;
		else if(accion == actTURN_R)
			st.orientacion = (st.orientacion + 3)%4;

		Explorar(st, mapareactivo[mapareactivo.size()-i-1]);
	}
}

void ComportamientoJugador::Explorar(estado st, vector<unsigned char> sensor){
	int i, j, k, fil = st.fila, col = st.columna;
	mapaResultado[fil][col] = sensor[0];

	switch (st.orientacion) {
		case 0: fil--;col--; break;
		case 1: col++;fil--; break;
		case 2: fil++;col++; break;
		case 3: col--;fil++; break;
	}
	for(i = 1, j = fil, k = col; i < 4; ++i){
		mapaResultado[j][k] = sensor[i];

		switch (st.orientacion) {
			case 0: k++; break;
			case 1: j++; break;
			case 2: k--; break;
			case 3: j--; break;
		}
	}

	switch (st.orientacion) {
		case 0: fil--;col--; break;
		case 1: col++;fil--; break;
		case 2: fil++;col++; break;
		case 3: col--;fil++; break;
	}

	for(i = 4, j = fil, k = col; i < 9; ++i){
		mapaResultado[j][k] = sensor[i];

		switch (st.orientacion) {
			case 0: k++; break;
			case 1: j++; break;
			case 2: k--; break;
			case 3: j--; break;
		}
	}

	switch (st.orientacion) {
		case 0: fil--;col--; break;
		case 1: col++;fil--; break;
		case 2: fil++;col++; break;
		case 3: col--;fil++; break;
	}

	for(i = 9, j = fil, k = col; i < 16; ++i){
		mapaResultado[j][k] = sensor[i];
		switch (st.orientacion) {
			case 0: k++; break;
			case 1: j++; break;
			case 2: k--; break;
			case 3: j--; break;
		}
	}

}


// Llama al algoritmo de busqueda que se usará en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding(int level, const estado &origen, const estado &destino, list<Action> &plan){
	switch (level){
		case 1: cout << "Busqueda en profundad\n";
			      	return pathFinding_Profundidad(origen,destino,plan);
						break;
		case 2: cout << "Busqueda en Anchura\n";
			      // Incluir aqui la llamada al busqueda en anchura
					return pathFinding_Anchura(origen,destino,plan);
						break;
		case 3: cout << "Busqueda Costo Uniforme\n";
						// Incluir aqui la llamada al busqueda de costo uniforme
					return pathFinding_CostoUniforme(origen,destino,plan);
						break;
		case 4: cout << "Busqueda para el reto\n";
						// Incluir aqui la llamada al algoritmo de búsqueda usado en el nivel 2
					return pathFinding_CostoUniforme(origen,destino,plan);
						break;
	}
	cout << "Comportamiento sin implementar\n";
	return false;
}


//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st){
	int fil=st.fila, col=st.columna;

  // calculo cual es la casilla de delante del agente
	switch (st.orientacion) {
		case 0: fil--; break;
		case 1: col++; break;
		case 2: fil++; break;
		case 3: col--; break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil<0 or fil>=mapaResultado.size()) return true;
	if (col<0 or col>=mapaResultado[0].size()) return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col])){
		// No hay obstaculo, actualizo el parámetro st poniendo la casilla de delante.
    st.fila = fil;
		st.columna = col;
		return false;
	}
	else{
	  return true;
	}
}

struct nodo{
	estado st;
	list<Action> secuencia;
	int pathcost;
};

struct ComparaEstados{
	bool operator()(const estado &a, const estado &n) const{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
	      (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion))
			return true;
		else
			return false;
	}
};


// Implementación de la búsqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	stack<nodo> pila;											// Lista de Abiertos

  	nodo current;
	current.st = origen;
	current.secuencia.empty();

	pila.push(current);

  while (!pila.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		pila.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			pila.push(hijoTurnR);
		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			pila.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				pila.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la pila
		if (!pila.empty()){
			current = pila.top();
		}
	}


  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		plan.push_back(actIDLE);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}


bool ComportamientoJugador::pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan){
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	queue<nodo> cola;											// Lista de Abiertos

  	nodo current;
	current.st = origen;
	current.secuencia.empty();

	cola.push(current);

  	while (!cola.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		cola.pop();
		generados.insert(current.st);

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				cola.push(hijoForward);
			}
		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			cola.push(hijoTurnL);
		}


		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			cola.push(hijoTurnR);
		}

		// Tomo el siguiente valor de la pila
		if (!cola.empty()){
			current = cola.front();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		plan.push_back(actIDLE);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}

struct ComparaCoste{
	bool operator()(const nodo &a, const nodo &n) const{
		return a.pathcost > n.pathcost;
	}
};

//Calcula el coste de ir a una casilla
int ComportamientoJugador::CalculaCoste(const estado &st){
	int fil=st.fila, col=st.columna;

	switch (st.orientacion) {
		case 0: fil--; break;
		case 1: col++; break;
		case 2: fil++; break;
		case 3: col--; break;
	}

	if (fil<0 or fil>=mapaResultado.size()) return 0;
	if (col<0 or col>=mapaResultado[0].size()) return 0;

	unsigned char tipocasilla = mapaResultado[fil][col];
	switch (tipocasilla){
		case 'B': return 5; break;
		case 'A': return 10; break;
		case 'T': return 2; break;
		case 'S': return 1; break;
		case 'K': return 1; break;
		case '?': return 3; break;
		default: return 0;
	}
}

bool ComportamientoJugador::pathFinding_CostoUniforme(const estado &origen, const estado &destino, list<Action> &plan){
	//Borro la lista
	int costo;
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	priority_queue<nodo, vector<nodo>, ComparaCoste> cola;	// Lista de Abiertos

  	nodo current;
	current.st = origen;
	current.secuencia.empty();
	current.pathcost = 0;

	cola.push(current);

  	while (!cola.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){
			cola.pop();
			generados.insert(current.st);

			// Generar descendiente de avanzar
			nodo hijoForward = current;
			costo = CalculaCoste(hijoForward.st);
			if (!HayObstaculoDelante(hijoForward.st)){
				if (generados.find(hijoForward.st) == generados.end()){
					if(hijoForward.secuencia.back() != actTURN_L && hijoForward.secuencia.back() != actTURN_R)
						hijoForward.pathcost += costo;
					hijoForward.secuencia.push_back(actFORWARD);
					cola.push(hijoForward);
				}
			}

			// Generar descendiente de girar a la izquierda
			nodo hijoTurnL = current;
			hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
			if (generados.find(hijoTurnL.st) == generados.end()){
				costo = CalculaCoste(hijoTurnL.st);

				if(costo != 0){
					hijoTurnL.pathcost += costo + 1;
					hijoTurnL.secuencia.push_back(actTURN_L);
					cola.push(hijoTurnL);
				}
			}


			// Generar descendiente de girar a la derecha
			nodo hijoTurnR = current;
			hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
			if (generados.find(hijoTurnR.st) == generados.end()){
				costo = CalculaCoste(hijoTurnR.st);

				if(costo != 0){
					hijoTurnR.pathcost += costo + 1;
					hijoTurnR.secuencia.push_back(actTURN_R);
					cola.push(hijoTurnR);
				}
			}

		// Tomo el siguiente valor de la pila
		if (!cola.empty()){
			current = cola.top();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		cout << "Coste del plan: " << current.pathcost << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		plan.push_back(actIDLE);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}

// Sacar por la términal la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}



void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}


// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else {
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}



int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
