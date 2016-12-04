#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef vector<char> Fila;
typedef vector<Fila> Matriu;
bool compara(string& paraula, int pos, Matriu& matriu, int x, int y, int dx, int dy) {
	if (pos == paraula.size()) return true;
	if (x<0 || x>=matriu.size() || y<0 || y>=matriu[0].size()) return false;
	if (paraula[pos] != tolower(matriu[x][y])) return false;
	if (not compara(paraula, pos+1, matriu, x+dx, y+dy, dx, dy)) return false;
	matriu[x][y] = toupper(matriu[x][y]);
	return true;
}
int main () {
	int paraules, files, columnes;
	bool separa=false;
	while (cin >> paraules >> files >> columnes) {
		vector <string> llista(paraules);
		Matriu matriu(files,Fila(columnes));
		for (int i=0 ; i<paraules ; i++) {
			cin >> llista[i];
		}
		for (int i=0 ; i<files ; i++) {
			for (int j=0 ; j<columnes ; j++) {
				cin >> matriu[i][j];
			}
		}
		for (int n=0 ; n<paraules ; n++) {
			for (int i=0 ; i<files ; i++) {
				for (int j=0 ; j<columnes ; j++) {
					compara (llista[n], 0, matriu, i,j,0,1);
					compara (llista[n], 0, matriu, i,j,1,1);
					compara (llista[n], 0, matriu, i,j,1,0);
				}
			}
		}
		if (separa) cout << endl;
		for (int i=0 ; i<files ; i++) {
			for (int j=0 ; j<columnes ; j++) {
				if (j!=0) cout << " ";
				cout << matriu[i][j];
			}
			cout << endl;
		}
		separa=true;
	}
}
