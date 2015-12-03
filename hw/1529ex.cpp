#include <iostream>
using namespace std;

int N, k;
int currNum[30];
int flag[4] = {0};
int cnt = 0;

bool isValid(int bit)
{
    if (bit == 0) return true;
    int tmp = currNum[bit];
    if (bit == 1 && tmp != 2) return false;
    if (tmp == 0 && flag[1] != 0) return false;
    if (tmp == 1 && flag[0] == 0) return false;
    if (tmp == 2 && flag[3] != 0) return false;
    if (tmp == 3 && flag[2] == 0) return false;
    if (bit == N && (flag[0] == 0 || flag[1] == 0 || flag[2] == 0 || flag[3] == 0)) return false;
    return true;
}

void print()
{
    for (int i = 1; i <= N; ++i)
        cout << currNum[i];
    cout << endl;
}

void getNum(int bit)
{
    if (cnt == k) return;
    bool valid = isValid(bit);
    if (!valid)
        return;
    else if (valid && bit != N)
    {
        currNum[bit + 1] = 0; ++flag[0]; getNum(bit + 1); --flag[0];
        currNum[bit + 1] = 1; ++flag[1]; getNum(bit + 1); --flag[1];
        currNum[bit + 1] = 2; ++flag[2]; getNum(bit + 1); --flag[2];
        currNum[bit + 1] = 3; ++flag[3]; getNum(bit + 1); --flag[3];
    }
    else if (valid && bit == N) {
        ++cnt;
       if (cnt == k)
            print();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> N >> k;
    getNum(0);
	system("pause");
    return 0;
}
