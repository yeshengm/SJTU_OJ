#include <iostream>
#include <fstream>
using namespace std;

struct edge {
	int s, t;
	int next;
} e[100005];
int N, M, head[10005], cnt[10005], start, deg[10005], q[10005], op, cl = -1;
void init() {
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int from, to;
		cin >> from >> to;
		e[i].s = from; e[i].t = to;
		e[i].next = head[from]; head[from] = i;
		++deg[to];
	}
}
void enQ(int x) {
	q[++cl] = x;
}
void deQ() {
	++op;
}
bool empty() {
	return cl < op;
}
void topSort() {
	enQ(start);
	while (!empty()) {
		int from = q[op];
		for (int i = head[from]; i != 0; i = e[i].next) {
			int to = e[i].t;
			--deg[to];
			if (deg[to] == 0) {
				cnt[to] = cnt[from] + 1;
				enQ(to);
			}
		}
		deQ();
	}
}
int main()
{
	init();
	for (int i = 1; i <= N; ++i) {
		if (deg[i] == 0) {
			enQ(i);
			cnt[i] = 1;
		}
	}
	topSort();
	int maxT = 0;
	for (int i = 1; i <= N; ++i)
		maxT = (cnt[i] > maxT) ? cnt[i] : maxT;
	cout << maxT << endl;
	return 0;
}