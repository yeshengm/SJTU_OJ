#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int p[20005];
vector<int> s[20005];
bool visit[20005];
int maxLen = -1;
int nextpos;

void bfs_1(int pos, int len) {
	visit[pos] = true;
	if (len > maxLen) {
		maxLen = len;
		nextpos = pos;
	}
	if (p[pos] != 0 && !visit[p[pos]]) bfs_1(p[pos], len + 1);
	for (size_t i = 0; i < s[pos].size(); ++i) {
		if (!visit[s[pos][i]]) bfs_1(s[pos][i], len + 1);
	}
}

void bfs_2(int pos, int len) {
	visit[pos] = true;
	maxLen = (len > maxLen) ? len : maxLen;
	if (p[pos] != 0 && !visit[p[pos]]) bfs_2(p[pos], len + 1);
	for (size_t i = 0; i < s[pos].size(); ++i) {
		if (!visit[s[pos][i]]) bfs_2(s[pos][i], len + 1);
	}
}


int main() 
{
	cin >> N >> M;
	int tmp;
	for (int i = 2; i <= N; ++i) {
		cin >> tmp;
		p[i] = tmp;
		s[tmp].push_back(i);
	}
	for (int i = 1; i <= M; ++i) {
		cin >> tmp;
		p[i + N] = tmp;
		s[tmp].push_back(i + N);
	}
	bfs_1(1, 0);
	memset(visit, 0, 20005);
	maxLen = -1;
	bfs_2(nextpos, 0);
	cout << maxLen;
	return 0;
}