#include <iostream>
#include <fstream>
using namespace std;

int l[100005], r[100005], w[100005], q[300005], op = 0, cl = -1, N, root;
bool mark[100005];
void enQ(int x) {
	q[++cl] = x;
}
void deQ() {
	++op;
}
void init() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> l[i] >> r[i] >> w[i];
		mark[l[i]] = true;
		mark[r[i]] = true;
	}
	for (int i = 1; i <= N; ++i) {
		if (!mark[i]) {
			root = i;
			return;
		}
	}
}

int main()
{
	init();
	enQ(root);
	while (cl >= op) {
		int head = q[op];
		if (l[head] != 0) enQ(l[head]);
		if (r[head] != 0) enQ(r[head]);
		cout << w[head] << ' ';
		deQ();
	}
	return 0;
}