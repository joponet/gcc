#include <iostream>
#include <vector>
#include "rectangle_contenidor.cc"
using namespace std;
typedef vector<char> Fila;
typedef vector<Fila> Rectangle;
int main () {
	static const char llista[5][6] = {
		{'o','o','o','o','o','c'},
		{'o','o','c','c','o','o'},
		{'o','c','c','o','c','o'},
		{'o','o','o','c','o','o'},
		{'o','o','o','o','o','o'}
	};

/*	static const char llista[1][1] = {
		{'c'}
	};
*/
	int columnes=sizeof(llista[0]);
	int files=sizeof(llista)/columnes;
	cout << "Tamany: " << files << ":" << columnes << endl; 
	char c='c';
	Rectangle rectangle(files,Fila(columnes));
	for (int i=0 ; i<files ; i++) {
		for (int j=0 ; j<columnes ; j++) {
			rectangle[i][j]=llista[i][j];
		}
	}
	int fils;
	int cols;
	dimensions_minimes(c,rectangle,fils,cols);
	cout << "Resposta: " << fils << ":" << cols << endl;
}
