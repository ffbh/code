#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;



int main(){
	ifstream in("C:\\temp.txt");
	int N;
	map<string, int> mii;
	while (cin >> N){
		mii.clear();
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			int dd = 0;
			for (; dd < s.length(); ++dd)
			if (s[dd] != '0')
				break;
			if (dd != 0 && dd != s.length())
				mii[s.substr(dd)]++;
			else if (dd == s.length())
				mii["0"]++;
			else if (dd == 0)
				mii[s]++;
				
	
				
		}
		map<string, int>::iterator it = mii.begin();
		int mmax = 0;
		while (it != mii.end()){
			if (it->second > mmax)
				mmax = it->second;
			++it;
		}
		cout << mmax << endl;
	}
	return 0;
}