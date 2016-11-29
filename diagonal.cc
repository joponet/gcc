#include <iostream>
using namespace std;
int main () {
	int files,columnes;
	std::cin >> files >> columnes;
	for (int i=0; i<files ; i++) {
		for (int j=0; j<columnes ; j++) {
			cout << (j>i?(j-i)%10:(i-j)%10);
		}
		cout << endl;
	}
}
