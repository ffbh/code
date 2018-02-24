#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first<b.first;
}
/*int main(int argc, char* argv[])
{
	long start;
	start = clock();
	unsigned int a, b, x, i;
	vector<pair<int, int> > interval;
	ifstream in("C:\\input.txt");
	while (in >> a >> b)
	{
		if (a<b)
			interval.push_back(make_pair(a, b));
		else
			interval.push_back(make_pair(b, a));
	}
	in.close();
	cout << "input end:  " << clock() - start << endl;
	sort(interval.begin(), interval.end(), cmp);
	int maxcover = 0;
	int end = interval[0].second;
	int right, cover;
	for (i = 1; i<interval.size(); i++)
	{
		right = end>interval[i].second ? interval[i].second : end;
		cover = right - interval[i].first >= 0 ? right - interval[i].first + 1 : 0;
		if (cover>maxcover)
			maxcover = cover;
		if (interval[i].second>end)
			end = interval[i].second;
	}
	cout << maxcover << endl;

	cout << clock() - start << endl;
	return 0;
}*/