#include "iostream"
using namespace std;

double n;

int main()
{
	cin >> n;
	n -= 3500;
	double val = 0;
	if (n < 0) val = 0;
	if (n >= 0 && n < 1500) val = n * 3 / 100;
	if (n >= 1500 && n < 4500) val = 45 + (n-1500)/10;
	if (n >= 4500 && n < 9000) val = 345 + (n - 4500) / 5;
	if (n >= 9000 && n < 35000) val = 1245 + (n - 9000) / 4;
	if (n >= 35000 && n < 55000) val = 7745 + (n - 35000) * 3 / 10;
	if (n >= 55000 && n < 80000) val = 13745 + ( n - 55000) * 35 / 100;
	if (n >= 80000) val = 22495 + (n - 80000) * 45 / 100;
	cout << (int) val << endl;
	return 0;
}
