#include <iostream>
using namespace std;
void int_to_bin (int entrada);
int main () {
	int entrada;
	cout << "Valor: ";
	cin >> entrada;
	int_to_bin(entrada);
	cout << endl;
}

void int_to_bin (int entrada) {
	if (entrada>0) {
		int_to_bin(entrada>>1);	
		cout << (entrada & 1);
	}
}
