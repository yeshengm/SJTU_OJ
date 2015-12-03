#include <iostream>
using namespace std;

int a[505], b[505], c[505], d[505];
int Hash[4000000 + 5];
int N, cnt;

int main() 
{
	cin >> N;
	for (int i = N - 1; i >= 0; --i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			Hash[2000000 + a[i] + b[j]]++;
		}
	}
	int tmp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			tmp = c[i] + d[j];
			cnt += Hash[-tmp + 2000000];
		}
	}
	cout << cnt << endl;
	return 0;
}