#include <iostream>
#include <fstream>
using namespace std;

int Na, la[100005], ra[100005], va[100005], roota;
int Nb, lb[100005], rb[100005], vb[100005], rootb;
bool marka[100005], markb[100005];
void init() {
	cin >> Na;
	for (int i = 1; i <= Na; ++i) {
		cin >> la[i] >> ra[i] >> va[i];
		marka[la[i]] = marka[ra[i]] = true;
	}
	cin >> Nb;
	for (int i = 1; i <= Nb; ++i) {
		cin >> lb[i] >> rb[i] >> vb[i];
		markb[lb[i]] = markb[rb[i]] = true;
	}
	for (int i = 1; i <= Na; ++i) {
		if (!marka[i]) {
			roota = i;
		}
	}
	for (int i = 1; i <= Nb; ++i) {
		if (!markb[i]) {
			rootb = i;
		}
	}
}
bool isSame(int a, int b) {
	if ((a == 0 && b != 0) || (a != 0 && b == 0)) return false;
	if (a == 0 && b == 0) return true;
	if (va[a] != vb[b]) return false;
	return isSame(la[a], lb[b]) && isSame(ra[a], rb[b]);
}
int main()
{
	init();
	if (Na != Nb) { cout << "N" << endl; return 0; }
	if (isSame(roota, rootb)) cout << "Y" << endl;
	else cout << "N" << endl;
	return 0;
}