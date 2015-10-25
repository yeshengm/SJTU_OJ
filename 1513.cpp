#include "iostream"
using namespace std;

unsigned long a[60][60];

int main()
{
	a[1][1] =  a[2][1] = a[2][2] = 1;
	for (int i = 3; i <= 55; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (j == 1 || j == i) a[i][j] = 1;
			else a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
		}
	}
	int n, m;
	cin >> n >> m;
	cout << a[n][m] << endl;
	//while (1) ;
	return 0;
}