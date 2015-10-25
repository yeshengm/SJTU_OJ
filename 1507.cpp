#include "iostream"
#include "algorithm"
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int convSum(int a, int b)
{
	return (a > b) ? a - b : b - a;
}

int main()
{
	int N, sum = 0;
	int a[1000000], b[1000000];
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	for (int i = 0; i < N; ++i)
		cin >> b[i];
	sort(a, a + N);
	sort(b, b + N, cmp);
	for (int i = 0; i < N; ++i) {
		sum += convSum(a[i], b[i]);
	}
	cout << sum << endl;
	return 0
}