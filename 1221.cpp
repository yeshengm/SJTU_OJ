#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstddef>
using namespace std;
//ifstream cin("1221.in");

struct node { //左小于，右大于等于
	long long val;
	node *left = 0;
	node *right = 0;
	node(long long x, node *l = 0, node *r = 0) {
		val = x;
		left = l;
		right = r;
	}
};
long long cnt = 1;
bool found = false;
void insert(long long x, node *&rt) {
	if (rt == 0)
		rt = new node(x);
	else if ( x < rt->val) {
		insert(x, rt->left);
	} else if (x >= rt->val ) {
		insert(x, rt->right);
	}
}
void deleteNode(node *&rt) {
	if (rt->left != 0 && rt->right != 0) {
		node **tmp = &rt->right;
		while ((*tmp)->left != 0) {
			tmp = &(*tmp)->left;
		}
		rt->val = (*tmp)->val;
		*tmp = 0;
	} else {
		node *clearNode = rt;
		rt = (rt->left == 0) ? rt->right : rt->left;
		delete clearNode;
	}
}
void deleteEqual(long long x, node *&rt) {
	if (rt == 0) return;
	if (x == rt->val) deleteNode(rt);
	else if (x < rt->val) deleteEqual(x, rt->left);
	else if (x >= rt->val) deleteEqual(x, rt->right);
}
void deleteLess(long long x, node *&rt) {
	if (rt == 0) return;
	if (x <= rt->val) {
		deleteLess(x, rt->left);
	} else if (x > rt->val) {
		deleteLess(x, rt->left);
		deleteLess(x, rt->right);
		deleteNode(rt);
	}
}
void deleteGreater(long long x, node *&rt) {
	if (rt == 0) return;
	if (x >= rt->val) {
		deleteGreater(x, rt->right);
	} else if (x < rt->val) {
		deleteGreater(x, rt->left);
		deleteGreater(x, rt->right);
		deleteNode(rt);
	}
}
void deleteInterval(long long lo, long long hi, node *&rt) {
	if (rt == 0) return;
	if (hi < rt->val) deleteInterval(lo, hi, rt->left);
	else if (lo > rt->val) deleteInterval(lo, hi, rt->right);
	else {
		deleteInterval(lo, hi, rt->left);
		deleteInterval(lo, hi, rt->right);
		if (lo < rt->val && hi > rt->val) deleteNode(rt);
	}
}
void find(long long x, node *rt) {
	if (rt == 0) { 
		cout << "N\n"; 
	} else if (x == rt->val) {
		cout << "Y\n";
	} else if (x < rt->val) {
		find(x, rt->left);
	} else if (x >= rt->val) {
		find(x, rt->right);
	}
}
void findIth(long long i, node *rt) {
	if (cnt > i) return;
	if (rt == 0) return;
	findIth(i, rt->left);
	if (cnt == i) { 
		cout << rt->val << endl;
		found = true; 
		
	}
	++cnt;
	findIth(i, rt->right);
	
}

int main() 
{
	node *root = 0;
	char op[100];
	long long opnum, opnum2;
	long long N;
	cin >> N;
	for (long long i = 0; i < N; ++i) {
		cin >> op >> opnum;
		if (op[0] == 'i') { //insert
			insert(opnum, root);
		} else if (op[0] == 'd') {
			if (op[6] == '\0') { //delete
				deleteEqual(opnum, root);
			} else if (op[7] == 'l') { //delete_less_than
				deleteLess(opnum, root);
			} else if (op[7] == 'g') { //delete_greater_than
				deleteGreater(opnum, root);
			} else if (op[7] == 'i') { //delete_interval
				cin >> opnum2;
				deleteInterval(opnum, opnum2, root);
			}
		} else if (op[0] == 'f') {
			if (op[4] == '\0') { //find
				find(opnum, root);
			} else if (op[4] == '_') { //find_ith
				findIth(opnum, root);
				if (!found) cout << "N\n";
				found = false;
				cnt = 1;
			}
		}
	}
	return 0;
}