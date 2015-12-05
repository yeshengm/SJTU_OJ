#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

char a[35];
int size = 0;
int pos = 0;
char tra[35];

struct trieNode {
	int cnt = 0;
	trieNode *next[128];
	trieNode() {
		for (int i = 0; i < 128; ++i)
			next[i] = NULL;
	}
};

trieNode *root = new trieNode();

void trieInsert(char a[]) {
	int i = 0;
	trieNode *currNode = root;
	while (a[i]) {
		int id = (int) a[i];
		if (currNode->next[id] == NULL)
			currNode->next[id] = new trieNode;
		currNode = currNode->next[id];
		++i;
	}
	currNode->cnt++;
}

void traverse(trieNode *p) {
	if (p == NULL) return;
	if (p->cnt != 0) {
		for (int i = 1; i <= pos; ++i) cout << tra[i];
		printf(" %.4lf \n", (double) p->cnt / (double) size * 100);
	}
	pos++;
	for (int i = 0; i < 128; ++i) {
		if (p->next[i] != NULL) {
			tra[pos] = (char) i;
			traverse(p->next[i]);
		}
	}
	pos--;
}

int main() 
{
	while (cin.getline(a, 35)) {
		trieInsert(a);
		size++;
	}
	traverse(root);
	return 0;
}