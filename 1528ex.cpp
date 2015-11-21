#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

const int LARGE = 2147483648 - 1;

struct node {
	int pos;
	int val;
	node(int p, int v) {
		pos = p;
		val = v;
	}
};

int N, P;
node *parent[100005];
vector<node *> child[100005];
int t = 0;
int maxT;
bool flag = false;
bool visit[100005];

bool isOver(int currPos) {
	for (size_t i = 0; i < child[currPos].size(); ++i) {
		if (visit[child[currPos][i]->pos] == false)
			return false;
	}
	return true;
}

int getPos(int currPos) {
	int minLen = LARGE;
	int minPos;
	for (size_t i = 0; i < child[currPos].size(); ++i) {
		if (!visit[child[currPos][i]->pos] && child[currPos][i]->val < minLen) {
			minPos = child[currPos][i]->pos;
			minLen = child[currPos][i]->val;
		}
	}
	return minPos;
}

void dfs(int currPos) {
	visit[currPos] = true;
	if (currPos == P) { maxT = t; return; }
	while (!isOver(currPos)) {
		int nextPos = getPos(currPos);
		t += parent[nextPos]->val;
		dfs(nextPos);
		t += parent[nextPos]->val;
	}
}

int main() 
{
	cin >> N >> P;
	int s, t, l;
	memset(parent, -1, 100005);
	for (int i = 2; i <= N; ++i) {
		cin >> s >> t >> l;
		child[s].push_back(new node(t, l));
		parent[t] = new node(s, l);
	}
	dfs(0);
	cout << maxT << endl;
	return 0;
}