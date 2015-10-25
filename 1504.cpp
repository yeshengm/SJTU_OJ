#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a*a + b*b == c*c || a*a == b*b + c*c || a*a + c*c == b*b)
		cout << "right-angled triangle";
	else if (a + b <= c || a + c <= b || b + c <= a)
		cout << "not triangle";
	else cout << "triangle";
	cout << endl;
	return 0;
}