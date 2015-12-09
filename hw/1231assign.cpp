#include <iostream>
using namespace std;

int father[100005], N, X, Y;
int fatArr[100005], size = 0;

int main()
{
    cin >> N >> X >> Y;
    int p, q;
    for (int i = 1; i <= N; ++i) { cin >> p >> q; if (p != 0) father[p] = i; if (q != 0) father[q] = i; }
    while (X != 0) {
        fatArr[++size] = X;
        X = father[X];
    }
    while (Y != 0) {
        for (int i = 1; i <= size; ++i)
            if (fatArr[i] == Y) {
                cout << Y << endl; return 0;
            }
        Y = father[Y];
    }
    return 0;
}
