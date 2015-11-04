#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[100000];
char b[100000];
int bita, bitb;

int strlen(char p[]) {
	int cnt = 0;
	while (*(p++) != '\0') cnt++;
	return cnt;
}

int flag(char *a, char *b) {
	while (1) { 
		if (*a > *b) return 1;
		if (*a < *b) return -1;
		++a; ++b;
		if (*a == '\0')
			return 0;
	}
}

void write(char *p) {
	while (*p == '0') p++;
	while (*p != '\0') { cout << (int) *p - '0'; ++p; }
}

int main()
{
	cin.getline(a, 100000, '\n');
	cin.getline(b, 100000, '\n');
	bita = strlen(a);
	bitb = strlen(b);
	if (bita > bitb) {
		for (int i = bitb - 1; i >= 0; --i)
			b[i + bita - bitb] = b[i];
		for (int i = 0; i < bita - bitb; ++i)
			b[i] = '0';
		for (int i = bita - 1; i >= 0; --i) {
			if (a[i] >= b[i]) a[i] = a[i] - b[i] + '0';
			else {
				a[i - 1]--;
				a[i] = a[i] - b[i] + 10 +'0';
			}
		}
		write(a);
		//cout << endl;
		return 0;
	} else if (bita < bitb) {
		for (int i = bitb - 1; i >= 0; --i)
			a[i + bitb - bita] = a[i];
		for (int i = 0; i < bitb - bita; ++i)
			a[i] = '0';
		for (int i = bitb - 1; i >= 0; --i) {
			if (b[i] >= a[i]) b[i] = b[i] - a[i] + '0';
			else {
				b[i - 1]--;
				b[i] = b[i] - a[i] + 10 + '0';
			}
		}
		cout << '-';
		write(b);
		//cout << endl;
		return 0;
	} else if (bita == bitb) {
		int f = flag(a, b);
		if (f == 0) { cout << '0' << endl; return 0; }
		if (f == -1) {
			cout << '-';
			for (int i = bita - 1; i >= 0; --i) {
				if (b[i] >= a[i]) b[i] = b[i] - a[i] + '0';
				else if (b[i] < a[i]) { b[i] = b[i] - a[i] + 10 + '0'; b[i - 1]--; }
			}
			write(b);
			//cout << endl;
			return 0;
		}
		if (f == 1) {
			for (int i = bita - 1; i >= 0; --i) {
				if (a[i] >= b[i]) a[i] = a[i] - b[i] + '0';
				else if (a[i] < b[i]) { a[i] = a[i] - b[i] + 10 + '0'; a[i - 1]--; }
			}
			write(a);
			return 0;
		}
		
		//while (1);
		return 0;
	}
	
	//system("pause");
	return 0;
}
/*
1234
2345
*/