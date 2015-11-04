#include <iostream>
#include <fstream>
using namespace std;
//ifstream cin("a.in");
int sz = 0, N;


void swap(int s, int t, int arr[]) {
	int tmp = arr[s];
	arr[s] = arr[t];
	arr[t] = tmp;
}
void qsort(int s, int t, int arr[]) {
	if (s >= t) return;
	int i = s, j = t, mid = arr[(s + t) >> 1];
	while (i <= j) {
		while (arr[i] < mid) ++i;
		while (arr[j] > mid) --j;
		if (i <= j) {
			swap(i, j, arr);
			++i; --j;
		}
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
void print(int set[]) {
	for (int i = 0; i < sz; ++i)
		cout << set[i] << ' ';
	cout << endl;
}
int find(int x, int arr[]) {
	for (int i = 0; i < sz; ++i)
		if (x == arr[i])
			return -1;
	return 1;
}

int main() 
{
	int set[10000];
	int mark[10000];
	int trans[10000];
	for (int i = 0; i < 10000; ++i) {
		set[i] = mark[i] = trans[i] = 0;
	}
	cin >> N;
	char op;
	int opn, tmp;
	for (int i = 0; i < N; ++i) {
		cin >> op;
		cin >> opn;
		if (op == '+') { //bing
			for (int i = 0; i < opn; ++i) {
				cin >> tmp;
				if (find(tmp, set) == 1)
					set[sz++] = tmp;
			}
			qsort(0, sz - 1, set);
		} else if (op == '-') { //cha
			for (int i = 0; i < opn; ++i) {
				cin >> tmp;
				int mk = binSearch(tmp, 0, sz - 1, set);
				if (mk != -1) {
					mark[mk] = 1;
				}
			}
			int tpos = 0, fsz = sz;
			for (int i = 0; i < fsz; ++i) {
				if (mark[i] == 1) { sz--; continue; }
				else trans[tpos++] = set[i];
			}
			for (int i = 0; i < sz; ++i) set[i] = trans[i];
			for (int i = 0; i < fsz; ++i) mark[i] = 0;
		} else if (op == '*') {//jiao
			for (int i = 0; i < opn; ++i) {
				cin >> tmp;
				int mk = binSearch(tmp, 0, sz - 1, set);
				if (mk != -1) {
					mark[mk] = 1;
				}
			}
			int tpos = 0, fsz = sz;
			for (int i = 0; i < fsz; ++i) {
				if (mark[i] == 0) { sz--; continue; } 
				else if (mark[i] == 1) trans[tpos++] = set[i];
			}
			for (int i = 0; i < sz; ++i) set[i] = trans[i];
			for (int i = 0; i < fsz; ++i) mark[i] = 0;
		}
		print(set);
	}
	return 0;
}