#include <iostream>
using namespace std;

int PQ[20005], size, N, opn;
char op[10];

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }
void swim(int pos) {
    while (pos/2 >= 1 && PQ[pos] < PQ[pos/2]) {
        swap(PQ[pos], PQ[pos/2]);
        pos /= 2;
    }
}
void ins(int x) { PQ[++size] = x; swim(size); }
void sink(int pos) {
    while (pos*2 <= size) {
        int child = 2*pos;
        if (child+1 <= size && PQ[child] > PQ[child + 1]) child++;
        if (PQ[pos] > PQ[child]) swap(PQ[pos], PQ[child]);
        pos = child;
    }
}
void delTop() { PQ[1] = PQ[size--]; sink(1); }

int main()
{
    cin >> N;
    while (N--) {
        cin >> op;
        if (op[0] == 'i') { cin >> opn; ins(opn); }
        else if (op[0] == 'd') delTop();
        else if (op[0] == 'm') cout << PQ[1] << endl;
    }
    return 0;
}
