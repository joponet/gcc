#include <iostream>
using namespace std;
int entrada;
void int_to_bin (int pot);
int main () {
	cout << "Valor: ";
	cin >> entrada;
	int_to_bin(1);
	cout << endl;
}

void int_to_bin (int pot) {
	int digit;
	digit = entrada & pot;
	pot <<= 1;
	if (pot<=entrada) int_to_bin(pot);	
	cout << (digit>0)?1:0;
}
