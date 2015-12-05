#include <iostream>
using namespace std;

int L, A[100][100], B[100][100], cnt = 0;
void infect();
bool isValid(int n)
{
	if (n >= 0 && n < L) 
		return true;
	else return false;
}
void update()
{
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			if (A[i][j] == 1 || A[i][j] == 2)
				B[i][j] = 1;
		}
	}
}

int main()
{
	cin >> L;
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			cin >> A[i][j];
			if (A[i][j] == 1 || A[i][j] == 2) {
				++cnt;
				B[i][j] = 1;
			}
		}
	}
	int step;
	for (step = 0; cnt != L * L; ++step) {
		infect();
		update();
	}
	cout << step << endl;
	return 0;
}

void infect()
{
	for (int i = 0; i < L; ++i) {
		for (int j = 0; j < L; ++j) {
			if (A[i][j] == 1 && B[i][j] == 1) {
				if (isValid(i - 1) && A[i - 1][j] == 0) { A[i - 1][j] = 1; ++cnt; }
				if (isValid(i + 1) && A[i + 1][j] == 0) { A[i + 1][j] = 1; ++cnt; }
				if (isValid(j - 1) && A[i][j - 1] == 0) { A[i][j - 1] = 1; ++cnt; }
				if (isValid(j + 1) && A[i][j + 1] == 0) { A[i][j + 1] = 1; ++cnt; }
			}
		}
	}
}