#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> Fila;
typedef vector<Fila> Rectangle;
void dimensions_minimes(char c, const Rectangle& r, int& fils, int& cols) {
	int fo=0;
	int ff=r.size()-1;
	int co=0;
	int cf=r[0].size()-1;
	int i=co;
	while ( r[fo][i]!=c ) {
		i++;
		if ( i>cf) {
			fo++;
			i=co;
		}
	}
	i=co;
	while ( r[ff][i]!=c ) {
		i++;
		if ( i>cf ) {
			ff--;
			i=co;
		}
	}
	i=fo;
	while ( r[i][co]!=c ) {
		i++;
		if ( i>ff) {
			co++;
			i=fo;
		}
	}
	i=fo;
	while ( r[i][cf]!=c ) {
		i++;
		if ( i>ff) {
			cf--;
			i=fo;
		}
	}
	fils=ff-fo+1;
	cols=cf-co+1;
}
