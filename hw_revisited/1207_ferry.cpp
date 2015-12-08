#include <iostream>
#include <cstdio>
using namespace std;

int N, headKc = 1, tailKc = 0, headHc = 1, tailHc = 0, currTime = 0, Nkc, Nhc, Tkc, Thc;
int Qkc[100005], Qhc[100005];

void enQkc(int x) { Qkc[++tailKc] = x; }
bool emptyKc() { return tailKc - headKc + 1 == 0; }
void enQhc(int x) { Qhc[++tailHc] = x; }
bool emptyHc() { return tailHc - headHc + 1 == 0; }
bool existHc() { return !emptyHc() && Qhc[headHc] <= currTime; }
bool existKc() { return !emptyKc() && Qkc[headKc] <= currTime; }

int main()
{
    cin >> N;
    int p, q;
    for (int i = 0; i < N; ++i) {
        cin >> p >> q;
        (p == 0) ? enQkc(q) : enQhc(q);
    }
    Nkc = tailKc; Nhc = tailHc;
    while (!(emptyHc() && emptyKc())) {
        int cntKc = 0, load = 0;
        while (load < 10) {
            if (existHc() && existKc()) {
                if (cntKc < 4) { Tkc += currTime - Qkc[headKc++]; ++load; ++cntKc; }
                else if (cntKc == 4) { Thc += currTime - Qhc[headHc++]; ++load; cntKc = 0; }
            }
            else if (!existKc() && existHc()) { Thc += currTime - Qhc[headHc++]; ++load; cntKc = 0;}
            else if (!existHc() && existKc()) { Tkc += currTime - Qkc[headKc++]; ++load; }
            else if (!existHc() && !existKc()) break;
        }
        currTime += 10;
    }
    printf("%.3lf %.3lf\n", (double) Tkc / Nkc, (double) Thc / Nhc);
    return 0;
}
