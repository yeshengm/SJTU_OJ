#include <iostream>
using namespace std;

int N;
bool use[20];
int a[20];
int cnt;

bool inAngle(int xa, int ya, int xb, int yb) {
    for (int i = 1; i <= N; ++i) {
        if ((xa + i == xb && ya + i == yb)
            || (xa - i == xb && ya - i == yb)
            || (xa - i == xb && ya + i == yb)
            || (xa + i == xb && ya - i == yb))
            return true;
    }
    return false;
}

void dfs(int bit)
{
    if (bit == N) {
        bool valid = true;
        for (int i = 1; i < N; ++i)
            if (inAngle(i, a[i], N, a[N])) {
                valid = false; break;
            }
        if (valid) { cnt++; if (cnt <= 3) for (int i = 1; i <= N; ++i) cout << a[i]; }
       use[bit] = false; a[bit] = 0;
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (!use[i]) {
            bool valid = true;
            for (int j = 1; j < bit; ++j)
                if (inAngle(j, a[j], i, a[i]))
                    valid = false;
            if (!valid) continue;
            use[i] = true; a[bit] = i;
            dfs(bit + 1);
        }
    }
    use[bit] = false;
    a[bit] = 0;
}

int main()
{
    cin >> N;
    dfs(1);
    return 0;
}
