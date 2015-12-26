#include <iostream>
#include <fstream>
using namespace std;
const int INF = 200000000;
struct edge {
	int s, t, w;
	int next;
} e[105];
int N, M, q[1000], op, cl = -1, head[15], start, term, dist[15];
bool mark[15];

void enQ(int x) {
	if (mark[x]) return;
	mark[x] = true;
	q[++cl] = x;
}
void deQ() {
	mark[op] = false;
	op++;
}
bool empty() {
	return cl - op < 0;
}
void init() {
	cin >> N >> M >> start >> term;
	int from, to, weight;
	for (int i = 1; i <= M; ++i) {
		cin >> from >> to >> weight;
		e[i].s = from; e[i].t = to; e[i].w = weight;
		e[i].next = head[from]; head[from] = i;
	}
	for (int i = 1; i <= N; ++i)
		dist[i] = INF;
	dist[start] = 0;
}

int main()
{
	init();
	enQ(start);
	while (op <= cl) {
		int from = q[op];
		for (int i = head[from]; i != 0; i = e[i].next) {
			int to = e[i].t, val = e[i].w;
			if (dist[to] > dist[from] + val) {
				dist[to] = dist[from] + val;
				enQ(to);
			}
		}
		deQ();
		mark[from] = false;
	}
	cout << dist[term] << endl;
}