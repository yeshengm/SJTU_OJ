#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#pragma warning(disable:4996)
char file[105][2005];
int size[105];
int fileSize = 0;

void list(int start, int end);
void ins(int x, int y, char* str);
void del(int x, int y, int num);
void quit();

int main()
{
	char copy[2005], command[10];
	for (int i = 1;; ++i) {
		cin.getline(copy, 2005);
		if (strcmp(copy, "******") == 0) {
			fileSize = i - 1;
			break;
		}
		else {
			strcpy(file[i] + 1, copy);
			*(file[i] + 1 + strlen(copy)) = '\0';
			size[i] = strlen(copy);
		}
	}

	while (1) {
		cin >> command;
		if (strcmp(command, "list") == 0) {
			int start, end;
			cin >> start >> end;
			list(start, end);
		}
		if (strcmp(command, "ins") == 0) {
			int x, y;
			char str[105];
			cin >> x >> y;
			cin.getline(str, 105);
			int sz = strlen(str);
			for (int i = 0; i <= sz; ++i)
				str[i] = str[i + 1];
			ins(x, y, str);
		}
		if (strcmp(command, "del") == 0) {
			int x, y, num;
			cin >> x >> y >> num;
			del(x, y, num);
		}
		if (strcmp(command, "quit") == 0) {
			break;
		}
	}
	quit();
	while (1);
	return 0;
}

void list(int start, int end)
{
	if (start < 1 || end > fileSize || start > end) {
		cout << "Error!" << endl;
		return;
	}
	for (int i = start; i <= end; ++i)
		cout << file[i] + 1 << endl;
}

void ins(int x, int y, char* str)
{
	int strsize = strlen(str);
	if (x < 1 || x > fileSize || y < 1 || y > size[x] + 1) {
		cout << "Error!" << endl;
		return;
	}
	if (y + strsize > 2000) {
		cout << "Error!" << endl;
		return;
	}
	for (int i = size[x] + 1; i >= y; --i)
		file[x][i + strsize] = file[x][i];
	for (int i = 0; i < strsize; ++i)
		file[x][y + i] = str[i];
	size[x] += strsize;
}

void del(int x, int y, int num)
{
	if (x < 1 || x > fileSize || y < 1 || y > size[x]) {
		cout << "Error!" << endl;
		return;
	}
	if (y + num - 1 > size[x]) {
		cout << "Error!" << endl;
		return;
	}
	for (int i = y; i <= size[x] + 1 - num; ++i) {
		file[x][i] = file[x][i + num];
	}
	size[x] -= num;
}

void quit()
{
	for (int i = 1; i <= fileSize; ++i)
		cout << file[i] + 1 << endl;
}