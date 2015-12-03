#include <iostream>
#include <queue>
using namespace std;

struct node
{
	node *left;
	node *parent;
	node *right;
	int value;

	node()
	{
		left = right = parent = 0;
		value = -1;
	}
};

int N, M;

int al[100000 + 10];
int ar[100000 + 10];
int av[100000 + 10];
int bl[100000 + 10];
int br[100000 + 10];
int bv[100000 + 10];

node *ta[100000 + 10];
node *tb[100000 + 10];

node *rta;
node *rtb;

node *findroot(node *p)
{
	while (p->parent != 0)
		p = p->parent;
	return p;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> al[i] >> ar[i] >> av[i];
		ta[i] = new node;
	}
	cin >> M;
	for (int i = 1; i <= M; ++i) {
		cin >> bl[i] >> br[i] >> bv[i];
		tb[i] = new node;
	}
	//special case
	if (N != M) {
		cout << 'N' << endl;
		return 0;
	}

	for (int i = 1; i <= N; ++i) {
		if (al[i] != 0)	{
			ta[i]->left = ta[al[i]];
			ta[al[i]]->parent = ta[i];
		}
		if (ar[i] != 0) {
			ta[i]->right = ta[ar[i]];
			ta[ar[i]]->parent = ta[i];
		}
		ta[i]->value = av[i];
	}
	//link, non-empty node's parent and l, r are linked
	for (int i = 1; i <= N; ++i) {
		if (bl[i] != 0)	{
			tb[i]->left = tb[bl[i]];
			tb[bl[i]]->parent = tb[i];
		}
		if (br[i] != 0) {
			tb[i]->right = tb[br[i]];
			tb[br[i]]->parent = tb[i];
		}
		tb[i]->value = bv[i];
	}

	rta = findroot(ta[1]);
	rtb = findroot(tb[1]);
	queue<node *> lva;
	queue<node *> lvb;
	lva.push(rta);
	lvb.push(rtb);
	int cnt = 0; //nodes that has been processed

	while (cnt < N) {
		if (lva.front()->value != lvb.front()->value) {
			cout << 'N' << endl;
			return 0;
		}
		if (lva.front()->value != -1)
			++cnt;
		//push and pop a
		if (lva.front()->left != 0)
			lva.push(lva.front()->left);
		else
			lva.front()->left = new node;
		if (lva.front()->right != 0)
			lva.push(lva.front()->right);
		else
			lva.front()->right = new node;
		lva.pop();
		//push and pop a
		if (lvb.front()->left != 0)
			lvb.push(lvb.front()->left);
		else
			lvb.front()->left = new node;
		if (lvb.front()->right != 0)
			lvb.push(lvb.front()->right);
		else
			lvb.front()->right = new node;
		lvb.pop();
	}
	cout << 'Y' << endl;
	//while (1);
	return 0;
	}