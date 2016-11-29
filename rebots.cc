#include <iostream>
#include <vector>
using namespace std;
void mostra(vector<int>& matriu,int pos) {
	if (matriu[pos]==0) { cout << ".";}
	else if (matriu[pos]==1) {cout << ">";}
	else {cout << "<";}
}
void mou(vector<int>& matriu) {
	int posicions = matriu.size();
	int i=0;
	while (i<posicions) {
		mostra(matriu,i);
		int dir=matriu[i];
		if (dir>0 && i==posicions-1) {
			matriu[i]=0;
			matriu[i-1]=-1;
		}
		else if (dir<0 && i==0) {
			matriu[0]=0;
			mostra(matriu,++i);
			matriu[i]=1;
		}
		else if (dir!=0 && matriu[i+dir]==0) {
			matriu[i]=0;
			if (dir==1) {
				mostra(matriu,++i);
				matriu[i]=dir;
			}
			else {
				matriu[i+dir]=dir;
			}
		}
		else if (dir!=0 && matriu[i+dir]!=0) {
			matriu[i-1]=-1;
			matriu[i]=0;
			mostra(matriu,++i);
			matriu[i]=0;
			mostra(matriu,++i);
			matriu[i]=1;
		}
		i++;
	}
	cout << endl;
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
		for (int i=0 ; i<iteracions-1 ; i++) {
			mou(matriu);
		}
		for (int i=0 ; i<posicions ; i++) {
			mostra(matriu,i);
		}
		cout << endl;
	}
}
