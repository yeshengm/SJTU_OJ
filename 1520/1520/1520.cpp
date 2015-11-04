#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
//ifstream fin("1520.in");
char file[1000000];
int filepos = 0;
char str[30000][15];
int sz = 0;

bool isOp(char *p) {
	if (*p == '+' || *p == '-' || *p == '(' || *p == ')')
		return true;
	else return false;
}

int getInt(char *p) {
	int tmp = 0;
	while (*p != '\0') {
		tmp = tmp * 10 + (int) (*p - '0');
		++p;
	}
	return tmp;
}

bool getInput(char *p) {
	if (file[filepos] == '\0') return false;
	if (isOp(file + filepos)) {
		p[0] = *(file + filepos);
		p[1] = '\0';
		filepos++;
	} else if (!isOp(file + filepos)) {
		for (int i = 0; file[filepos] != '\0' && file[filepos] >= '0' && file[filepos] <= '9'; ++i) {
			p[i] = file[filepos];
			p[i + 1] = '\0';
			++filepos;
		}
	}
	return true;
}

void copystr(char (*p)[15], char *input) {
	for (int i = 0; i < 10; ++i) {
		p[sz][i] = input[i];
	}
}

void setInt(int n) {
	char a[10];
	int asz = 0;
	str[sz - 1][0] = '0'; str[sz - 1][1] = '\0';
	while (n != 0) {
		int tmp = n % 10;
		a[asz++] = tmp + '0';
		n /= 10;
	}
	for (int i = 0; i < asz; ++i) {
		str[sz - 1][i] = a[asz - 1 - i];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	char input[100];
	for (int i = 0; i < 1000000; ++i) {
		char c = cin.get();
		while (c == ' ') c = cin.get();
		file[i] = c;
		file[i + 1] = '\0';
		if (c == '\0' || c == EOF || c == '\n') {
			file[i] = '\0';
			break;
		}
	}
	while (getInput(input)) {
		if (input[0] == '+' && (str[sz - 1][0] == '+' || str[sz - 1][0] == '('))
			continue;
		if (!isOp(input)) { copystr(str, input); sz++; }
		if (isOp(input)) {
			if (input[0] == '+') { str[sz][0] = '+'; str[sz][1] = '\0'; ++sz; } //no sz - 1
			else if (input[0] == '-') { str[sz][0] = '-'; str[sz][1] = '\0'; ++sz; }
			else if (input[0] == '(') { str[sz][0] = '('; str[sz][1] = '\0'; ++sz; }
			else if (input[0] == ')') {
				int tmp = 0;
				while (str[sz - 1][0] != '(') {	 
					if (sz >= 2 && str[sz - 2][0] == '(') { tmp += getInt(str[sz - 1]); sz -= 1; }
					else if (sz >= 2 && str[sz - 2][0] == '+') { tmp += getInt(str[sz - 1]); sz -= 2; }
					else if (sz >= 2 && str[sz - 2][0] == '-') { tmp -= getInt(str[sz - 1]); sz -= 2; }
				}
				setInt(tmp);
			}
		}
	}
	int sum = 0;
	if (sz == 1) {
		cout << str[0];
		return 0;
	}
	while (sz >= 1) {
		if (sz == 1 && !isOp(str[0])) { sum += getInt(str[sz - 1]); break; }
		else if (sz == 2 && str[0][0] == '-') { sum -= getInt(str[sz - 1]); break; }
		else if (sz >= 2 && str[sz - 2][0] == '+') { sum += getInt(str[sz - 1]); sz -= 2; } 
		else if (sz >= 2 && str[sz - 2][0] == '-') { sum -= getInt(str[sz - 1]); sz -= 2; }
	}
	cout << sum;
	return 0;
}