#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

#include "cpu_timer.h"

using namespace std;


int n_pigeons, q_pigeonniers; // n_pigeons = nombre de pigeons, q_pigeonniers = nombre de pigeonniers



//Pour le moment la matrice contient des 0 partout sauf dans le cas où i=j
void remplirMatriceTab(int * matrice, int CMAX, int LMAX){

	for(int i=0;i<LMAX;i++){

		for(int j=0;j<CMAX;j++){

			matrice[ i * CMAX + j] = i == j ? 1 : 0;

		}
	}
}


int main(int argc, char ** argv){

	// recupérer le nombre de pigeons et le nombre de pigeonniers
	if (argv[1] && argv[2]) {
		n_pigeons = atoi(argv[1]);
		q_pigeonniers = atoi(argv[2]);
	}

	// initialiser un tableau de n * q
	int * matrice = new int [n_pigeons * q_pigeonniers];

	// créer une matrice identité
	for (int i=0; i<n_pigeons; i++) {
		for (int j=0; j<q_pigeonniers; j++) {
			if (i == j)
				matrice[i*j] = 1;
			else
				matrice[i*j] = 0;
		}
	}

	for (int i=0; i<n_pigeons; i++) {
		for (int j=0; j<q_pigeonniers; j++) {
			cout << matrice[i*j] << "\t";
		}
		cout << endl;
	}


	return 0;
}
