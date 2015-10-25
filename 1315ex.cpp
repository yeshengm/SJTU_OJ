//如果分子和分母不是互质的，那么之前就已经出现过了
//用sort完成排序

#include <iostream>
#include <algorithm>
using namespace std;

struct frac
{
	int fz;
	int fm;
};
int N;
int sz = 0;
frac stfrac[30000];
bool isprime(int n, int m);
bool fraccmp(frac f1, frac f2);
void append(int j, int i);

int main()
{
	cin >> N;
	
	for (int i = 2; i <= N; ++i) { //i fenmu j fenzi
		for (int j = 1; j < i; ++j)
			if (isprime(j, i)) {
				append(j, i);
			}
	}
	append(0, 1);
	append(1, 1);
	sort(stfrac, stfrac + sz, fraccmp);
	//cout << isprime(3, 15);
	for (int i = 0; i < sz; ++i) {
		cout << stfrac[i].fz << '/' << stfrac[i].fm << endl;
	}
	//while (1);
	return 0;
}

bool isprime(int n, int m)
{
	while (m != 0) {
		int tmp = m;
		m = n % m;
		n = tmp;
	}
	return n == 1;
}

bool fraccmp(frac frac1, frac frac2)
{
	return frac1.fz * frac2.fm < frac1.fm * frac2.fz;
}

void append(int j, int i)
{
	stfrac[sz].fz = j;
	stfrac[sz].fm = i;
	sz++;
}