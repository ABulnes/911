/*
 * Bomberos.h
 *
 *  Created on: 21 ago. 2018
 *      Author: RLizardo
 */



#ifndef BOMBEROS_H_
#define BOMBEROS_H_

#include <iostream>
using namespace std;
#include <time.h>
#include <windows.h>

pthread_mutex_t situacion_bomberos = PTHREAD_MUTEX_INITIALIZER;

int v_procesoB, id_patrullaB, v_tpb, v_eq, v_sit, v_derrum, v_inc, v_exp, v_acci, v_urg;
string tipo_patrulla_b[3] = {"Camion de bomberos", "Helicoptero"};
string equipo[9] = {"mangueras","motosierras","hachas","cortadoras","palas","camillas","cuerdas","poleas","herramientas hidraulicas"};
string situaciones[3] = {"Accidente de trafico","Derrumbe","Incendio"};
string c_derrumbes[3] = {"Terremoto","Lluvia fuerte","Avalancha"};
string c_incendios[4] = {"Lava","Cortocircuito","Explosion","Accidetal"};
string c_explosiones[2] = {"Fuga de gas","Elementos peligrosos"};
string c_accidentales[4] = {"Fosforos","Velas","Cigarros","Lampara"};
string urgencia[2] = {"grave","leve"};

class Bomberos{
public:
static void * atenderBomberos(void*) {
	pthread_mutex_lock(&situacion_bomberos);
	srand(time(NULL));
	//Variables del proceso
	v_procesoB = rand() % 3; // Variable de manejo del proceso
	v_tpb = rand() % 2; // Tipo de patrulla de bomberos
	id_patrullaB = 1 + rand() % 10; // ID de la patrulla de bomberos
	v_eq = rand() % 9; // Tipo de equipo
	v_sit = rand() % 3; // Tipo de situaciones
	v_derrum = rand() % 3; // Tipo de causas de derrumbes
	v_inc = rand() % 4; //Tipo de causas de incendios
	v_exp = rand()  % 2; // Tipo de causas de explosiones
	v_acci = rand() % 4; //Tipo de causas accidentales
	v_urg = rand() % 2; //Tipo de urgencia


	cout << "Los bomberos reciben la solicitud debido a " << situaciones[v_sit] << endl; Sleep(1000);

	switch(v_procesoB){
				case 0:	//Accidente de trafico
					cout << "Situacion a enfrentar: " << situaciones[v_sit] << endl; Sleep(1000);
					cout << "Los bomberos enviaron un " << tipo_patrulla_b[v_tpb] <<endl; Sleep(1000);
					cout << tipo_patrulla_b[v_tpb] << " "<< id_patrullaB <<" va en camino al " << situaciones[v_sit] << endl; Sleep(3000);
					cout << "Los bomberos llegaron " << endl; Sleep(1000);
					cout << "Equipo necesario para la situacion: " << equipo[v_eq] << endl;Sleep(1000);
					heridosUrg();
					cout << tipo_patrulla_b[v_tpb] << " regresa a la estacion" << endl; Sleep(1000);
					cout << tipo_patrulla_b[v_tpb] << " llego a la estacion" << endl;
				break;
				case 1: // Derrumbes
					cout << "Situacion a enfrentar: " << situaciones[v_sit] << endl; Sleep(1000);
					cout << "Los bomberos enviaron un " << tipo_patrulla_b[v_tpb] <<endl; Sleep(1000);
					cout << tipo_patrulla_b[v_tpb] <<" "<< id_patrullaB << " va en camino al " << situaciones[v_sit] << endl; Sleep(3000);
					cout << "Los bomberos llegaron " << endl; Sleep(1000);
					cout << "Causa del derrumbe: " << c_derrumbes[v_derrum] << endl; Sleep(1000);
					int equi;
					if(v_eq == 0){
						equi = v_eq + 1;
					}else{
						equi = v_eq;
					}
					cout << "Equipo necesario para la situacion: " << equipo[equi] << endl;Sleep(1000);
					heridosUrg();
					cout << tipo_patrulla_b[v_tpb] << " regresa a la estacion" << endl; Sleep(1000);
					cout << tipo_patrulla_b[v_tpb] << " llego a la estacion" << endl;
				break;
				case 2: // Incendios
					cout << "Situacion a enfrentar: " << situaciones[v_sit] << endl; Sleep(1000);
					cout << "Los bomberos enviaron un " << tipo_patrulla_b[v_tpb] <<endl; Sleep(1000);
					cout << tipo_patrulla_b[v_tpb] << " "<< id_patrullaB <<" va en camino al " << situaciones[v_sit] << endl; Sleep(3000);
					cout << "Los bomberos llegaron " << endl; Sleep(1000);
					cout << "Causa del incendio: " << c_incendios[v_inc] << endl; Sleep(1000);
					if(v_inc == 2){
						cout << "La explosion fue producida por: " << c_explosiones[v_exp] << endl; Sleep(1000);
					} else
						if(v_inc == 3){
							cout << "La explosion fue producida por: " << c_accidentales[v_acci] << endl; Sleep(1000);
						}
					cout << "Equipo necesario para la situacion: " << equipo[v_eq] << endl;Sleep(1000);
					heridosUrg();
					cout << tipo_patrulla_b[v_tpb] << " regresa a la estacion" << endl; Sleep(1000);
					cout << tipo_patrulla_b[v_tpb] << " llego a la estacion" << endl;
				break;
	}
	pthread_mutex_unlock(&situacion_bomberos);
	return 0;

}

static void heridosUrg(){
	if(rand()%2 == 0){ // Hay heridos
		cout << "Hay heridos en el accidente con una urgencia " << urgencia[v_urg] << endl; Sleep(1000);
		if(v_urg == 0){
			cout << "¡Hay un herido en una situacion grave!" << endl; Sleep(1000);
			cout << "Los bomberos decidieron llamar al hospital... " << endl; Sleep(1000);
			cout << "La ambulancia va en camino..." << endl; Sleep(3000);
			cout << "La ambulancia llego" << endl; Sleep(1000);
			cout << "La ambulancia atiende al herido" << endl; Sleep(1000);
			cout << "La ambulancia atendio con exito al herido!" << endl; Sleep(1000);
			cout << "La ambulancia regresa al hospital" << endl; Sleep(1000);
		} else{
			cout << "Los bomberos no tienen problema al atender al herido"<< endl; Sleep(1000);
						}
	} else{ //No hay heridos
		cout << "No se encontraron heridos en el accidente " << endl; Sleep(4000);
	}
}

};


#endif /* BOMBEROS_H_ */

