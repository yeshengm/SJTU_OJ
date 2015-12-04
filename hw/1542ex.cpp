#include <iostream>
#include <fstream>
using namespace std;

int N, a[300005], aux[300005];
long long cnt;

void merge(int s, int  mid, int t)
{
    int i = s, j = mid + 1, p = s;
    while (i <= mid || j <= t) {
        if (i > mid) aux[p++] = a[j++];
        else if (j > t) aux[p++] = a[i++];
        else if (a[i] <= a[j]) aux[p++] = a[i++];
        else if (a[i] > a[j]) { aux[p++] = a[j++]; cnt += mid - i + 1; }
    }
    for (int i = s; i <= t; ++i) a[i] = aux[i];
}

void mergeSort(int s, int t)
{
    if (s >= t) return;
    int mid = (s + t) / 2;
    mergeSort(s, mid);
    mergeSort(mid + 1, t);
    merge(s, mid, t);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    mergeSort(0, N - 1);
    cout << cnt << endl;
    return 0;
}
