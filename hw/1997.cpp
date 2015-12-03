#include "iostream"
using namespace std;

int diff(int a, int b)
{
	return (a > b) ? a - b : b - a;
}

int main()
{
	int N, W;
	cin >> N >> W;
	int weight[1000 + 10];
	for (int i = 0; i < N; ++i) cin >> weight[i];
	int bestw = weight[1];
	for (int i = 0; i < N; ++i) {
		if (diff(weight[i], W) < diff(W, bestw))
			bestw = weight[i];
		else if (diff(weight[i], W) == diff(W, bestw) && weight[i] >= bestw)
			bestw = weight[i];
	}
	cout << bestw << endl;
	//while (1);
	return 0;
}