#include <iostream>
#include <fstream>
using std::endl;
using std::cout;
using std::cin;
using std::ifstream;
ifstream fin("1.txt");

int const INFI = 200000000;

struct edge {
	int s, t, w;
	int next;
} e[105];
int n, m, start, end, head[15], dist[15];
int q[105], op, cl = -1;
void enQ(int x) {
	q[++cl] = x;
}
void deQ() { ++op; }
bool empty() { return cl < op; }
void init() {
	for (int i = 1; i <= n; ++i) {
		dist[i] = INFI;
	}
	dist[start] = 0;
}

int main()
{
	cin >> n >> m >> start >> end;
	int from, to, weight;
	for (int i = 1; i <= m; ++i) {
		cin >> from >> to >> weight;
		e[i].s = from; e[i].t = to; e[i].w = weight;
		e[i].next = head[from];
		head[from] = i;
	}
	init();
	enQ(start);
	while (!empty()) {
		int from = q[op];
		for (int i = head[from]; i != 0; i = e[i].next) {
			int to = e[i].t;
			if (dist[from] + e[i].w < dist[to]) {
				dist[to] = dist[from] + e[i].w;
				enQ(to);
			}
		}
		deQ();
	}
	cout << dist[end] << endl;
	return 0;
}