#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10005;
int a[N];

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	sort(a, a + N);
	for (int i = 0; i < N; ++i) {
		cout << a[i] << ' ';
	}
	return 0;
}

