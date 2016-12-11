#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Fila;
typedef vector<Fila> Matriu;
bool comprova(Matriu& matriu, int fo, int co, int ff, int cf) {
	vector <int> llista(10);
	for (int i=fo ; i<=ff ; i++) {
		for (int j=co ; j<=cf ; j++) {
			int valor=matriu[i][j];
			llista[valor]++;
			if (llista[valor]>1) return false;
		}
	}
	return true;
}
int main() {
	int n;
	Matriu matriu(9,Fila(9));
	cin >> n;
	for (int x=0; x<n; x++) {
		for (int i=0 ; i<9 ; i++) {
			for (int j=0 ; j<9 ; j++) {
				cin >> matriu[i][j];
			}
		}
		bool esok=true;
		for (int i=0 ; i<9 and esok ; i+=3) {
			for (int j=0 ; j<9 and esok ; j+=3) {
				int k=i+(j/3);
				esok = comprova(matriu,k,0,k,8);
				if (esok) esok = comprova(matriu,0,k,8,k);
				if (esok) esok = comprova(matriu,i,j,i+2,j+2);
			}
		}
		cout << (esok?"si":"no") << endl;
	}
}
