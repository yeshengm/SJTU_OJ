#include <iostream>
#include <fstream>
using namespace std;

int l[100005], r[100005], N, root, q[300005], op, cl = -1, cnt;
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
		cin >> l[i] >> r[i];
		mark[l[i]] = true;
		mark[r[i]] = true;
	}
	for (int i = 1; i <= N; ++i) {
		if (!mark[i]) {
			root = i;
			break;
		}
	}
}
bool isCBT() {
	enQ(root); cnt = 1;
	while (cnt <= N) {
		int head = q[op];
		if (head == 0) return false;
		enQ(l[head]);
		enQ(r[head]);
		++cnt;
		deQ();
	}
	return true;
}

int main()
{
	init();
	bool flag = isCBT();
	if (flag) cout << "Y" << endl;
	else cout << "N" << endl;
	return 0;
}