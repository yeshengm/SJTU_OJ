#include <iostream>
using namespace std;

long long acker(int m, int n) {
	if (m == 0) return n + 1;
	if (n == 0 && m > 0) return acker(m - 1, 1);
	if (n > 0 && m > 0) return acker(m - 1, acker(m, n - 1));
}

int main()
{
	long long m, n;
	cin >> m >> n;
	cout << acker(m, n) << endl;
	return 0;
}