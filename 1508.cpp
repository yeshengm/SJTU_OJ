#include "iostream"
using namespace std;

const int yuanshi = 8000, wusi = 4000, chengji = 2000, xibu = 1000, banji = 850;

struct student
{
	char name[20];
	int grade;
	int inclassgrade;
	char leader;
	char west;
	int publication;
	int money = 0;

	void calculate()
	{
		cin >> name;
		cin >> grade >> inclassgrade >> leader >> west >> publication;
		if (grade > 80 && publication >= 1) money += yuanshi;
		if (grade > 85 && inclassgrade > 80) money += wusi;
		if (grade > 90) money += chengji;
		if (grade > 85 && west == 'Y') money += xibu;
		if (inclassgrade > 80 && leader == 'Y') money += banji;
	}
};

int main()
{
	int N;
	cin >> N;
	student sjtu[100];
	for (int i = 0; i < N; ++i)
		sjtu[i].calculate();
	int max = 0;
	int maxn = 0;
	for (int i = 0; i < N; ++i) {
		if (sjtu[i].money > max) {
			max = sjtu[i].money;
			maxn = i;
		}
	}
	cout << sjtu[maxn].name << endl;
	cout << sjtu[maxn].money << endl;
	int total = 0;
	for (int i = 0; i < N; ++i)
		total += sjtu[i].money;
	cout << total << endl;
	return 0;
}