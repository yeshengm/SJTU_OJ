#include <iostream>
using namespace std;

int N, a[1000000];

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void quickSort(int s, int t) {
    if (s >= t) return;
    int i = s, j = t, midval = a[(s + t) >> 1];
    while (i <= j) {
        while (a[i] < midval) ++i;
        while (a[j] > midval) --j;
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
    for (int i = 0; i < N - 1; ++i) cout << a[i] << ' '; cout << a[N - 1] << endl;
    return 0;
}
