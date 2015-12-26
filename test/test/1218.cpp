#include <iostream>
using namespace std;

int N, opn, a[10005], sz;
bool mark[10005];
char op;
void reset() {
	for (int i = 0; i < sz; ++i) {
		mark[i] = false;
	}
}
void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }
void setSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = a[(s + t ) >> 1];
	while (i <= j) {
		while (a[i] < vmid) i++;
		while (a[j] > vmid) j--;
		if (i <= j) swap(a[i++], a[j--]);
	}
	setSort(s, j);
	setSort(i, t);
}
int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> op >> opn;
		if (op == '+') {
			reset();
			int currNum;
			for (int j = 1; j <= opn; ++j) {
				cin >> currNum;
				bool flag = false;
				for (int k = 0; k < sz; ++k) {
					if (a[k] == currNum) {
						flag = true;
						break;
					}
				}
				if (!flag) a[sz++] = currNum;
			}
		} else if (op == '-') {
			reset();
			int currNum;
			for (int j = 1; j <= opn; ++j) {
				cin >> currNum;
				for (int k = 0; k < sz; ++k) {
					if (a[k] == currNum) {
						mark[k] = true;
					}
				}
			}
			int newsz = 0;
			for (int j = 0; j < sz; ++j) {
				if (!mark[j]) {
					a[newsz++] = a[j];
				}
			}
			sz = newsz;
		} else if (op == '*') {
			reset();
			int currNum;
			for (int j = 1; j <= opn; ++j) {
				cin >> currNum;
				for (int k = 0; k < sz; ++k) {
					if (a[k] == currNum) {
						mark[k] = true;
					}
				}
			}
			int newsz = 0;
			for (int j = 0; j < sz; ++j) {
				if (mark[j]) {
					a[newsz++] = a[j];
				}
			}
			sz = newsz;
		}
		setSort(0, sz - 1);
		for (int j = 0; j < sz; ++j)
			cout << a[j] << ' ';
		cout << endl;
	}
	return 0;
}
/*
7
+ 3 1 2 3
- 1 2
+ 3 4 5 6
* 2 1 4
- 2 1 4
+ 1 100
- 1 99
*/