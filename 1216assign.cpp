#include <iostream>
using namespace std;

int M;
int heap[20000];
int sz = 0;

void ins(int x) {
	heap[++sz] = x;
	int hole = sz;
	while (hole > 1 && heap[hole / 2] > x) {
		heap[hole] = heap[hole / 2];
		hole /= 2;
	}
	heap[hole] = x;
}

void dec(int i, int v) {
	int tmp = heap[i] - v;
	int hole = i;
	while (hole > 1 && heap[hole / 2] > tmp) {
		heap[hole] = heap[hole / 2];
		hole /= 2;
	}
	heap[hole] = tmp;
}

void find(int x) {
	int min = 200000000;
	int minindex = 1;
	int i = 1;
	for (; i <= sz; ++i) {
		if (heap[i] > x && heap[i] < min) {
			min = heap[i];
			minindex = i;
		}
		if (min == x - 1) break;
	}
	cout << minindex << endl;
}

int main() 
{
	cin >> M;
	char op[20];
	for (int i = 0; i < M; ++i) {
		cin >> op;
		int a1;
		cin >> a1;
		if (op[0] == 'i') ins(a1);
		else if (op[0] == 'f') find(a1);
		else if (op[0] == 'd') {
			int a2;
			cin >> a2;
			dec(a1, a2);
		}
	}
	return 0;
}