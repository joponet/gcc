#include <iostream>
#include <vector>
using namespace std;
void mostra(vector<int>& matriu) {
	int posicions = matriu.size();
	for (int i=0 ; i< posicions ; i++) {
		if (matriu[i]==0) { cout << ".";}
		else if (matriu[i]==1) {cout << ">";}
		else {cout << "<";}
	}
	cout << endl;
}
void mou(vector<int>& matriu) {
	int posicions = matriu.size();
	int i=0;
	while (i<posicions) {
		int dir=matriu[i];
		if (dir>0 && i==posicions-1) {
			matriu[i]=0;
			matriu[i-1]=-1;
		}
		else if (dir<0 && i==0) {
			matriu[0]=0;
			matriu[1]=1;
			i++;
		}
		else if (dir!=0 && matriu[i+dir]==0) {
			matriu[i]=0;
			matriu[i+dir]=dir;
			if (dir==1) {i++;}
		}
		else if (dir!=0 && matriu[i+dir]!=0) {
			matriu[i]=0;
			matriu[i-1]=-1;
			i++;
			matriu[i]=0;
			matriu[i+1]=1;
			i++;
		}
		i++;
	}
}
int main() {
	int posicions;
	while(cin >> posicions) {
		int iteracions;
		cin >> iteracions;
		vector<int> matriu(posicions);
		int dreta;
		cin >>dreta;
		for (int i=0 ; i<dreta ; i++) {
			int ent;
			cin >> ent;
			matriu[ent-1]=1;
		}
		int esquerra;
		cin >>esquerra;
		for (int i=0 ; i<esquerra ; i++) {
			int ent;
			cin >> ent;
			matriu[ent-1]=-1;
		}
		mostra(matriu);
		for (int i=0 ; i<iteracions-1 ; i++) {
			mou(matriu);
			mostra(matriu);
		}
		cout << endl;
	}
}
