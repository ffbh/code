#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	map<_int64, int> mii;
	while (cin >> N&&N){
		mii.clear();
		while(N--){
			int num[5];
			_int64 temp = 0;
			for (int i = 0; i < 5; ++i)
				cin >> num[i];
			sort(num, num + 5);
			for (int i = 0; i < 5; ++i)
				temp = temp * 500 + num[i];
			mii[temp]++;
		}
		map<_int64, int>::iterator it = mii.begin();
		int ans = 0;
		int maxsize = 0;
		while (it != mii.end()){
			if (it->second>maxsize){
				maxsize = it->second;
				ans = maxsize;
			}
			else if (maxsize == it->second)
				ans += it->second;
			it++;
		}
		cout << ans << endl;
	}
	return 0;
}