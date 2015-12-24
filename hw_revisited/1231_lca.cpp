#include <iostream>
using namespace std;

int N, X, Y;
int father[10000];
int candidate[10000], sz = 0;

int main()
{
	cin >> N >> X >> Y;
	for (int i = 1; i <= N; ++i) {
		int l, r;
		cin >> l >> r;
		if (l != 0) father[l] = i;
		if (r != 0) father[r] = i;
	}
	while (X != 0) {
		candidate[++sz] = X;
		X = father[X];
	}
	while (Y != 0) {
		for (int i = 1; i <= sz; ++i) {
			if (Y == candidate[i]) {
				cout << Y << endl;
				return 0;
			}
		}
		Y = father[Y];
	}
	return 0;
}