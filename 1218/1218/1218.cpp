#include <fstream>
#include <iostream>
using namespace std;

int sz;
int N;
int set[110];
void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}
void qsort(int s, int t, int arr[]) {
	if (s >= t) return;
	int i = s, j = t, mid = arr[(s + t) >> 1];
	while (i <= j) {
		while (arr[i] < mid) ++i;
		while (arr[j] > mid) --j;
		if (i <= j)
			swap(i++, j++, arr);
	}
	qsort(s, j, arr);
	qsort(i, t, arr);
}
int binSearch(int x, int s, int t, int arr[]) {
	if (s > t) return -1;
	int mid = (s + t) / 2;
	if (arr[mid] == x) return mid;
	if (arr[mid] < x) return binSearch(x, mid + 1, t, arr);
	if (arr[mid] > x) return binSearch(x, s, mid - 1, arr);
	return -1;
}

int main() 
{
	cin >> N;
	char op;
	int opn, tmp;
	for (int i = 0; i < N; ++i) {
		cin >> op;
		cin >> opn;
		if (op == '+') {
			for (int i = 0; i < opn; ++i) {
				cin >> tmp;
				if (binSearch(tmp, 0, sz - 1, set) == -1)
					set[sz++] = tmp;
			}
			qsort(0, sz - 1, set);
		}
	}
}