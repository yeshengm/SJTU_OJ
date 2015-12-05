#include <iostream>
using namespace std;

int N;
int pos[30005];
int l[100005], r[100005];

void traverse(int root)
{
    if (root == 0) return;
    traverse(l[root]);
    traverse(r[root]);
    cout << root << ' ';
}

int main()
{
    cin >> N;
    pos[1] = 1;
    int a, b, c;
    for (int i = 1; i <= N; ++i) {
        cin >> a >> b >> c;
        if (b != -1) {pos[b] = 2 * pos[a]; l[a] = b;}
        if (c != -1) {pos[c] = 2 * pos[a] + 1; r[a] = c;}
    }
    for (int i = 1; i <= N; ++i) cout << pos[i] << ' ';
    cout << endl;
    traverse(1);
    cout << endl;
    return 0;
}
