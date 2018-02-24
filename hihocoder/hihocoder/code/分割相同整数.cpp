#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> mii;
map<int, int>::iterator it;
map<int, int>::iterator mmaxid;
int num[100010];
int sum, size, mmax;
bool judge(){
	it = mii.begin();
	size = 0;
	mmax = 0;
	while (it != mii.end()){
		if (it->second >= mmax){
			mmax = it->second;
			mmaxid = it;
		}
		it++;
	//	num[it->first] = it->second;
	}
	return (mmax - 1) <= (sum - mmax);
}

bool judgeend(){
	return sum - mmax == mmax - 1;
}

void findmax(){
	it = mii.begin();
	mmax = 0;
	while (it != mii.end()){
		if (it->second >= mmax){
			mmax = it->second;
			mmaxid = it;
		}
		it++;
	}
}

int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	sum = N;
	while(N--){
		int t;
		cin >> t;
		mii[t]++;
	}
	if (!judge()){
		cout << -1 << endl;
		return 0;
	}
	int pre = -1;
	while (!judgeend()){
		it = mii.begin();
		if (it->first == pre)
			++it;
		printf("%d ", it->first);
		sum--;
		pre = it->first;
		if (mii[pre] == 1)
			mii.erase(it);
		else{
			mii[pre]--;
			if (pre == mmaxid->first){
				findmax();
			}
		}
	}
	int id = mmaxid->first;
	mii.erase(mmaxid);
	for (it = mii.begin(); it != mii.end();++it)
	for (int j = 0; j < it->second; ++j)
		printf("%d %d ", id, it->first);
	printf("%d\n", id);



	return 0;
}