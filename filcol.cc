#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriu;

int main() {
	int files, columnes;
	cin >> files >> columnes;
	Matriu matriu(files,Fila(columnes));
	for (int i=0 ; i<files ; i++) {
		for (int j=0 ; j<columnes ; j++) {
			cin >> matriu[i][j];
		}
	}
	string entrada;
	while (cin >> entrada) {
		cout << entrada << " ";
		if (entrada == "fila") {
			int f;
			cin >> f;
			cout << f << ": ";
			for (int i=0 ; i<columnes ; i++) {
					cout << matriu[f-1][i] << " ";
			}
		}
		else if (entrada == "columna") {
			int c;
			cin >> c;
			cout << c << ": ";
			for (int i=0 ; i<files ; i++) {
				cout << matriu[i][c-1] << " ";
			}
		}
		else {
			int f,c;
			cin >> f >> c;
			cout << f << " " << c << ": ";
			cout << matriu[f-1][c-1];
		}
		cout << endl;
	}
}
