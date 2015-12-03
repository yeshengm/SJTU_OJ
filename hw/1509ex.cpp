#include <iostream>
using namespace std;

int a, b, c, year1, year2;
int leap[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int nonleap[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeap(int n);
void getDate(int dayType, int year);

int main()
{
	cin >> a >> b >> c >> year1 >> year2;
	c = c % 7;
	int totalDay = 2;
	for (int i = 1850; i < year1; ++i) {
		if (isLeap(i)) totalDay += 366;
		else totalDay += 365;
		totalDay %= 7;
	} //从1850到y1年经过的天数

	for (int i = year1; i <= year2; ++i) {
		int tempDay = totalDay;
		bool thisLeap = isLeap(i);
	
		if (thisLeap) {
			for (int j = 1; j < a; ++j)
				tempDay += leap[j];
		} else {
			for (int j = 1; j < a; ++j)
				tempDay += nonleap[j];
		}
		tempDay %= 7; //a月1日是礼拜几
		getDate(tempDay, i);

		if (thisLeap) totalDay = (totalDay + 366) % 7;
		else totalDay = (totalDay + 365) % 7;
	}
	//while (1);
	return 0;
}

bool isLeap(int n)
{
	return (n % 400 == 0 || (n % 100 != 0 && n % 4 == 0));
}

void getDate(int dayType, int year)
{
	int date = 1;
	for (int i = 0; i < 7; ++i) {
		if (dayType == c) break;
		else {
			++date;
			dayType = (dayType + 1) % 7;
		}
	}
	date += (b - 1) * 7;
	int monthDay;
	if (isLeap(year)) monthDay = leap[a];
	else monthDay = nonleap[a];//初始化本月总天数
	if (date <= monthDay) {
		cout << year << '/';
		if (a < 10) cout << '0' << a << '/';
		else cout << a <<'/';
		if (date < 10) cout << '0' << date << endl;
		else cout << date << endl;
	}
	else {
		cout << "none" << endl;
	}
}