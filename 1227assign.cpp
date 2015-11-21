#include <iostream>
using namespace std;

int N;
int a[1000000];

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void qsort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vm = a[(s + t) >> 1];
	while (i <= j) {
		while (a[i] < vm) ++i;
		while (a[j] > vm) --j;
		if (i <= j) swap(a[i++], a[j--]);
	}
	qsort(s, j);
	qsort(i, t);
}

int main() 
{
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> a[i];
	qsort(0, N - 1);
	for (int i = 0; i < N - 1; ++i) cout << a[i] << ' ';
	cout << a[N - 1];
	return 0;
}