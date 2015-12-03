#include "iostream"
using namespace std;

int coeff(int n)
{
	return (n % 2 == 0) ? 1 : -1;
}

int main()
{
	double sum = 0.0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		sum += coeff(n) * 4.0 / (2 * n - 1);
	}
	cout << sum << endl;
	//while (1) ;
	return 0;
}