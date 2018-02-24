#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int num[10], ans[4];


bool slove(int m, int index){
	for (int i = m; i >= 0;--i){
		if (num[i]){
			num[i]--;
			ans[index] = i;
			return 1;
		}
	}
	return 0;
}


int main(){
	ifstream in("C:\\input.txt");
	int mmax;
	for (int i = 0; i < 4; ++i){
		int t;
		cin >> t;
		num[t]++;
	}
	memset(ans, -1, sizeof(ans));
	mmax = 2;

	if (!slove(mmax,0)){
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}
	
	if (ans[0] == 2)
		mmax = 3;
	else
		mmax = 9;

	if (!slove(mmax, 1)){
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}

	mmax = 5;
	if (!slove(mmax, 2)){
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}

	mmax = 9;
	if (!slove(mmax, 3)){
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}
	printf("%d%d:%d%d\n", ans[0], ans[1], ans[2], ans[3]);
	return 0;
}