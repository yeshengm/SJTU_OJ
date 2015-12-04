#include <iostream>
using namespace std;

int k, N;
int a[200005];

long long findMax(int p)
{
    int max = a[p];
    for (int i = p; i < p + k; ++i)
        max = (a[i] > max) ? a[i] : max;
    return max;
}

int main()
{
    cin >> k >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    prevMax = findMax(0);
    cout << prevMax << ' ';
    for (int i = 1; i < N - k + 1; ++i) {
        prevMax = findMax(i);
        cout << prevMax << ' ';
    }
    cout << endl;
    return 0;
}
