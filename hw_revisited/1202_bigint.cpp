#include <iostream>
using namespace std;

int a[1000005], b[1000005], sum[100005];
int asz, bsz, sumsz;

int main()
{
    char ch;
    while ((ch = cin.get()) != '\n') a[asz++] = ch - '0';
    while ((ch = cin.get()) != '\n') b[bsz++] = ch -'0';
    while (asz > 0 || bsz > 0) {
        if (asz > 0 && bsz > 0) sum[sumsz] += a[--asz] + b[--bsz];
        else if (asz > 0 && bsz == 0) sum[sumsz] += a[--asz];
        else if (asz == 0 && bsz > 0) sum[sumsz] += b[--bsz];
        sum[sumsz + 1] += sum[sumsz] / 10;
        sum[sumsz++] %= 10;
    }
    if (sum[sumsz] != 0) cout << sum[sumsz];
    for (int i = sumsz - 1; i >= 0; --i) cout << sum[i];
    cout << endl;
    return 0;
}