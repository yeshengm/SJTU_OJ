#include <iostream>
using namespace std;

int a[100000], N;

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

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    quickSort(0, N - 1);
    for (int i = 0; i < N; ++i) cout << a[i] << ' ';
    return 0;
}
