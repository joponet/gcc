#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int cont;
void mostra(vector<int>& llista) {
	return;
	for (int i=0 ; i<llista.size() ; i++) {
		if (i!=0) cout << " ";
		cout << llista[i];
	}
	cout << endl;
}
void ordena(vector<int>& llista, int pi, int pf, int rec) {
	cont++;
	cout << cont << " - " << rec << " : " << pi << " " << pf << endl;
	if (pf<=pi) return;
	int pe=pi;
	int pd=pf-1;
	int pivot=llista[pf];
	while (pe<pd) {
		while (llista[pe]<pivot && pe<pd) {
			pe++;
		}
		while (llista[pd]>pivot && pe<pd) {
			pd--;
		}
		int tmp=llista[pe];
		llista[pe]=llista[pd];
		llista[pd]=tmp;
	}
	if (llista[pd]>pivot) {
		llista[pf]=llista[pd];
		llista[pd]=pivot;
		mostra(llista);
		if (pd-1>pi) ordena(llista, pi, pd-1, rec+1);
		if (pd+1<pf) ordena(llista, pd+1, pf, rec+1);
	}
	else {
		mostra(llista);
		if (pi<pf-1) ordena(llista, pi, pf-1, rec+1);
	}
}
int main() {
	int longitud;
	cin >> longitud;
	vector <int> llista(longitud);
	srand(time(NULL));
	for (int i=0 ; i<longitud ; i++) {
		//cin >> llista[i];
		llista[i]=rand()%10000;
	}
	mostra(llista);
	//cout << endl;
	cont=0;
	ordena(llista,0,longitud-1,1);
	//cout << endl;
	mostra(llista);
}
