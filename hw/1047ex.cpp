/*
之前想的方法是设置一个30位的序列遍历，但是这样遍历次数为10^30
而采用循环嵌套之后，遍历次数为3^10
*/

#include <iostream>
using namespace std;

int A[3][3];
int mat[3][3];
int op[15] = {0};

void movemat(int opn)
{
	switch (opn)
	{
	case 1:
	{
		mat[0][0] += 3;
		mat[0][1] += 3;
		mat[1][0] += 3;
		mat[1][1] += 3;
		break;
	}
	case 2:
	{
		mat[0][0] += 3;
		mat[0][1] += 3;
		mat[0][2] += 3;
		break;
	}
	case 3:
	{
		mat[0][1] += 3;
		mat[0][2] += 3;
		mat[1][1] += 3;
		mat[1][2] += 3;
		break;
	}
	case 4:
	{
		mat[0][0] += 3;
		mat[1][0] += 3;
		mat[2][0] += 3;
		break;
	}
	case 5:
	{
		mat[0][1] += 3;
		mat[1][0] += 3;
		mat[1][1] += 3;
		mat[1][2] += 3;
		mat[2][1] += 3;
		break;
	}
	case 6:
	{
		mat[0][2] += 3;
		mat[1][2] += 3;
		mat[2][2] += 3;
		break;
	}
	case 7:
	{
		mat[1][0] += 3;
		mat[1][1] += 3;
		mat[2][0] += 3;
		mat[2][1] += 3;
		break;
	}
	case 8:
	{
		mat[2][0] += 3;
		mat[2][1] += 3;
		mat[2][2] += 3;
		break;
	}
	case 9:
	{
		mat[1][1] += 3;
		mat[1][2] += 3;
		mat[2][1] += 3;
		mat[2][2] += 3;
		break;
	}
	break;
	}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (mat[i][j] > 12)
				mat[i][j] %= 12;
}

bool same()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (mat[i][j] != 12) return false;
	return true;
}

int main()
{
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> A[i][j];

	for (op[1] = 0; op[1] < 4; ++op[1])
		for (op[2] = 0; op[2] < 4; ++op[2])
			for (op[3] = 0; op[3] < 4; ++op[3])
				for (op[4] = 0; op[4] < 4; ++op[4])
					for (op[5] = 0; op[5] < 4; ++op[5])
						for (op[6] = 0; op[6] < 4; ++op[6])
							for (op[7] = 0; op[7] < 4; ++op[7])
								for (op[8] = 0; op[8] < 4; ++op[8])
									for (op[9] = 0; op[9] < 4; ++op[9])
									{
										for (int i = 0; i < 3; ++i)
											for (int j = 0; j < 3; ++j)
												mat[i][j] = A[i][j];
										for (int i = 1; i <= 9; ++i)
											for (int j = 0; j < op[i]; ++j)
												movemat(i);
										if (same())
										{
											for (int i = 1; i <= 9; ++i)
												for (int j = 0; j < op[i]; ++j)
													cout << i << ' ';
											cout << endl;
											return 0;
										}
									}
	cout << "Error!" << endl;
	while (1);
	return 0;
}