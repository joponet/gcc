#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

Matriu suma(const Matriu& a, const Matriu& b) {
	int row = a.size();
	if (row==0) {
		return a;
	}
	int col = a[0].size();
	Matriu re(row, vector<int>(col));
	for(int i=0; i < row; i++)
		for(int j=0; j < col; j++)
			re[i][j] = a[i][j] + b[i][j];
	return re;
}

int main() {
	int s=0;
	Matriu a(s, vector<int>(s));
	Matriu b(s, vector<int>(s));
	for(int j=0; j < s; j++) {
		for(int i=0; i < s; i++) {
			a[j][i] = 2;
			b[j][i] = 2;
		}
	}
	Matriu r = suma(a,b);
	for(int j=0; j < s; j++) {
		for(int i=0; i < s; i++) {
			cout << r[j][i] << " ";
		}
		cout << endl;
	}
}
