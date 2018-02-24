#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
int dp[20];
int num[20];


string dfs(int n,int nodenum){
	if (nodenum == 0){
		return "";
	}
	int lfnum, rgnum, lfn, rgn;
	int tmpn = n;
	string ans = "", lf, rg;
	for (int i = 0; i < nodenum; ++i){
		if (tmpn > num[i] * num[nodenum - i - 1]){
			tmpn -= num[i] * num[nodenum - i - 1];
		}
		else{
			lfnum = i;
			rgnum = nodenum - i - 1;
			lfn = (tmpn - 1) / num[rgnum] + 1;
			rgn = (tmpn - 1) % num[rgnum] + 1;
			lf = dfs(lfn, lfnum);
			rg = dfs(rgn, rgnum);
			if (lf.size() != 0)
				lf = "(" + lf + ")";
			if (rg.size() != 0){
				rg = "(" + rg + ")";
			}
			break;
		}
	}
	return lf + "X" + rg;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	dp[1] = 1;
	num[0] = num[1] = 1;
	for (int i = 2; i < 20; ++i){
		num[i] = 0;
		for (int j = 0; j < i; ++j)
			num[i] += num[j] * num[i - j - 1];
		dp[i] = dp[i - 1] + num[i];
	}


	int p = 0;
	int N;
	while (in >> N&&N){
		int nodenum;
		for (int i = 1; i < 20; ++i){
			if (dp[i - 1] < N&&N <= dp[i]){
				nodenum = i;
				N -= dp[i - 1];
				break;
			}
		}
		cout << dfs(N, nodenum) << endl;

	}

















	return 0;
}





