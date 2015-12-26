#include <iostream>
#include <fstream>
using namespace std;
//ifstream cin("1.txt");
const int INF = 200000000;
struct edge {
	int s, t, w;
	int next;
} e[200005];
int N, M, start, term, head[10005], dist[10005], cnt[10005], former[100005];
bool mark[10005];
int q[100005], op, cl = -1;
void enQ(int x) {
	if (mark[x]) return;
	mark[x] = true;
	q[++cl] = x;
}
void deQ() {
	mark[q[op]] = false;
	++op;
}
void init() {
	cin >> N >> M >> start >> term;
	for (int i = 1; i <= M; ++i) {
		int from, to, weight;
		cin >> from >> to >> weight;
		e[i].s = from; e[i].t = to; e[i].w = weight;
		e[i].next = head[from]; head[from] = i;
	}
	for (int i = 1; i <= N; ++i) {
		dist[i] = INF;
	}
	dist[start] = 0;
}
void spfa() {
	enQ(start);
	while (cl >= op) {
		int from = q[op];
		for (int i = head[from]; i != 0; i = e[i].next) {
			int to = e[i].t; //jieshu dian
			if (dist[to] > dist[from] + e[i].w) {
				dist[to] = dist[from] + e[i].w;
				former[to] = from;
				cnt[to] = cnt[from] + 1;
				enQ(to);
			} else if (dist[to] == dist[from] + e[i].w && cnt[to] > cnt[from] + 1) {
				former[to] = from;
				cnt[to] = cnt[from] + 1;
			}
		}
		deQ();
	}
}
void printPath(int pos) {
	if (pos == start) { cout << start << ' '; return; }
	printPath(former[pos]);
	cout << pos << ' ';
}
int main()
{
	init();
	spfa();
	cout << dist[term] << endl;
	printPath(term);
	return 0;
}