#include <iostream>
using namespace std;

struct node {
	node *s = 0;
	node *f = 0;
	node *yb = 0;
	node *ob = 0;
	int val = 0;
};

node *tree[100000 + 5];
node *root;
int N, p, q, v;

node **queue = tree;
int head = 0, tail = -1;

void findroot();
void preTra(node *p);
void postTra(node *p);
void levTra();


int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		tree[i] = new node;
	for (int i = 1; i <= N; ++i) {
		cin >> p >> q >> v;
		if (p != 0) {
			tree[i]->s = tree[p];
			tree[p]->f = tree[i];
		}
		if (q != 0) {
			tree[i]->yb = tree[q];
			tree[q]->ob = tree[i];
		}
		tree[i]->val = v;
	}
	root = tree[1];
	findroot();
	preTra(root); cout << endl;
	postTra(root); cout << endl;
	levTra(); cout << endl;
	//while (1);
	return 0;
}

void findroot() {
	while (root->f != 0 || root->ob != 0 || root->yb != 0) {
		if (root->f != 0)
			root = root->f;
		else if (root->ob != 0)
			root = root->ob;
	}
}

void preTra(node *p) {
	cout << p->val << ' ';
	node *tmp0 = p;
	while (tmp0->yb != 0 && p == root)  {
		preTra(tmp0->yb);
		tmp0 = tmp0->yb;
	}
	if (p->s != 0) {
		preTra(p->s);
		node *tmp = p->s;
		while (tmp->yb != 0)  {
			preTra(tmp->yb);
			tmp = tmp->yb;
		}
	}
}

void postTra(node *p) {
	node *tmp0 = p;
	while (tmp0->yb != 0 && p == root)  {
		preTra(tmp0->yb);
		tmp0 = tmp0->yb;
	}
	if (p->s != 0) {
		postTra(p->s);
		node *tmp = p->s;
		while (tmp->yb != 0)  {
			postTra(tmp->yb);
			tmp = tmp->yb;
		}
	}
	cout << p->val << ' ';
}

void levTra() {
	queue[++tail] = root;
	node *tmp0 = root;
	while (tmp0->yb != 0) {
		tmp0 = tmp0->yb;
		queue[tail++] = tmp0;
	}
	while (tail - head + 1 != 0) {
		node *tmp = queue[head];
		cout << tmp->val << ' ';
		if (tmp->s != 0) {
			tmp = tmp->s;
			queue[++tail] = tmp;
			while (tmp->yb != 0) {
				tmp = tmp->yb;
				queue[++tail] = tmp;
			}
		}
		++head;
	}
}

/*
9
2 0 1
3 4 2
0 0 3
5 6 4
0 8 5
0 7 6
0 0 7
9 0 8
0 0 9
*/