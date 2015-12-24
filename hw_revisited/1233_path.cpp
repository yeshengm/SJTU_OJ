#include <iostream>
#include <fstream>
using namespace std;
//ifstream fin("1.txt");

struct edge {
	int s, t;
	int next;
} e[105];

int N, M, start, Len, head[20], cnt;
bool mark[20];
void dfs(int s, int len) {
	if (len == Len) {
		++cnt;
		return;
	}
	int tmp = head[s];
	while (tmp != 0) {
		int dst = e[tmp].t;
		if (!mark[dst]) {
			mark[dst] = true;
			dfs(dst, len + 1);
			mark[dst] = false;
		}
		tmp = e[tmp].next;
	}
}

int main()
{
	cin >> N >> M >> start >> Len;
	for (int i = 1; i <= M; ++i) {
		int from, to;
		cin >> from >> to;
		e[i].s = from; e[i].t = to;
		e[i].next = head[from];
		head[from] = i;
	}
	mark[start] = true;
	dfs(start, 0);
	cout << cnt << endl;
	return 0;
}