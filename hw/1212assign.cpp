#include <iostream>
#include <queue>
using namespace std;

struct node
{
	node *left;
	node *right;
	node *parent;
	int value;
	node()
	{
		left = right = parent = 0;
		value = 0;
	}
};

int il[100000 + 5], ir[100000 + 5], data[100000 + 5];
node *nodeptr[100000 + 5];
node *root;
int N;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> il[i] >> ir[i] >> data[i];
	}
	for (int i = 1; i <= N; ++i) {
		nodeptr[i] = new node;
	}
	for (int i = 1; i <= N; ++i) {
		nodeptr[i]->value = data[i];
		if (il[i] != 0) { 
			nodeptr[i]->left = nodeptr[il[i]]; 
			nodeptr[il[i]]->parent = nodeptr[i];
		}
		if (ir[i] != 0)	{
			nodeptr[i]->right = nodeptr[ir[i]];
			nodeptr[ir[i]]->parent = nodeptr[i];
		}
	}
	root = nodeptr[1];
	while (root->parent != 0) {
		root = root->parent;
	}

	queue<node *> level;
	level.push(root);
	while (!level.empty()) {
		if (level.front()->left != 0)
			level.push(level.front()->left);
		if (level.front()->right != 0)
			level.push(level.front()->right);
		cout << level.front()->value << ' ';
		level.pop();
	}
	cout << endl;
	//while (1);
	return 0;
}