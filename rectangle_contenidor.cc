#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> Fila;
typedef vector<Fila> Rectangle;
void dimensions_minimes(char c, const Rectangle& r, int& fils, int& cols) {
	int fo=-1;
	int co=-1;
	int ff=-1;
	int cf=-1;
	for (int i=0 ; i<r.size() and fo<0 ; i++) {
		for (int j=0 ; j<r[0].size() and fo<0 ; j++) {
			if (r[i][j]==c) fo=i;
		}
	}
	for (int i=r.size()-1 ; i>=0 and ff<0 ; i--) {
		for (int j=r[0].size()-1 ; j>=0 and ff<0 ; j--) {
			if (r[i][j]==c) ff=i;
		}
	}
	for (int j=0 ; j<r[0].size() and co<0 ; j++) {
		for (int i=fo ; i<=ff and co<0 ; i++) {
			if (r[i][j]==c) co=j;
		}
	}
	for (int j=r[0].size()-1 ; j>=0 and cf<0 ; j--) {
		for (int i=ff ; i>=fo and cf<0 ; i--) {
			if (r[i][j]==c) cf=j;
		}
	}
	fils = ff-fo+1;
	cols = cf-co+1;
}
