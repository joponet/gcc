#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
bool debug=false;
// mostra el vector
void mostra(vector<int>& llista) {
	if (llista.size()>30) return;
	for (int i=0 ; i<llista.size() ; i++) {
		if (i!=0) cout << " ";
		cout << llista[i];
	}
	cout << endl;
}

// ordena mode quick
void ordena_mode_quick(vector<int>& llista, int pi, int pf, int& cicles) {
	cicles++;
	if (debug) cout << cicles << ":" << pi << "-" << pf << endl;
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
		if (debug) mostra(llista);
		if (pd-1>pi) ordena_mode_quick(llista, pi, pd-1, cicles);
		if (pd+1<pf) ordena_mode_quick(llista, pd+1, pf, cicles);
	}
	else {
		if (debug) mostra(llista);
		if (pi<pf-1) ordena_mode_quick(llista, pi, pf-1, cicles);
	}
}

// ordena mode llista
void ordena_mode_llista(vector<int>& llista, int pi, int pf, int& cicles) {
	cicles++;
	int pm=(pi+pf+1)/2;
	if (pm-1-pi>0) ordena_mode_llista(llista,pi,pm-1,cicles);
	if (pf-pm>0) ordena_mode_llista(llista,pm,pf,cicles);
	int pe=pi;
	int pd=pm;
	while (pe<pd && pd<=pf) {
		if(llista[pe]>llista[pd]) {
			int tmp=llista[pd];
			for (int i=pd ; i>pe ; i--) llista[i]=llista[i-1];
			llista[pe]=tmp;
			pd++;
		}
		else {
			pe++;
		}
	}
	if (debug) {
		cout << cicles << ":" << pi << "-" << pf << endl;
		mostra(llista);
	}
}

// ordena mode fusio
void fusiona(vector<int>& llista, int pi, int pm, int pf) {
	int n=pf-pi+1;
	vector<int> aux(n);
	int i=pi;
	int j=pm +1;
	int k=0;
	while(i<=pm and j<=pf) {
		if (llista[i] <= llista[j]) {
			aux[k] = llista[i];
			++i;
		}
		else {
			aux[k] = llista[j];
			j++;
		}
		k++;
	}
	while (i<=pm) {
		aux[k]=llista[i];
		k++;
		i++;
	}
	while (j<=pf) {
		aux[k]=llista[j];
		k++;
		j++;
	}
	for (k=0 ; k<n ; k++) llista[pi+k] = aux[k];
}
void ordena_mode_fusio(vector<int>& llista, int pi, int pf, int& cicles) {
	cicles++;
	int pm=(pi+pf)/2;
	if (pi<pm) ordena_mode_fusio(llista, pi, pm, cicles);
	if (pm+1<pf) ordena_mode_fusio(llista, pm+1, pf, cicles);
	fusiona(llista, pi, pm, pf);
	if (debug) {
		cout << cicles << ":" << pi << "-" << pm << "-" << pf << endl;
		mostra(llista);
	}
}
// ordena per doble matriu
void ordena_mode_matriu (vector<int>& llista, int pi, int pf, int& cicles) {
	int longitud = pf-pi+1;
	vector<int> aux(longitud);
	for (int i=0 ; i<longitud ; i++) {
		aux[i]=llista[pi+i];
	}
	int pos=0;
	while (pos<=pf) {
		cicles++;
		int post=pos;
		int tmp=aux[post];
		for (int i=pos; i<longitud ; i++) {
			if (aux[i]<tmp) {
				post=i;
				tmp=aux[post];
			}
		}
		aux[post]=aux[pos];
		llista[pi+pos]=tmp;
		pos++;					
		if (debug) {
			cout << cicles << ":" << post << endl;
			mostra(aux);
		}
	}
}
// ordena
void ordena(vector<int>& llista, int longitud, char metode, string titol) {
	int cicles=0;
	vector<int> llista_tmp(longitud);
	for (int i=0 ; i<longitud ; i++) llista_tmp[i]=llista[i];
	cout << endl << "*** " << titol << endl;
	clock_t inici=clock();
	if (metode=='q') ordena_mode_quick(llista_tmp,0,longitud-1,cicles);
	if (metode=='l') ordena_mode_llista(llista_tmp,0,longitud-1,cicles);
	if (metode=='f') ordena_mode_fusio(llista_tmp,0,longitud-1,cicles);
	if (metode=='m') ordena_mode_matriu(llista_tmp,0,longitud-1,cicles);
	clock_t fi=clock();
	cout << "Cicles: " << cicles << endl;
	cout << "Temps: " << fi-inici << endl;
	mostra(llista_tmp);
}
// principal
int main(int argc, char* argv[]) {
	int longitud = 10000;
	int valors = 100000000;
	char metode = 't';
	if (argc>1) longitud = atoi(argv[1]);
	if (argc>2) valors = atoi(argv[2]);
	if (argc>3) metode = argv[3][0];
	if (argc>4 && argv[4][0]=='d') debug=true;
	cout << "Longitud: " << longitud << endl;
	cout << "Valors: " << valors << endl;
	vector <int> llista(longitud);
	srand(time(NULL));
	for (int i=0 ; i<longitud ; i++) {
		llista[i]=rand()%valors;
	}
	if (llista.size()<30) {
		cout << "Matriu:" << endl;
		mostra(llista);
	}
	if (metode=='t' || metode=='q') ordena(llista, longitud, 'q', "Quick");
	if (metode=='t' || metode=='l') ordena(llista, longitud, 'l', "Llista");
	if (metode=='t' || metode=='f') ordena(llista, longitud, 'f', "Fusió");
	if (metode=='t' || metode=='m') ordena(llista, longitud, 'm', "Matriu");
}
