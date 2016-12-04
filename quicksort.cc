#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void mostra(vector<int>& llista) {
	if (llista.size()>30) return;
	for (int i=0 ; i<llista.size() ; i++) {
		if (i!=0) cout << " ";
		cout << llista[i];
	}
	cout << endl;
}
void ordena(vector<int>& llista, int pi, int pf, int& cicles) {
	cicles++;
	if (llista.size()<10000) cout << cicles << ":" << pi << "-" << pf << endl;
	if (pf<=pi) return;
	int pe=pi;
	int pd=pf-1;
	int pivot=llista[pf];
	while (pe<pd) {
		while (llista[pe]<=pivot && pe<pd) {
			pe++;
		}
		while (llista[pd]>=pivot && pe<pd) {
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
		if (pd-1>pi) ordena(llista, pi, pd-1, cicles);
		if (pd+1<pf) ordena(llista, pd+1, pf, cicles);
	}
	else {
		mostra(llista);
		if (pi<pf-1) ordena(llista, pi, pf-1, cicles);
	}
}
int main() {
	int longitud;
	int cicles=0;
	cin >> longitud;
	vector <int> llista(longitud);
	srand(time(NULL));
	for (int i=0 ; i<longitud ; i++) {
		//cin >> llista[i];
		llista[i]=rand()%100000000;
	}
	mostra(llista);
	clock_t inici=clock();
	ordena(llista,0,longitud-1,cicles);
	clock_t fi=clock();
	cout << endl << "Cicles: " << cicles << endl;
	cout << "Temps: " << fi-inici << endl;
	mostra(llista);
}
