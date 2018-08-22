//============================================================================
// Name        : 911.cpp
// Author      : Grupo # 2 
// Version     :
// Copyright   : Proyecto de la clase de Sistemas Operativos
//============================================================================

#include <iostream>
#include "comisaria.h"
#include "Hospital.h"
#include "Central.h"

using namespace std;

int max_patrullas = 10;
int main() {

	pthread_t hilosCentral[3];
	for (int i = 0; i < 3; i++) {
		//Asi se realiza el llamado del hilo de hospital
		//pthread_create(&hilosPatrulla[i],nullptr,Hospital::atenderMedico,nullptr);
		//Asi se realiza el llamado del hilo de comisaria
		pthread_create(&hilosCentral[i], nullptr,Central::atenderLlamada, nullptr);
	}

	pthread_join(hilosCentral[0], nullptr);
	pthread_join(hilosCentral[1], nullptr);
	pthread_join(hilosCentral[2], nullptr);

	return 0;
}
