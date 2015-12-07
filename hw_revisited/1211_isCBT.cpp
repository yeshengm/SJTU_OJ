#include <iostream>
using namespace std;

int N, l[100005], r[100005], root;
bool exist[100005], treeEnd = false;
int queue[300005], head = 0, tail = -1;

void enQ(int num) {
    queue[++tail] = num;
}
void deQ() {
    ++head;
}
bool empty() {
    return tail - head + 1 == 0;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> l[i] >> r[i];
        exist[l[i]] = (l[i] == 0) ? false : true;
        exist[r[i]] = (r[i] == 0) ? false : true;
    }
    for (int i = 1; i <= N; ++i)
        if (!exist[i]) { root = i; break; }
    enQ(root);
    while (N--) {
        if (queue[head] == 0) { cout << "N" << endl; return 0; }
        enQ(l[queue[head]]); enQ(r[queue[head]]); deQ();
    }
    cout << "Y" << endl;
    return 0;
}
