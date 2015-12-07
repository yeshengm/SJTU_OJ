#include <iostream>
using namespace std;

int N, M, la[100005], ra[100005], va[100005], lb[100005], rb[100005], vb[100005], roota, rootb;
bool exista[100005], existb[100005];

bool isSame(int posa, int posb) {
    if (posa == 0 && posb != 0 || posa != 0 && posb == 0) return false;
    if (posa == 0 && posb == 0) return true;
    return isSame(la[posa], lb[posb]) && isSame(ra[posa], rb[posb]) && va[posa] == vb[posb];
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) { cin >> la[i] >> ra[i] >> va[i]; exista[la[i]] = exista[ra[i]] = true; }
    cin >> M;
    for (int i = 1; i <= M; ++i) { cin >> lb[i] >> rb[i] >> vb[i]; existb[lb[i]] = existb[rb[i]] = true; }
    if (N != M) { cout << "N" << endl; return 0; }
    for (int i = 1; i <= N; ++i) if (!exista[i]) roota = i;
    for (int i = 1; i <= M; ++i) if (!existb[i]) rootb = i;
    if (isSame(roota, rootb)) cout << "Y" << endl;
    else cout << "N" << endl;
    return 0;
}
