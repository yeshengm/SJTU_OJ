#include <iostream>
#include <cmath>
using namespace std;

bool isValid(int num);

int main()
{
	int N;
	cin >> N;
	cout << N << '=';
	if (isValid(N)) 
		cout << N << '(' << '1' << ')' << endl;
	else {
		int cnt = 0;
		int divider = 3;
		int maxdiv = sqrt(N);
		while (N % 2 == 0) {
			N /= 2;
			cnt++;
		}
		if (cnt != 0)
			cout << '2' << '(' << cnt << ')';
		for (;N != 1; divider += 2) {
			if (isValid(N)) {
				cout << N << '(' << '1' << ')';
				break;
			}
			if (!isValid(divider)) continue;
			cnt = 0;
			while (N % divider == 0) {
				N /= divider;
				cnt++;
			}
			if (cnt != 0) cout << divider << '(' << cnt << ')';
		}
		cout << endl;
	}
	
	//while (1);
	return 0;
}

bool isValid(int num)
{
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	int maxDiv = sqrt(num);
	for (int i = 3; i <= maxDiv; i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}