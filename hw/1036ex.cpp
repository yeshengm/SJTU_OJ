#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
ifstream fin("1.txt");

int N;
int a[100005];
long long q[3];
long long cnt = 0;
long long wait1, wait2;

long long maxV()
{
    if (q[0] >= q[1] && q[0] >= q[2]) return q[0];
    if (q[1] >= q[0] && q[1] >= q[2]) return q[1];
    if (q[2] >= q[0] && q[2] >= q[1]) return q[2];
}

long long minV()
{
    if (q[0] <= q[1] && q[0] <= q[2]) return q[0];
    if (q[1] <= q[0] && q[1] <= q[2]) return q[1];
    if (q[2] <= q[0] && q[2] <= q[1]) return q[2];
}

int getId()
{
    if (q[0] == 0) return 0;
    if (q[1] == 0) return 1;
    if (q[2] == 0) return 2;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {scanf("%d", &a[i]); wait1 += q[i % 3]; q[i % 3] += a[i];}
    printf("%lld %lld\n", wait1, maxV());
    q[0] = q[1] = q[2] = 0;
    int i = 0;
    while (i < N)
    {
        int tmpMin = minV();
        cnt += tmpMin;
        wait2 += tmpMin * (N - i);
        q[0] -= tmpMin; q[1] -= tmpMin; q[2] -= tmpMin;
        q[getId()] += a[i++];
    }
    cnt += maxV();
    printf("%lld %lld\n", wait2, cnt);
    return 0;
}
