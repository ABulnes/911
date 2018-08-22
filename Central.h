/* 
tipoLlamada: variable int con valores 0,1,2,3,4
0 falsa alarma			30%
1 emergencia medica		25%
2 emergencia policial 	25%
3 emergencia bomberos	5%
4 llamadas canceladas	15%

estadoCabina 1 libre, 0 ocupada
*/

#ifndef CENTRAL_H_
#define CENTRAL_H_
#include <pthread.h>
#include <iostream>
#include <time.h>
#include <windows.h>
#include "Bomberos.h"
#include "comisaria.h"
#include "Hospital.h"

using namespace std;

pthread_mutex_t estado = PTHREAD_MUTEX_INITIALIZER;


class Central
{
public:
	static void* atenderLlamada(void* data) {
		pthread_mutex_lock(&estado);

		pthread_t hilosPatrulla[3];
		pthread_t hilosHospital[3];
		pthread_t hilosBomberos[3];

		for (int i = 0; i < 3; i++) {
			pthread_create(&hilosHospital[i], nullptr,Hospital::atenderMedico,nullptr);
			pthread_create(&hilosBomberos[i], nullptr,Bomberos::atenderBomberos,nullptr);
			pthread_create(&hilosPatrulla[i], nullptr,Comisaria::atenderSituacion, nullptr);
		}

		srand(time(NULL));
		idCabina = 1+rand() % 40;

		cout << "---------------------------------------------\n" << 
		"Cabina  " << idCabina << " atendiendo recibe llamada  \n";
		cout << "Llamada en proceso, esperando a establecer el tipo de llamada...\n";
		Sleep(2000);
		tipoLLamada = rand() % 99; //0-29 falsa, 30-54 medica, 55-69 poli, 70-75 Bomb, 76-99 canceladas
		//===================================================================================
		if (tipoLLamada < 30)
		{
			cout << "Falsa alarma, descartar la llamada\n";	
		}
		if (tipoLLamada >=30 && tipoLLamada < 55)
		{
			cout << "Emergencia medica\n";
			pthread_join(hilosHospital[0], nullptr);
			pthread_join(hilosHospital[1], nullptr);
			pthread_join(hilosHospital[2], nullptr);
		}
		if (tipoLLamada >= 55 && tipoLLamada < 70)
		{
			cout << "Requiere presencia policial\n";
			pthread_join(hilosPatrulla[0], nullptr);
			pthread_join(hilosPatrulla[1], nullptr);
			pthread_join(hilosPatrulla[2], nullptr);
		}
		if (tipoLLamada >= 70 && tipoLLamada < 75)
		{
			cout << "Requiere presencia de bomberos\n";
			pthread_join(hilosBomberos[0], nullptr);
			pthread_join(hilosBomberos[1], nullptr);
			pthread_join(hilosBomberos[2], nullptr);
		}
		if (tipoLLamada >= 75 && tipoLLamada < 100)
		{
			cout << "La llamada no se concreto, esperando nuevas llamadas\n";
		}

		pthread_mutex_unlock(&estado);
		return nullptr;
				
	}//===============================================================================================================================
};

#endif /* CENTRAL_H_ */
