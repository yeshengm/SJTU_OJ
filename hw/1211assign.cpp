#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct node
{
	node *left;
	node *parent;
	node *right;
	node(node *lnode, node *rnode)
	{
		left = lnode;
		parent = 0;
		right = rnode;
	}
};

int N;
node *root;
node *nodeptr[1000000];
int il[1000000];
int ir[1000000];
void traverse(node *currnode = root)
{
	int state = 0;
	int cnt = 0;
	queue<node*> levelnode;
	levelnode.push(currnode);
	while (cnt < N) {
		if (state == 0 && levelnode.front()->left == 0 && levelnode.front()->right == 0)
			state = 1;
		if (levelnode.front()->parent != 0 || levelnode.front() == root)
			++cnt;
		if (cnt == N) break;
		if (state == 1 && cnt < N && levelnode.front()->parent == 0 && levelnode.front() != currnode) {
			cout << 'N' << endl;
			return;
		}

		if (levelnode.front()->left == 0)
			levelnode.front()->left = new node(0, 0);
		if (levelnode.front()->right == 0)
			levelnode.front()->right = new node(0, 0);
		
		levelnode.push(levelnode.front()->left);
		levelnode.push(levelnode.front()->right);
		levelnode.pop();
	}
	cout << 'Y' << endl;
}


int main()
{

	cin >> N;
	nodeptr[0] = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> il[i] >> ir[i];
		nodeptr[i] = new node(0, 0);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (il[i] != 0) { nodeptr[il[i]]->parent = nodeptr[i]; nodeptr[i]->left = nodeptr[il[i]]; }
		if (ir[i] != 0) { nodeptr[ir[i]]->parent = nodeptr[i]; nodeptr[i]->right = nodeptr[ir[i]]; }
	}
	root = nodeptr[1];
	while (root->parent != 0)
	{
		root = root->parent;
	}
	traverse(root);
	//while (1);
	return 0;
}
