#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string ss;
int beg, iff, ift;
int main()
{
	while (cin >> ss) {
		if (ss == "begin") ++beg;
		else if (ss == "end") --beg;
		else if (ss == "if") ++iff;
		else if (ss == "then") { --iff; ++ift; }
		else if (ss == "else") { --ift; }
		if (beg < 0 || iff < 0 || ift < 0) {
			cout << "Error!" << endl;
			return 0;
		}
	}
	if (beg != 0 || iff != 0) {
		cout << "Error!" << endl;
		return 0;
	}
	cout << "Match!" << endl;
	return 0;
}