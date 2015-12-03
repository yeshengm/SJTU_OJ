#include "iostream"
#include "fstream"
#include "cstring"
#include "queue"
using namespace std;
//ifstream cin("1530.in");

int t, n;
char order[10], code[10];
char str[1100000];

int power(int i) {
	int res = 1;
	while (i--)
		res <<= 1;
	return res;
}

struct tree {
	int beg;
	int end;
	tree(int b, int e) {
		beg = b;
		end = e;
	}
};

void HieToPre(int p) {
	if (p > n) return;
	cout << str[p];
	if (2 * p <= n) HieToPre(2 * p);
	if (2 * p <= n) HieToPre(2 * p + 1);
}

void HieToIn(int p) {
	if (p > n) return;
	if (2 * p <= n) HieToIn(2 * p);
	cout << str[p];
	if (2 * p <= n) HieToIn(2 * p + 1);
}

void HieToPost(int p) {
	if (p > n) return;
	if (2 * p <= n) HieToPost(2 * p);
	if (2 * p <= n) HieToPost(2 * p + 1);
	cout << str[p];
}

int getMidPre(int s, int t) {
	int size = t - s;
	int i = 0;
	while (1) {
		if (2 * (power(i) - 1) <= size && size < 2 * (power(i + 1) - 1))
			break;
		else ++i;
	}
	int left = size - 2 * (power(i) - 1);
	left = (left > power(i)) ? power(i) : left;
	return s + power(i) - 1 + left + 1;
}

void PreToHie() {
	queue<tree *> preQ;
	preQ.push(new tree(1, n));
	while (!preQ.empty()) {
		if (preQ.front()->beg == preQ.front()->end) {
			cout << str[preQ.front()->beg];
			delete preQ.front();
			preQ.pop();
		} else if (preQ.front()->beg > preQ.front()->end) {
			delete preQ.front();
			preQ.pop();
		} else {
			int mid = getMidPre(preQ.front()->beg, preQ.front()->end);
			preQ.push(new tree(preQ.front()->beg + 1, mid - 1));
			preQ.push(new tree(mid, preQ.front()->end));
			cout << str[preQ.front()->beg];
			delete preQ.front();
			preQ.pop();
		}
	}
}

int getMidIn(int s, int t) {
	int size = t - s;
	int i = 0;
	while (1) {
		if (2 * (power(i) - 1) <= size && size < 2 * (power(i + 1) - 1))
			break;
		else ++i;
	}
	int left = size - 2 * (power(i) - 1);
	left = (left > power(i)) ? power(i) : left;
	return s + power(i) - 1 + left;
}

void InToHie() {
	queue<tree *> inQ;
	inQ.push(new tree(1, n));
	while (!inQ.empty()) {
		if (inQ.front()->beg == inQ.front()->end) {
			cout << str[inQ.front()->end];
			delete inQ.front();
			inQ.pop();
		} else if (inQ.front()->beg > inQ.front()->end) {
			delete inQ.front();
			inQ.pop();
		} else {
			int mid = getMidIn(inQ.front()->beg, inQ.front()->end);
			inQ.push(new tree(inQ.front()->beg, mid - 1));
			inQ.push(new tree(mid + 1, inQ.front()->end));
			cout << str[mid];
			delete inQ.front();
			inQ.pop();
		}
	}
}

int getMidPost(int s, int t) {
	int size = t - s;
	int i = 0;
	while (1) {
		if (2 * (power(i) - 1) <= size && size < 2 * (power(i + 1) - 1))
			break;
		else ++i;
	}
	int left = size - 2 * (power(i) - 1);
	left = (left > power(i)) ? power(i) : left;
	return s + power(i) - 1 + left;
}

void PostToHie() {
	queue<tree *> postQ;
	postQ.push(new tree(1, n));
	while (!postQ.empty()) {
		if (postQ.front()->beg == postQ.front()->end) {
			cout << str[postQ.front()->end];
			delete postQ.front();
			postQ.pop();
		} else if (postQ.front()->beg > postQ.front()->end) {
			delete postQ.front();
			postQ.pop();
		} else {
			int mid = getMidPost(postQ.front()->beg, postQ.front()->end);
			postQ.push(new tree(postQ.front()->beg, mid - 1));
			postQ.push(new tree(mid, postQ.front()->end - 1));
			cout << str[postQ.front()->end];
			delete postQ.front();
			postQ.pop();
		}
	}
}

int main() {
	cout << sizeof(queue<tree *>);
	std::ios::sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> order >> code >> str + 1;
		if (code[0] == 'E') {
			if (order[1] == 'N') HieToIn(1);
			else if (order[1] == 'R') HieToPre(1);
			else if (order[1] == 'O') HieToPost(1);
		} else if (code[0] == 'D') {
			if (order[1] == 'N') InToHie();
			else if (order[1] == 'R') PreToHie();
			else if (order[1] == 'O') PostToHie();
		}
		cout << endl;
	}
	return 0;
}