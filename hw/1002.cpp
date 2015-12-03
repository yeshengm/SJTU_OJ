#include <iostream>
using namespace std;

int main()
{
	int a[1001][1001], b[1001][1001], c[1001][1001], l, w, i, j, x, y, sum, result = 0;
	cin >> l >> w;
	for (i = 1; i <= l; i++)
		for (j = 1; j <= w; j++)
			cin >> a[i][j];
	cin >> x >> y;

	/*	for (i = 1; i <= l; i++)
	{
	b[i][1] = 0;
	for (j = 1; j <= y; j++) b[i][1] += a[i][j];
	for (j = 2; j <= w - y + 1; j++) b[i][j] = b[i][j - 1] - a[i][j - 1] + a[i][j + y - 1];
	}
	*/	for (j = 1; j <= w; j++)
	{
		c[1][j] = 0;
		for (i = 1; i <= x; i++) c[1][j] += a[i][j];
		for (i = 2; i <= l - x + 1; i++) c[i][j] = c[i - 1][j] - a[i - 1][j] + a[i + x - 1][j];
	}

	for (i = 1; i <= l - x + 1; i++)
	{
		sum = 0;
		for (j = 1; j <= y; j++) sum += c[i][j];
		if (sum > result) result = sum;
		for (j = 2; j <= w - y + 1; j++)
		{
			sum = sum - c[i][j - 1] + c[i][j + y - 1];
			if (sum > result) result = sum;
		}
	}

	cout << result << endl;

	system("pause");

	return 0;
}