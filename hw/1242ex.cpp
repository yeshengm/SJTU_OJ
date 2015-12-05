#include "iostream"
using namespace std;

bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 1; (2*i+1)*(2*i+1) <= n; ++i)
		if (n % (2 * i + 1) == 0)
			return false;
	return true;
}

int main()
{
	int a, b, cnt = 0;
	cin >> a >> b;
	for (int i = a; i <= b; ++i)
		if (isPrime(i)) cnt++;
	cout << cnt << endl;
	return 0;
}