#include <iostream>
using namespace std;

int a[20005], size, N, op1, op2;
char op[10];

void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }
void swim(int pos) {
    while (pos/2 != 0 && a[pos/2] > a[pos]) {
        swap(a[pos], a[pos/2]);
        pos /= 2;
    }
}
void sink(int pos) {
    while (2*pos <= size) {
        int child = 2 * pos;
        if (child + 1 <= size && a[child+1] < a[child]) child++;
        if (a[pos] > a[child]) swap(a[pos], a[child]);
        pos = child;
    }
}
void ins(int x) { a[++size] = x; swim(size); }
void dec(int i, int v) { a[i] -= v; swim(i); }
int find(int x) {
    int min = 200000000, minpos;
    for (int i = 1; i <= size; ++i)
        if (a[i] > x && a[i] < min) { min = a[i]; minpos = i; }
    return minpos;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> op;
        if (op[0] == 'i') { cin >> op1; ins(op1); }
        else if (op[0] == 'd') { cin >> op1 >> op2; dec(op1, op2); }
        else if (op[0] == 'f') { cin >> op1; cout << find(op1) << endl; }
    }
    return 0;
}