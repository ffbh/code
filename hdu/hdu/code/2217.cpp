#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v1, v2;

int main(){
	ifstream in("C:\\temp.txt");
	int N, T;
	vector<int>::iterator it;
	while (cin >> N >> T){
		v1.clear();
		v2.clear();
		int ans1 = 0;
		while (N--){
			int t;
			cin >> t;
			if (t > 0)
				v1.push_back(t);
			else if (t == 0)
				ans1++;
			else
				v2.push_back(-t);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int mmax = 0;
		for (int i = 0; i < v1.size(); ++i){
			if (v1[i]>T)
				continue;
			int temp = i + 1;
			it = lower_bound(v2.begin(), v2.end(), T - 2 * v1[i]);
			if (it!=v2.end()&&*it == T - 2 * v1[i])
				temp++;
			temp += it - v2.begin();
			if (mmax < temp)
				mmax = temp;
		}
		for (int i = 0; i < v2.size(); ++i){
			if (v2[i]>T)
				continue;
			int temp = i + 1;
			it = lower_bound(v1.begin(), v1.end(), T - 2 * v2[i]);
			if (it!=v1.end()&&*it == T - 2 * v2[i])
				temp++;
			temp += it - v1.begin();
			if (mmax < temp)
				mmax = temp;
		}
		cout << ans1 + mmax << endl;
	}
	return 0;
}