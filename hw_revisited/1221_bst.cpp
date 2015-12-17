#include <iostream>
using namespace std;

int N, op1, op2, a[10000], size;
char op[30];

void ins(int x) {
    int i = size + 1;
    for (; i >= 2; --i)
        if (a[i - 1] > x) a[i] = a[i - 1];
        else break;
    a[i] = x;
    ++size;
}
void find(int x) {
    for (int i = 1; i <= size; ++i)
        if (a[i] == x) { cout << "Y" << endl; return; }
    cout << "N" << endl;
}
void findIth(int i) {
    if (i > size) { cout << "N" << endl; return; }
    else cout << a[i] << endl;
}
void delInt(int lo, int hi) {
    int lopos, hipos, i;
    for (i = 1; i <= size; ++i)
        if (a[i] > lo) break;
    lopos = i;
    for (; i <= size; ++i)
        if (a[i] >= hi) break;
    hipos = i;
    for (i = hipos; i <= size; ++i)
        a[lopos++] = a[i];
    size = lopos - 1;
}
void delThis(int x) {
    int pos = 1;
    for (; pos <= size; ++pos)
        if (a[pos] == x) break;
    for (int i = pos; i <= size - 1; ++i)
        a[i] = a[i + 1];
    --size;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> op;
        if (op[0] == 'i') { cin >> op1; ins(op1); }
        else if (op[0] == 'f' && op[4] == '\0') { cin >> op1; find(op1); }
        else if (op[0] == 'f' && op[4] == '_') { cin >> op1; findIth(op1); }
        else if (op[0] == 'd' && op[6] == '\0') { cin >> op1; delThis(op1); }
        else if (op[0] == 'd' && op[7] == 'i') { cin >> op1 >> op2; delInt(op1, op2); }
        else if (op[0] == 'd' && op[7] == 'g') { cin >> op1; delInt(op1, 200000000); }
        else if (op[0] == 'd' && op[7] == 'l') { cin >> op1; delInt(-200000000, op1); }
     }
    return 0;
}
