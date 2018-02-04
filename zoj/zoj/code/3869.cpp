#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	map<int, int> mii;
	int T;
	cin >> T;
	while (T--){
		mii.clear();
		int N;
		cin >> N;
		while (N--){
			int t;
			cin >> t;
			mii[t]++;
		}
		int maxid, maxnum;
		bool flag = 0;
		maxnum = -1;
		map<int, int>::iterator it = mii.begin();
		while (it != mii.end()){
			if (it->second > maxnum){
				maxnum = it->second;
				maxid = it->first;
				flag = 0;
			}
			else if (it->second == maxnum)
				flag = 1;
			it++;
		}
		if (flag)
			cout << "Nobody" << endl;
		else
			cout << maxid << endl;
	}
	return 0;
}