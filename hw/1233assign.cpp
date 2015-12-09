#include <iostream>
using namespace std;

struct vertice {
    int a = 0;
    int next = 0;
} v[105];

int n, m, start, M, cnt;
int adj[15];
bool mark[15];

void dfs(int len, int root) {
    mark[root] = true;
    if (len == M) { ++cnt; mark[root] = false; return; }
    for (int i = adj[root]; i != 0; i = v[i].next) {
        if (!mark[v[i].a]) {
            dfs(len + 1, v[i].a);
        }
    }
    mark[root] = false;
}

int main()
{
    cin >> n >> m >> start >> M;
    int s, t;
    for (int i = 1; i <= m; ++i) {
        cin >> s >> t;
        v[i].a = t; v[i].next = adj[s]; adj[s] = i;
    }
    dfs(0, start);
    cout << cnt << endl;
    return 0;
}
