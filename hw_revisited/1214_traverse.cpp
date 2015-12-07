#include <iostream>
using namespace std;

int N, l[100005], r[100005], v[100005], root;
bool exist[100005];
int traQ[200005], head, tail = -1;

void enQ(int x) { traQ[++tail] = x; }
void deQ() { ++head; }
bool empty() { return tail - head + 1 == 0; }
void preOrder(int pos) {
    if (pos == 0) return;
    cout << v[pos] << ' ';
    pos = l[pos];
    while (pos != 0) {
        preOrder(pos);
        pos = r[pos];
    }
}
void postOrder(int pos) {
    if (pos == 0) return;
    int val = v[pos];
    pos = l[pos];
    while (pos != 0) {
        postOrder(pos);
        pos = r[pos];
    }
    cout << val << ' ';
}
void levelOrder() {
    enQ(root);
    while (!empty()) {
        int pos = traQ[head];
        cout << v[pos] << ' ';
        pos = l[pos];
        while (pos != 0) {
            enQ(pos); pos = r[pos];
        }
        deQ();
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> l[i] >> r[i] >> v[i];
        exist[l[i]] = exist[r[i]] = true;
    }
    for (int i = 1; i <= N; ++i) if (!exist[i]) { root = i; break; }
    preOrder(root); cout << endl;
    postOrder(root); cout << endl;
    levelOrder(); cout << endl;
    return 0;
}
