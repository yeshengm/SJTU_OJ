#include <iostream>
#include <iomanip>
using namespace std;

int kcfront, hcfront, kcrear, hcrear;
int kc[25000], hc[25000];
int N;
int systime = 0;

bool existhc();
bool existkc();
bool existfourkc();

int main()
{
	kcfront = hcfront = 20000;
	kcrear = hcrear = kcfront + 1;
	
	cin >> N;
	int cartype, currtime;
	for (int i = 0; i < N; ++i)
	{
		cin >> cartype >> currtime;
		if (cartype == 0)
			kc[--kcrear] = currtime;
		else if (cartype == 1)
			hc[--hcrear] = currtime;
	}

	int passn = 0;
	int kctime, hctime; kctime = hctime = 0;
	int kcn = kcfront - kcrear + 1; int hcn = hcfront - hcrear + 1;
	int totaln = kcn + hcn;

	while (totaln != passn)
	{
		int loadn = 0;
		
		for (int i = 0; i < 2; ++i)
		{
			if (existfourkc() && existhc())
			{
				loadn += 5;
				kctime += -kc[kcfront] - kc[kcfront - 1] - kc[kcfront - 2] - kc[kcfront - 3] + systime * 4;
				kcfront -= 4;
				hctime += -hc[hcfront] + systime;
				hcfront--;
			}
		}
		
		while (existkc() && loadn != 10)
		{
			kctime += -kc[kcfront--] + systime;
			loadn++;
		}
		while (existhc() && loadn != 10)
		{
			hctime += -hc[hcfront--] + systime;
			loadn++;
		}
		passn += loadn;
		systime += 10;
	}
	cout << setiosflags(ios::fixed) << setprecision(3) << (double)kctime / (double)kcn << ' ' << (double)hctime / (double)hcn << endl;
	//while (1);
	return 0;
}

bool existhc()
{
	if (hcfront - hcrear + 1 > 0 && hc[hcfront] <= systime)
		return true;
	return false;
}
bool existkc()
{
	if (kcfront - kcrear + 1 > 0 && kc[kcfront] <= systime)
		return true;
	return false;
}

bool existfourkc()
{
	if (kcfront - kcrear + 1 > 3 && kc[kcfront] <= systime && kc[kcfront - 1] <= systime && kc[kcfront - 2] <= systime && kc[kcfront - 3] <= systime)
		return true;
	return false;
}