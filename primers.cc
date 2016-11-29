#include <iostream>
#include <vector>
using namespace std;

int suma_digits(int x) {
	int suma=0;
	for (int i=x ; i>0 ; i=i/10) {
		suma += i%10;
	}
	return suma;
}
bool es_primer(int n) {
	if (n<=1) return false;
	if (n!=2 && n%2==0) return false;
	for (int i=3 ; i*i <= n ; i +=2) {
		if (n%i==0) return false;
	}
	return true;
}
bool es_primer_perfecte(int n) {
	if (n<10) return es_primer(n);
	else if ( !es_primer_perfecte(suma_digits(n)) ) return false;
	return es_primer(n);
}
int main () {
	int ent;
	while (cin >>ent) {
		if (es_primer_perfecte(ent)) cout << "true" << endl;
		else cout << "false" << endl;
	}
}
