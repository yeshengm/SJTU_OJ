#include <iostream>
using namespace std;

int M;
int heap[20000];
int sz = 0;

void ins(int x) {
	int hole = ++sz;
	while (hole > 1 && x < heap[hole / 2]) {
		heap[hole] = heap[hole / 2];
		hole /= 2;
	}
	heap[hole] = x;
}

void del() {
	int top = heap[sz--];
	int hole = 1;
	while (hole * 2 <= sz) {
		int icmp = 2 * hole;
		if (icmp + 1 <= sz && heap[icmp] > heap[icmp + 1])
			icmp++;
		if (heap[icmp] < top) {
			heap[hole] = heap[icmp];
			hole = icmp;
		} else break;
	}
	heap[hole] = top;
}

void min() {
	cout << heap[1] << endl;
}

int main() 
{
	cin >> M;
	char op[10];
	for (int i = 0; i < M; ++i) {
		cin >> op;
		if (op[0] == 'd') del();
		else if (op[0] == 'm') min();
		else if (op[0] == 'i') {
			int tmp;
			cin >> tmp;
			ins(tmp);
		}
	}
	//while (1);
	return 0;
}