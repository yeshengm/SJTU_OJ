#include <iostream>
#include <fstream>
using namespace std;

struct edge {
	int s, t;
	int w;
} e[100005];
int n, m, sum;
void swap(edge &a, edge &b) {
	edge tmp = a;
	a = b;
	b = tmp;
}
void quickSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = e[(s + t) >> 1].w;
	while (i <= j) {
		while (e[i].w < vmid) ++i;
		while (e[j].w > vmid) --j;
		if (i <= j) swap(e[i++], e[j--]);
	}
	quickSort(s, j);
	quickSort(i, t);
}

int UF[10005];
int UFfind(int x) {
	if (UF[x] < 0) return x;
	return UF[x] = UFfind(UF[x]);
}
void UFUnion(int x, int y) {
	x = UFfind(x);
	y = UFfind(y);
	if (x == y) return;
	if (x < y) {
		UF[x] += UF[y]; UF[y] = x;
	} else if (y < x) {
		UF[y] += UF[x]; UF[x] = y;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		UF[i] = -1;
	for (int i = 1; i <= m; ++i) {
		cin >> e[i].s >> e[i].t >> e[i].w;
	}
	quickSort(1, m);
	for (int i = 1; i <= m; ++i) {
		int s = e[i].s;
		int t = e[i].t;
		if (UFfind(s) == UFfind(t)) continue;
		else {
			UFUnion(UFfind(s), UFfind(t));
			sum += e[i].w;
		}
	}
	cout << sum << endl;
	return 0;
}