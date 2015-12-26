#include <iostream>
#include <fstream>
using namespace std;
char a[1000005], b[1000005];
int ia[1000005], sza, ib[1000005], szb, res[1000005];
#define max(x, y) ((x > y) ? x : y)
int strlen(char s[]) {
	int i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}

int main()
{
	cin >> a >> b;
	sza = strlen(a); szb = strlen(b);
	for (int i = 0; i < sza; ++i) {
		ia[i] = a[sza - 1 - i] - '0';
	}
	for (int i = 0; i < szb; ++i) {
		ib[i] = b[szb - 1 - i] - '0';
	}
	int maxsz = max(sza, szb);
	for (int i = 0; i <= maxsz; ++i) {
		res[i] = (ia[i] + ib[i]) % 10;
		ia[i + 1] += (ia[i] + ib[i]) / 10;
	}
	int pos = maxsz + 1;
	for (; pos >= 0; --pos) {
		if (res[pos] != 0)
			break;
	}
	for (int i = pos; i >= 0; --i) {
		cout << res[i];
	}
	return 0;
}