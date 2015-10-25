#include <iostream>
using namespace std;
 
const int busy = 0;
const int idle = 1;
int N;
int st[1000000 + 5], et[1000000 + 5];
int state[1000000 + 5];
int begt, endt;
 
int getbeg();
int getend();
void getstate();
bool inrange(int i);
 
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> st[i] >> et[i];
	}
	begt = getbeg();
	endt = getend();
	getstate();
	
	int maxbusy, currbusy, maxidle, curridle;
	maxbusy = currbusy = maxidle = curridle = 0;
	int former = idle;
	for (int i = begt; i < endt; i++)
	{
		if (state[i] == busy)
		{
			if (former == busy)
				++currbusy;
			if (former == idle)
			{
				maxidle = (maxidle > curridle) ? maxidle : curridle;
				curridle = 0;
				currbusy = 1;
				former = busy;
			}
		}
		if (state[i] == idle)
		{
			if (former == idle)
				++curridle;
			if (former == busy)
			{
				maxbusy = (maxbusy > currbusy) ? maxbusy : currbusy;
				currbusy = 0;
				curridle = 1;
				former = idle;
			}
		}
	}
	maxidle = (maxidle > curridle) ? maxidle : curridle;
	maxbusy = (maxbusy > currbusy) ? maxbusy : currbusy;
	//cout << begt << ' ' << endt;
	cout << maxbusy << ' ' << maxidle << endl;
	//while (1);
	return 0;
}
 
int getbeg()
{
	int min = st[0];
	for (int i = 0; i < N; i++)
	{
		min = (st[i] < min) ? st[i] : min;
	}
	return min;
}
 
int getend()
{
	int max = et[0];
	for (int i = 0; i < N; i++)
	{
		max = (et[i] > max) ? et[i] : max;
	}
	return max;
}
 
bool inrange(int pos)
{
	for (int i = 0; i < N; i++)
	{
		if (pos >= st[i] && pos + 1 <= et[i])
			return true;
	}
	return false;
}
 
void getstate()
{
	for (int i = begt; i < endt; i++)
	{
		if (inrange(i))
			state[i] = busy;
		else state[i] = idle;
	}
}