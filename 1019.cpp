#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	int lb = 0;
	int N;
	cin >> N;
	getchar();
	for (int i = 0; i < N; ++i)
	{
		char tmp;
		while ((tmp = getchar()) != '\n') {
			if (tmp == '(')
				++lb;
			else if (tmp == ')') {
				if (lb == 0) {
					cout << "NO" << endl;
					lb = 0;
					break;
				}
				else --lb;
			}
		}
		if (lb == 0) {
			cout << "YES" << endl;
		}
		lb = 0;
	}
	//while (1);
	return 0;
}