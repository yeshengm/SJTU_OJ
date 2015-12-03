#include "iostream"
using namespace std;


int main()
{
	int M, T, U, F, D;
	int totalTime[100000];
	char tmp;
	cin >> M >> T >> U >> F >> D;
	for (int i = 0; i < T; ++i) {
		cin >> tmp;
		if (tmp == 'u' || tmp == 'd') totalTime[i] = U + D;
		if (tmp == 'f') totalTime[i] = 2 * F;
	}
	int Time = 0;
	int i = 0;
	for (; i < T && Time + totalTime[i] <= M; ++i) {
		Time += totalTime[i];
	}
	cout << i << endl;
	return 0;
}