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
string s;
vector<int> data;
int dp[int(1e6) + 10];


int dfs(int p){
	if (p == 1){
		int t = 0;
	}

	if (dp[p] != -1){
		return dp[p];
	}
	int ret;
	if (p == int(data.size()) - 2){
		ret = min(data[p]+1, dfs(p + 1) + 1);
	}
	else if (p == int(data.size()) - 1){
		if (data[p] == 1)
			ret = 1;
		else{
			ret = 2;
		}
	}
	else{
		ret = min(data[p]  + dfs(p + 2), 1 + dfs(p + 1));
	}
	return dp[p] = ret;
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	memset(dp, -1, sizeof(dp));
	in >> s;
	int pos = 0;
	while (pos < s.length()){
		char now = s[pos];
		int num = 0;
		while (pos < s.length() && now == s[pos]){
			pos++;
			num++;
		}
		if (pos != s.length() || now != '0'){
			data.push_back(num);
		}
	}
	dfs(0);
	cout << dp[0] + dp[0] - 1 << endl;
	return 0;
}





