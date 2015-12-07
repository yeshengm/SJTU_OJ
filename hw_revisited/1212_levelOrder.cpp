#include <iostream>
using namespace std;

int N, l[100005], r[100005], val[100005], root;
bool exist[100005];
int levQ[300005], head = 0, tail = -1;

void enQ(int x) {
    levQ[++tail] = x;
}
void deQ() {
    head++;
}
bool empty() {
    return tail - head + 1 == 0;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> l[i] >> r[i] >> val[i];
        exist[l[i]] = exist[r[i]] = true;
    }
    for (int i = 1; i <= N; ++i)
        if (!exist[i]) root = i;
    enQ(root);
    while (!empty()) {
        cout << val[levQ[head]] << ' ';
        if (l[levQ[head]] != 0) enQ(l[levQ[head]]);
        if (r[levQ[head]] != 0) enQ(r[levQ[head]]);
        deQ();
    }
    cout << endl; return 0;
}
