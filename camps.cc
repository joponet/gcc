#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Fila;
typedef vector<Fila> Matriu;
int main() {
	int m,n;
	while (cin >> m >> n) {
		Matriu matriu(m,Fila(n));
		int cont=0;
		for (int i=0 ; i<m ; i++) {
			int ultim=0;
			for (int j=0 ; j<n ; j++) {
				cin >> matriu[i][j];
				if (matriu[i][j]>0 && ultim==0 && (i==0 || matriu[i-1][j]==0)) cont++;
				ultim = matriu[i][j];
			}
		}
		cout << cont << endl;
	}
}
