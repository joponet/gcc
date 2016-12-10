#include <iostream>
#include <vector>
#include "rectangle_contenidor.cc"
using namespace std;
typedef vector<char> Fila;
typedef vector<Fila> Rectangle;
int main () {
	static const char llista[5][6] = {
		{'o','o','o','o','o','o'},
		{'o','o','c','c','o','o'},
		{'o','c','c','o','c','o'},
		{'o','o','o','c','o','o'},
		{'o','o','o','o','o','o'}
	};
	char c='c';
	Rectangle rectangle(5,Fila(6));
	int files;
	int columnes;
	for (int i=0 ; i<5 ; i++) {
		for (int j=0 ; j<6 ; j++) {
			rectangle[i][j]=llista[i][j];
		}
	}
	dimensions_minimes(c,rectangle,files,columnes);
	cout << files << ":" << columnes << endl;
}
