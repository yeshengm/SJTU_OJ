#include <iostream>
#include <fstream>
using namespace std;
//ifstream cin("1.txt");
struct edge {
	int s, t;
	int next;
} e[100005];
int N, M, head[10005], cnt[10005], deg[10005];
int q[100005], op, cl = -1;
void enQ(int x) {
	q[++cl] = x;
}
void deQ() {
	++op;
}
void init() {
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int from, to;
		cin >> from >> to;
		e[i].s = from; e[i].t = to;
		e[i].next = head[from]; head[from] = i;
		++deg[to];
	}
	for (int i = 1; i <= N; ++i) {
		if (deg[i] == 0) {
			enQ(i);
			cnt[i] = 1;
		}
	}
}

void topSort() {
	while (cl >= op) {
		int from = q[op]; //qishi dian
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
	topSort();
	int maxT = 0;
	for (int i = 1; i <= N; ++i) {
		maxT = (cnt[i] > maxT) ? cnt[i] : maxT;
	}
	cout << maxT << endl;
	return 0;
}