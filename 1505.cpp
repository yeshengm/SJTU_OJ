#include <iostream>
using namespace std;

char trans[] = "abcdefghijklmnopqrstuvwxyzabcd";

int main()
{
	char psw;
	cin >> psw;
	cout << trans[psw - 'a' + 3] << endl;
	return 0;
}