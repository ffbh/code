#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	set<int> si;
	set<int>::iterator it;
	for (int i = 0; i < 96; ++i)
		si.insert(i*(i + 1)*(i + 2) / 6);
	int mmin ;
	while (cin >> N&&N){
		mmin = 99999;
		for (int i = 0; i < 54; ++i){
			int temp = i*i*i;
			if (temp>N)
				break;
	        it = lower_bound(si.begin(), si.end(), N - temp);
			if (it == si.end())
				it--;
			if (*it>N - temp)
				it--;
			if (mmin > N - temp - *it)
				mmin = N - temp - *it;
		}
		cout << N - mmin << endl;
	}
	return 0;
}