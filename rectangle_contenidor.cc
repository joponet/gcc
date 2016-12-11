#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> Fila;
typedef vector<Fila> Rectangle;
void incrementa(int& fc, int dir, int& i, int vo, int vf) {
	i++;
	if (i>vf) {
		fc += dir;
		i = vo;
	}
}
void dimensions_minimes(char c, const Rectangle& r, int& fils, int& cols) {
	int fo=0;
	int ff=r.size()-1;
	int co=0;
	int cf=r[0].size()-1;
	int i=co;
	while ( r[fo][i]!=c ) incrementa(fo,1,i,co,cf);
	i=co;
	while ( r[ff][i]!=c ) incrementa(ff,-1,i,co,cf);
	i=fo;
	while ( r[i][co]!=c ) incrementa(co,1,i,fo,ff);
	i=fo;
	while ( r[i][cf]!=c ) incrementa(cf,-1,i,fo,ff);
	fils=ff-fo+1;
	cols=cf-co+1;
}
