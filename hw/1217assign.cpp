#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("a.in");
int N, M;
int a[3000];

void qsort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, mid = a[(s + t) >> 1];
	while (i <= j) {
		while (a[i] < mid) ++i;
		while (a[j] > mid) --j;
		if (i <= j)
			swap(a[i++], a[j--]);
	}
	qsort(s, j);
	qsort(i, t);
}

void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

bool binSearch(int x, int s, int t) {
	if (s > t) return false;
	int mid = (s + t) / 2;
	if (a[mid] == x) return true;
	if (a[mid] > x) return binSearch(x, s, mid - 1);
	if (a[mid] < x) return binSearch(x, mid + 1, t);
	return false;
}

int main() 
{
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> a[i];
	qsort(0, N - 1);
	cin >> M;
	int tmp;
	for (int i = 0; i < M; ++i) {
		cin >> tmp;
		if (binSearch(tmp, 0, N - 1)) cout << 'Y' << endl;
		else cout << 'N' << endl;
	}
	return 0;
}