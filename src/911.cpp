//============================================================================
// Name        : 911.cpp
// Author      : Grupo # 2 
// Version     :
// Copyright   : Proyecto de la clase de Sistemas Operativos
//============================================================================

#include <iostream>
using namespace std;
#include "Comisaria.h"
#include "Hospital.h"
#include "Bomberos.h"
#include <pthread.h>
#include <time.h>
#include <windows.h>
pthread_t hilosCentral[3];
string tipo_llamada[4] = {"Policiaca","Emergencia Medica","Bomberos","Falsa Alarma"};
int v_central;
int main() {
	cout << "Central iniciando operaciones";Sleep(1000);
	for(int j=0; j<3; j++){
				cout << ".";Sleep(100);
			}
	Sleep(1000);
	cout << endl;
	for(int i=0; i<30; i++){
		srand(time(NULL));
		v_central = rand()%4;
		cout << "---------------------------------------------" << endl;
		cout << "Entra llamada" << endl;
		Sleep(1000);
		cout <<"Llamada de tipo " << tipo_llamada[v_central] << endl;
		Sleep(1000);
		if(v_central ==0){
			cout << "Central redirige llamada a comisaria" << endl;
			Sleep(1000);
			cout << "Comisaria atiende llamada" << endl;
			Sleep(1000);
			pthread_create(&hilosCentral[0],nullptr,Comisaria::atenderSituacion,nullptr);
			pthread_join(hilosCentral[0],nullptr);
		}else{
			if(v_central ==1){
				cout << "Central redirige llamada a hospital" << endl;
				Sleep(1000);
				cout << "Hospital atiende llamada" << endl;
				Sleep(1000);
				pthread_create(&hilosCentral[1],nullptr,Hospital::atenderMedico,nullptr);
				pthread_join(hilosCentral[1],nullptr);
			}else{
				if(v_central == 2){
					cout << "Central redirige llamada a central de bomberos" << endl;
					Sleep(1000);
					cout << "Central de Bomberos atiende llamada" << endl;
					Sleep(1000);
					pthread_create(&hilosCentral[2],nullptr,Bomberos::atenderBomberos,nullptr);
					pthread_join(hilosCentral[2],nullptr);
				}else{
					if(rand()%2==0){
						cout << "Operador realizando procesos administrativos" << endl;
						Sleep(6000);
						cout << "Operador termina trabajo administativo" << endl;
						Sleep(1000);
					}else{
						if(rand()%2==1){
							cout << "Operador realizando procesos administrativos" << endl;
							Sleep(6000);
							cout << "Operador termina trabajo administativo" << endl;
							Sleep(1000);
						}
					}
				}
			}
		}
	}


	return 0;
}
