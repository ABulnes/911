/*
 * comisaria.h
 *
 *  Created on: 14 ago. 2018
 *      Author: ABulnes
 */

#ifndef COMISARIA_H_
#define COMISARIA_H_
#include <pthread.h>
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

pthread_mutex_t situacion = PTHREAD_MUTEX_INITIALIZER;

int v_proceso, v_zona;
string zonas[6] = { "zona A", "zona B", "zona C", "zona D", "zona E", "zona F" };
int contzona[6] = { 0, 0, 0, 0, 0, 0,};
int id_patrulla;
class Comisaria {

public:

	static void* atenderSituacion(void* data) {

		pthread_mutex_lock(&situacion);

		srand(time(NULL));
		v_zona = rand() % 6;
		id_patrulla = 1+rand() % 10;
		cout << "Comisaria atiende situacion en  " <<zonas[v_zona] <<endl;
		cout << "---------------------------------------------" << endl;
		cout << "Patrulla  " << id_patrulla << " atendiendo situacion en "
				<< zonas[v_zona] << endl;
		cout << "---------------------------------------------" << endl;
		Sleep(1000);
		contzona[v_zona]++; // Aumenta el contador de zona
		cout << "Patrulla en camino: estimando llegada " << rand() % 30 + 10
				<< " minutos" << endl;
		Sleep(5000);
		v_proceso = rand() % 2; // Variable que indica las situaciones en las que puede caer una patrulla
		//Situacion en la que puede atrapar a un delicuente
		if (v_proceso == 0) {
			cout <<"Patrulla esta atrapando al delincuente " << endl; Sleep(1000);
			if (rand() % 2 == 0) {
				cout << "Patrulla atrapa al delincuente" << endl; Sleep(1000);
				cout << "Patrulla lleva detenido hacia la comisaria" << endl;
				Sleep(5000);
				cout << "Patrulla " << id_patrulla << "  llego a la central"<< endl; 
				Sleep(1000);
			} else {
				cout << "Patrulla atrapa al delincuente" << endl; Sleep(1000);
				cout << "La patrulla tuvo un incidente en el camino" << endl;
				Sleep(5000);
				cout << "Patrulla " << id_patrulla << "  llego a la central" << endl; 
				Sleep(1000);
			}
		} else {
			//Situacion en la que pide refuerzos
			if (v_proceso == 1) {
				cout << "Patrulla " << id_patrulla << " solicita refuerzos" << endl; 
				Sleep(1000);
				//Operacion aleatoria de a que refuerzo llamara si bombero o ambulancia
				if (rand() % 3 == 0) {
					cout << "Hay heridos patrulla requiere ambulancia" << endl;
					Sleep(1000);
					cout << "Ambulancia va en camino... " << endl;
					Sleep(1000);
					cout << "Ambulancia llego a " << zonas[v_zona] << endl;
					Sleep(1000);
					cout << "Ambulancia atendiendo heridos...." << endl;
					Sleep(1000);
					cout << "Policia patrullando zona..." << endl;
					Sleep(1000);
					Sleep(rand() % 4 + 1);
					cout << "Se resolvio con los refuerzos, se capturo a los individuos"	<< endl;
					Sleep(1000);
					cout << "Patrullas van en camino a comisaria, con los detenidos"	<< endl;
					Sleep(1000);
					cout << "Ambulancia regresa a la central" << endl;
					Sleep(1000);
					cout << "Patrullas llegaron a comisaria" << endl; 
					Sleep(1000);

				} else {
					if (rand() % 3 == 1) {
						cout << "Hay situacion critica patrulla requiere bomberos" << endl;
						Sleep(1000);
						cout << "Bomberos van en camino... " << endl;
						Sleep(1000);
						cout << "Bombero llego a " << zonas[v_zona] << endl;
						Sleep(1000);
						cout << "Bombero atendiendo situacion" << endl;
						Sleep(5000);
						cout << "La situacion se resolvio " << endl;
						Sleep(1000);
						cout << "Patrullas vuelven a comisaria" << endl;
						Sleep(1000);
						cout << "Bomberos vuelven a central" << endl;
					} else {
						if (rand() % 3 == 2) {
							cout << "Las patrullas llegaron  a auxiliar patrulla  "<< id_patrulla << endl;
							Sleep(500);
							cout << "Patrullas atendiendo situacion " << endl;
							Sleep(3000);
							if (rand() % 2 == 0) {
								cout << "Las patrullas encontraron al delincuente" << endl;
								Sleep(1000);
								cout << "Las patrullas vuelven a comisaria" << endl;

							} else {
								cout << "Las patrullas perdieron al delicuente" << endl;
								Sleep(1000);
								cout << "Los refuerzos vuelven a comisaria" << endl;
								Sleep(1000);
							}

						}else{
							cout << "Los refuerzos llegaron a asistir a la patrulla" << endl;
							Sleep(1000);
							cout << "Los refuerzos solucionarion el problema" << endl;
							Sleep(1000);
							cout << "Patrulla " << id_patrulla << " volviendo a comisaria" << endl;
							Sleep(4000);
							cout << "Refuerzos volviendo a comisaria"<<endl;
							Sleep(4000);
						}
					}
				}

			} else {
				//Atencion  en la que la situacion no se pudo solucionar
				if (v_proceso == 2) {
					cout << "El delincuente escapo" << endl;
					cout << "Patrulla " << id_patrulla << " patrullando la zona" << zonas[v_zona] << endl;
					Sleep(1000);
					if (rand() % 2 == 0) {
						cout << "La patrulla encontro al delincuente" << endl;
						Sleep(1000);
						cout << "La patrulla vuelve a comisaria con el delicuente"<< endl;
						Sleep(1000);

					} else {
						cout << "La patrulla no encontro al delincuente" << endl;
						Sleep(1000);
						cout << "La patrulla vuelve a comisaria" << endl; 
						Sleep(1000);
 					}
					contzona[v_zona]++;
				}
			}
		}
		//Verificar las zonas conflictivas, en caso de ser mayor a 5 indica una zona con mucha incidencia
		for (int i = 0; i < 4; i++) {
			if (contzona[i] >= 5) {
				cout << "Se han detectado muchos delitos en  " << zonas[i] << " enviando patrulla a resguardar " << endl;
				contzona[i] = 0;
			}
		}
		cout << "------------------------------------------" << endl;
		pthread_mutex_unlock(&situacion);

		return nullptr;
	}
};

#endif /* COMISARIA_H_ */
