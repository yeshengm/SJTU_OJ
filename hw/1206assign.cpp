#include <iostream>
using namespace std;

bool isequal(char *a, char *b)
{
	while (*a == *b) {
		if (*a == '\0' && *b == '\0') return true;
		++a;
		++b;
	}
	return false;
}

int main()
{
	char beg[10000];
	char ite[10000];
	int begpos = 0, itepos = 0;
	int nbeg = 0, ni = 0, nit = 0;
	char tmp[50] = "";
	while (cin >> tmp) {
		if (isequal(tmp, "begin")) nbeg++;
		if (isequal(tmp, "end")) {
			if (nbeg == 0) {
				cout << "Error!" << endl;
				return 0;
			}
			else --nbeg;
		}
		if (isequal(tmp, "if"))
			++ni;
		if (isequal(tmp, "then")) {
			if (ni == 0) {
				cout << "Error!" << endl;
				return 0;
			}
			--ni;
			++nit;
		}
		if (isequal(tmp, "else")) {
			if (nit == 0) {
				cout << "Error!" << endl;
				return 0;
			}
			--nit;
		}
	}
	cout << "Match!" << endl;
	//while (1);
	return 0;
}