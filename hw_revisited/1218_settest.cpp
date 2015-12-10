#include <iostream>
using namespace std;

int n, m, opn, a[50000], size;
bool mark[50000];
char op;

void setmark() {
    for (int i = 1; i <= 30000; ++i) mark[i] = false;
}
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void quickSort(int s, int t) {
    if (s >= t) return;
    int i = s, j = t, vmid = a[(s+t)>>1];
    while (i <= j) {
        while (a[i] < vmid) ++i;
        while (a[j] > vmid) --j;
        if (i <= j) swap(a[i++], a[j--]);
    }
    quickSort(s, j);
    quickSort(i, t);
}
void print() { for (int i = 1; i <= size; ++i) cout << a[i] << ' '; cout << endl; }
void Plus() {
    int num;
    for (int i = 0; i < opn; ++i) {
        cin >> num;
        bool isSame = false;
        for (int j = 1; j <= size; ++j) if (a[j] == num) { isSame = true; break; }
        if (!isSame) a[++size] = num;
    }
    quickSort(1, size);
    print();
}
void Minus() {
    int num;
    for (int i = 0; i < opn; ++i) {
        cin >> num;
        for (int j = 1; j <= size; ++j) {
            if (a[j] == num) mark[j] = true;
        }
    }
    int currSize = 0;
    for (int i = 1; i <= size; ++i) {
        if (!mark[i]) {
            a[++currSize] = a[i];
        }
    }
    size = currSize;
    quickSort(1, size);
    print();
}
void Multi() {
    int num;
    for (int i = 0; i < opn; ++i) {
        cin >> num;
        for (int j = 1; j <= size; ++j) {
            if (a[j] == num) mark[j] = true;
        }
    }
    int currSize = 0;
    for (int i = 1; i <= size; ++i) {
        if (mark[i]) a[++currSize] = a[i];
    }
    size = currSize;
    quickSort(1, size);
    print();
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> op >> opn;
        if (op == '+') Plus();
        else if (op == '-') { setmark(); Minus(); }
        else if (op == '*') { setmark(); Multi(); }
    }
    return 0;
}
