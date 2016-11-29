#include <iostream>
#include <vector>
using namespace std;

int size;
vector<int> llista;
vector<int> cont;

void push(int pos);

int main() {
	int n;

	cin>>n;
	if (n>0) {
		int ent;
		cin>>ent;
		llista.push_back(ent);
		cont.push_back(1);
		size=1;
	}

	for (int i=2; i<=n; i++) {
		int ent;
		cin>>ent;
		// cerca en la llista
		for (int j=0; j<size ; j++) {
			// inserir
			if (ent<llista[j]) {
				push(j);
				llista[j]=ent;
				cont[j]=1;
				j=size; // sortir del for
			// incrementar
			} else if (ent==llista[j]) {
				cont[j]++;
				j=size;
			// afegir al final
			} else if (j==size-1) {
				llista.push_back(ent);
				cont.push_back(1);
				size++;
				j=size;
			}
		}
	}
	
	for (int i=0 ; i<size ; i++) {
		cout << llista[i] << " : " << cont[i] << endl;
	}
}

void push(int pos) {
	size++;
	llista.push_back(0);
	cont.push_back(0);
	for (int i=size-1 ; i>pos ; i--) {
		llista[i]=llista[i-1];
		cont[i]=cont[i-1];
	}
}

