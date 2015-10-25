#include <iostream>
using namespace std;

long long a, b, c, N;
long long calcNum(long long n1, long long n2, long long n3, long long n);

int main()
{
	cin >> a >> b >> c >> N;
	cout << calcNum(1, 0, 0, 1) << endl;
	return 0;
}

long long calcNum(long long n1, long long n2, long long n3, long long n)
{
	if (n == N) return a * n1 + b * n2 + c * n3 + n1 + n2 + n3;
	else return calcNum(n1*a + n2*b + n3*c, n1, n3 + n2, n+1);
}