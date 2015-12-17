#include<iostream>
using namespace std;

int n, a, b;
int size;
int *mazeParent;
int *isVis;
int *result;
int **maze;
int lastI = -1;

int getRow(int index) {
	for (int r = 1; r <= n; r++) {
		if (index >= ((r) *(r - 1) / 2 + 1) && index <= ((r + 1)*(r) / 2)) {
			return r;
		}
	}
	return 0;
}

int getCol(int index, int row) {
	return index - (row - 1)*row / 2;
}

int MazeFind(int index) {
	int root = index;
	while (mazeParent[root] > 0) {
		root = mazeParent[root];
	}
	int tmp = index;
	int tmp2;
	while (mazeParent[tmp] > 0) {
		tmp2 = mazeParent[tmp];
		mazeParent[tmp] = root;
		tmp = tmp2;
	}
	return root;
}

void MazeUnion(int index1, int index2) {
	int root1, root2;
	root1 = MazeFind(index1);
	root2 = MazeFind(index2);

	if (root1 == root2) {
		return;
	}

	if (mazeParent[root1] < mazeParent[root2]) {
		mazeParent[root1] += mazeParent[root2];
		mazeParent[root2] = root1;
	} else {
		mazeParent[root2] += mazeParent[root1];
		mazeParent[root1] = root2;
	}
}

int getIndex(int r, int c) {
	return (r) *(r - 1) / 2 + c;
}

void test() {
	for (int i = 1; i < 9; i++) {
		cout << i << " " << getRow(i) << " " << getCol(i, getRow(i)) << endl;
	}
}

void fun(int r, int c, bool &test) {
	if (test == true) {
		return;
	}
	result[++lastI] = getIndex(r, c);
	isVis[getIndex(r, c)] = 1;
	int pIndex = 0;
	if (getIndex(r, c) == b) {
		test = true;
		return;
	}
	if (r - 1 > 0 && c - 1 >= 1) {
		pIndex = getIndex(r - 1, c - 1);
		if (MazeFind(pIndex) == MazeFind(b) && isVis[pIndex] == 0 && maze[pIndex][getIndex(r, c)] == 1) {
			isVis[pIndex] = 1;
			fun(r - 1, c - 1, test);
			if (test == false) {
				lastI--;
			} else {
				return;
			}
		}
	}
	if (r - 1 >= 1) {
		pIndex = getIndex(r - 1, c);
		if (MazeFind(pIndex) == MazeFind(b) && isVis[pIndex] == 0 && c <= r - 1 && maze[pIndex][getIndex(r, c)] == 1) {
			isVis[pIndex] = 1;
			fun(r - 1, c, test);
			if (test == false) {
				lastI--;
			} else {
				return;
			}
		}
	}
	if (r + 1 <= n) {
		pIndex = getIndex(r + 1, c);
		if (MazeFind(pIndex) == MazeFind(b) && isVis[pIndex] == 0 && maze[pIndex][getIndex(r, c)] == 1) {
			isVis[pIndex] = 1;
			fun(r + 1, c, test);
			if (test == false) {
				lastI--;
			} else return;
		}
		pIndex = getIndex(r + 1, c + 1);
		if (MazeFind(pIndex) == MazeFind(b) && isVis[pIndex] == 0 && maze[pIndex][getIndex(r, c)] == 1) {
			isVis[pIndex] = 1;
			fun(r + 1, c + 1, test);
			if (test == false) {
				lastI--;
			} else return;
		}
	}
}

int main() {
	//test();
	cin >> n >> a >> b;
	size = (1 + n)*n / 2;
	mazeParent = new int[size + 5];
	maze = new int*[size + 5];
	isVis = new int[size + 5];
	result = new int[size + 5];
	for (int i = 1; i <= size; i++) {
		mazeParent[i] = -1;
		isVis[i] = 0;
		maze[i] = new int[size + 5];
		for (int j = 1; j <= size; j++) {
			maze[i][j] = 0;
		}
	}
	int p, q;
	int r, c;
	while (cin >> p >> q) {
		r = getRow(p);
		c = getCol(p, r);
		if (q == 0) {
			r--;
			c--;
			if (r <= 0 || c <= 0) {

			} else {
				MazeUnion(p, c + (r - 1)*r / 2);
				maze[p][c + (r - 1)*r / 2] = 1;
				maze[c + (r - 1)*r / 2][p] = 1;
			}
		} else if (q == 1) {
			r--;
			c;
			if (c > r) {

			} else {
				MazeUnion(p, c + (r - 1)*r / 2);
				maze[p][c + (r - 1)*r / 2] = 1;
				maze[c + (r - 1)*r / 2][p] = 1;
			}
		} else if (q == 2) {
			r++;
			if (r > n) {
			} else {
				MazeUnion(p, c + (r - 1)*r / 2);
				maze[p][c + (r - 1)*r / 2] = 1;
				maze[c + (r - 1)*r / 2][p] = 1;
			}
		} else if (q == 3) {
			r++;
			c++;
			if (r > n) {

			} else {
				MazeUnion(p, c + (r - 1)*r / 2);
				maze[p][c + (r - 1)*r / 2] = 1;
				maze[c + (r - 1)*r / 2][p] = 1;
			}
		}
		if (MazeFind(a) == MazeFind(b)) {
			break;
		}
	}
	r = getRow(a);
	c = getCol(a, r);
	bool test = false;
	fun(r, c, test);
	for (int i = 0; i <= lastI; i++) {
		cout << result[i] << " ";
	}
	cout << endl;

	return 0;
}
