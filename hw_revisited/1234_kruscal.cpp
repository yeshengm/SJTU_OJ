#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("1.txt");

struct edge {
	int s, t, w;
} e[100001];

int cnt, UF[10005], N, M;

void init() {
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int from, to, weight;
		cin >> from >> to >> weight;
		e[i].s = from; e[i].t = to;
		e[i].w = weight;
	}
	for (int i = 0; i <= N; ++i)
		UF[i] = -1;
}
void swap(edge &a, edge &b) {
	edge tmp = a;
	a = b;
	b = tmp;
}
void edgeSort(int s, int t) {
	if (s >= t) return;
	int i = s, j = t, vmid = e[(i + j) >> 1].w;
	while (i <= j) {
		while (e[i].w < vmid) ++i;
		while (e[j].w > vmid) --j;
		if (i <= j) swap(e[i++], e[j--]);
	}
	edgeSort(s, j);
	edgeSort(i, t);
}
int UFfind(int x) {
	if (UF[x] < 0) return x;
	else return UF[x] = UFfind(UF[x]);
}
void UFunion(int x, int y) {
	x = UFfind(x); y = UFfind(y);
	if (x == y) return;
	else if (UF[x] < UF[y]) { UF[x] += UF[y]; UF[y] = x; }
	else { UF[y] += UF[x]; UF[x] = y; }
}

int main()
{
	init();
	edgeSort(1, M);
	for (int i = 1; i <= M; ++i) {
		int from = e[i].s, to = e[i].t;
		if (UFfind(from) != UFfind(to)) {
			UFunion(from, to);
			cnt += e[i].w;
		}
	}
	cout << cnt << endl;
	return 0;
}