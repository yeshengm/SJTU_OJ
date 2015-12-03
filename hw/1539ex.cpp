#include <iostream>
using namespace std;

int N, cnt, bit = 1;
bool use[20];
int a[20];

bool isIVP(int xa, int ya, int xb, int yb) {
	return (xa == xb || ya == yb || xa - xb == ya - yb || xa - xb == yb - ya);
}

bool isValid() {
	for (int i = 1; i < bit - 1; ++i)
		if (isIVP(i, a[i], bit - 1, a[bit - 1]))
			return false;
	return true;
}

void print() {
	for (int i = 1; i < N; ++i) cout << a[i] << ' ';
	cout << a[N];
	cout << endl;
}

void goback(int i) {
	bit--; use[i] = false; a[bit] = 0;
}

void setbit(int i) {
	use[i] = true; a[bit++] = i;
}

void dfs() {
	if (bit == N + 1) {
		cnt++;
		if (cnt <= 3) print();
		return;
	}
   for (int i = 1; i <= N; ++i) {
		if (!use[i]) {
			setbit(i);
			if (isValid()) dfs();
			goback(i);
		}
	}
}

int main() {
	cin >> N;
	dfs();
	cout << cnt << endl;
	return 0;
}