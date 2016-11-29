#include <iostream>
#include <vector>
using namespace std;
vector<int> llista(1001);
int main() {
	int n;
	cin>>n;
	for (int i=1; i<=n; i++) {
		int ent;
		cin>>ent;
		int id=ent%10000;
		llista[id]++;
	}	
	for (int i=0 ; i<=1000 ; i++) {
		if (llista[i]>0) {
			cout << 1000000000 + i << " : " << llista[i] << endl;
		}
	}
}
