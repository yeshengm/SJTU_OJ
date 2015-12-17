#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int topLeft = 0;
const int topRight = 1;
const int botLeft = 2;
const int botRight = 3;

int N = 2, A = 2, B = 3, inRow, inCol, outRow, outCol;
int UF[1000][1000];
bool mark[1000][1000];
int route[100][1000];
int routeCnt = 1;

int cmp(const void *a, const void *b) {
	for (int i = 1; i < 100; ++i) {
		if (*(int *) a < *(int *) b) return -1;
		if (*(int *) a > *(int *) b) return 1;
	}
	return 0;
}

int getNum(int row, int col) {
	int num = 0;
	num += row * (row - 1) / 2;
	num += col;
	return num;
}
void getPos(int &row, int &col, int num) {
	int i = 0, tmpNum = 0;
 	while (tmpNum + i < num) {
		tmpNum += i;
		++i;
	}
	row = i;
	col = num - tmpNum;
}
bool valid(int row, int col, int dir) {
	if (row == 1 && (dir == topLeft || dir == topRight)) return false;
	if (row == N && (dir == botLeft || dir == botRight)) return false;
	if (col == 1 && dir == topLeft) return false;
	if (row == col && dir == topRight) return false;
	return true;
}
int find(int row, int col) {
	if (UF[row][col] == -1) return getNum(row, col);
	int nextRow, nextCol;
	getPos(nextRow, nextCol, UF[row][col]);
	UF[row][col] = find(nextRow, nextCol);
	return UF[row][col];
}
void Union(int root1, int root2) {
	int row1, col1, row2, col2;
	getPos(row1, col1, root1); getPos(row2, col2, root2);
	if (row1 == row2 && col1 == col2) return;
	UF[row1][col1] = root2;
}
void dfs(int row, int col, int dep) {
	if (mark[row][col]) return;
	mark[row][col] = true;
	route[routeCnt][dep] = getNum(row, col);
	if (getNum(row, col) == B) {
		route[routeCnt++][0] = dep;
		for (int i = 1; i <= dep; ++i)
			route[routeCnt][i] = route[routeCnt - 1][i];
		mark[row][col] = false;
		return;
	}
	if (valid(row, col, topLeft) && find(row, col) == find(row - 1, col - 1)) dfs(row - 1, col - 1, dep + 1);
	if (valid(row, col, topRight) && find(row, col) == find(row - 1, col)) dfs(row - 1, col, dep + 1);
	if (valid(row, col, botLeft) && find(row, col) == find(row + 1, col)) dfs(row + 1, col, dep + 1);
	if (valid(row, col, botRight) && find(row, col) == find(row + 1, col + 1)) dfs(row + 1, col + 1, dep + 1);
	mark[row][col] = false;
}
int main() {
	cin >> N >> A >> B;
	getPos(inRow, inCol, A); getPos(outRow, outCol, B);
	for (int i = 0; i < 1000; ++i) for (int j = 0; j < 1000; ++j) UF[i][j] = -1;
	while (find(inRow, inCol) != find(outRow, outCol) || (UF[inRow][inCol] == -1 && UF[outRow][outCol] == -1)) {
		int currNum, currDir, currRow, currCol; cin >> currNum >> currDir;
		getPos(currRow, currCol, currNum);
		if (!valid(currRow, currCol, currDir)) continue;
		int nextRow = 0, nextCol = 0;
		if (currDir == topLeft) { nextRow = currRow - 1; nextCol = currCol - 1; }
		else if (currDir == topRight) { nextRow = currRow - 1; nextCol = currCol; }
		else if (currDir == botLeft) { nextRow = currRow + 1; nextCol = currCol; }
		else if (currDir == botRight) { nextRow = currRow + 1; nextCol = currCol + 1; }
		Union(find(currRow, currCol), find(nextRow, nextCol));
	}
	dfs(inRow, inCol, 1);
	int minstr[100], minlen = route[1][0];
	for (int i = 1; i <= route[1][0]; ++i)
		minstr[i] = route[1][i];
	for (int i = 2; i < routeCnt; ++i) {
		bool smaller = false;
		if (route[i][0] < minlen) smaller = true;
		else if (route[i][0] == minlen)
			for (int j = 1; j <= minlen; ++j) 
				if (route[i][j] < minstr[j]) 
					smaller = true;
		if (smaller) {
			minlen = route[i][0];
			for (int j = 1; j <= minlen; ++j)
				minstr[j] = route[i][j];
		}
	}
	for (int i = 1; i <= minlen; ++i)
		cout << minstr[i] << ' ';
	return 0;
}