#include <iostream>
using namespace std;

int N, M, a[3000], tmp;

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> tmp;
        bool flag = false;
        for (int j = 0; j < N; ++j)
            if (a[j] == tmp) { flag = true; break; }
        if (flag) cout << 'Y' << endl;
        else cout << 'N' << endl;
    }
    return 0;
}