#include <iostream>
#include <fstream>
using namespace std;

int N, l[100005], r[100005], v[100005], root;
bool mark[100005];
int q[300005], op = 0, cl = -1;
void enQ(int x) {
	q[++cl] = x;
}
void deQ() {
	++op;
}
void init() {
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> l[i] >> r[i] >> v[i];
		mark[l[i]] = mark[r[i]] = true;
	}
	for (int i = 1; i <= N; ++i) {
		if (!mark[i]) {
			root = i;
			break;
		}
	}
}
void preTra(int rt) {
	if (rt == 0) return;
	cout << v[rt] << ' ';
	rt = l[rt];
	while (rt != 0) {
		preTra(rt);
		rt = r[rt];
	}
}
void postTra(int rt) {
	if (rt == 0) return;
	int val = v[rt];
	rt = l[rt];
	while (rt != 0) {
		postTra(rt);
		rt = r[rt];
	}
	cout << val << ' ';
}
void levTra() {
	enQ(root);
	while (cl >= op) {
		int tmp = q[op];
		cout << v[q[op]] << ' ';
		for (int i = l[tmp]; i != 0; i = r[i]) {
			enQ(i);
		}
		
		deQ();
	}
}
int main()
{
	init();
	preTra(root); cout << endl;
	postTra(root); cout << endl;
	levTra(); cout << endl;
	return 0;
}