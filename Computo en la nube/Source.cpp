#include <stdio.h>
#include <omp.h>
#include <iostream>

using namespace std;

void main() {
	//Se preparan los arreglos
	int arryA[1000];
	int arryB[1000];
	int resultado[1000];


	//Se Preparan los arreglos A y B
	for (int i = 0; i < 1000; i++) {
		arryA[i] = rand() % 1000;
		arryB[i] = rand() % 1000;
	}

	int threadId;
	int i = 0;

	// Determina cuantos elementos trabajará cada hilo
	int n_per_thread = 1000 / 100;


	//Esta es la sección que se realizará en cada hilo
#pragma omp parallel for shared(arryA, arryB, resultado) private(i) schedule(static, n_per_thread) num_threads(100)
	for (i = 0; i < 1000; i++) {
		resultado[i] = arryA[i] + arryB[i];
		printf("hilo %d, sumando %d + %d = %d \n", omp_get_thread_num(), arryA[i], arryB[i], resultado[i]);
	}

	//Se muestran los resultados
	for (int i = 0; i < 1000; i++) {
		printf("Resultado [%d]: %d \n", i, resultado[i]);
	}
}
