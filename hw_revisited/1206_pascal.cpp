#include <iostream>
using namespace std;

int b, i, it;
char a[100];

int main()
{
    while (cin >> a)
    {
        if (a[0] == 'b' && a[1] == 'e' && a[2] == 'g' && a[3] == 'i' && a[4] == 'n' && a[5] == '\0')
            ++b;
        else if (a[0] == 'e' && a[1] == 'n' && a[2] == 'd' && a[3] == '\0')
            --b;
        else if (a[0] == 'i' && a[1] == 'f' && a[2] == '\0')
            ++i;
        else if (a[0] == 't' && a[1] == 'h' && a[2] == 'e' && a[3] == 'n' && a[4] == '\0')
            { --i; ++it; }
        else if (a[0] == 'e' && a[1] == 'l' && a[2] == 's' && a[3] == 'e' && a[4] == '\0')
            --it;
        if (b < 0 || i < 0 || it < 0) { cout << "Error!" << endl; return 0; }
    }
    if (b != 0 || i != 0) { cout << "Error!" << endl; return 0; }
    cout << "Match!" << endl;
    return 0;
}
