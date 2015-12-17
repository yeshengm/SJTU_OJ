#include <iostream>
using namespace std;

int a[501], b[501], c[501], d[501], N, cnt;
int hashSum[6000001];
int hashFunct(int x) { return x + 3000000; }

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) { cin >> a[i] >> b[i] >> c[i] >> d[i]; }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            hashSum[hashFunct(a[i] + b[j])]++;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cnt += hashSum[hashFunct(-c[i] - d[j])];
    cout << cnt << endl;
    return 0;
}
