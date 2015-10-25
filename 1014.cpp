#include <iostream>
using namespace std;

int a[100000 + 10], b[100000 + 10], indexa, indexb;

void movea(int pos)
{
	while (indexa >= 0) {
		int temp = a[indexa];
		a[indexa] = 0;
		a[pos] = temp;
		pos--; indexa--;
	}
}

void moveb(int pos)
{
	while (indexb >= 0) {
		int temp = b[indexb];
		b[indexb] = 0;
		b[pos] = temp;
		pos--; indexb--;
	}
}


//倒存数组实现似乎更加简单

int main()
{
	char c;
	indexa = indexb = 0;
	while ((c = cin.get()) != '\n') {
		a[indexa++] = c - '0';
	}
	while ((c = cin.get()) != '\n') {
		b[indexb++] = c - '0';
	}
	int max = (indexa > indexb ? indexa : indexb);
	indexa--; indexb--;

	movea(max);
	moveb(max);
	
	int pos = max;
	while (pos >= 1) {
		int temp = a[pos] + b[pos];
		b[pos--] = temp % 10;
		b[pos] += temp / 10;
	}

	if (b[0] == 0) {
		for (int i = 1; i <= max; ++i) cout << b[i];
		cout << endl;
	}
	if (b[0] != 0) {
		for (int i = 0; i <= max; ++i) cout << b[i];
		cout << endl;
	}
	//while (1);
	return 0;
}

