#include <iostream>
using namespace std;

int main()
{
	int hp, hc, num, height, temp, cnt = 0;
	cin >> hp >> hc >> num;
	height = hp + hc;
	for (int i = 0; i < num; ++i) {
		cin >> temp;
		if (temp <= height) ++cnt;
	}
	cout << cnt;
	return 0;
}