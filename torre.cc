#include <iostream>
using namespace std;
void mou (int nivell,char origen, char desti, char tmp);
int main() {
	int nivell;
	cin>>nivell;
	mou(nivell,'A','C','B');
}

void mou (int nivell,char origen, char desti, char tmp) {
	if (nivell>1) mou (nivell-1,origen,tmp,desti);
	cout << origen << "=>" << desti << endl;
	if (nivell>1) mou (nivell-1,tmp,desti,origen);
}
