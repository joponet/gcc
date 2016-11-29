#include <iostream>
using namespace std;
int main () {
	int entrada;
	int pot;
	cout << "Valor: ";
	cin >> entrada;
	for ( pot=1 ; pot<=entrada ; pot<<=1);
	while (pot>1) {
		pot >>= 1;
		int digit = entrada & pot;
		cout << (digit>0)?1:0;
	}
	cout << endl;
}
