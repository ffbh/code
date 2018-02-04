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
#define DEBUG (0)

int dp[66666];
int pace[66666];
vector<int> pc[20], W;
int N;

int Count(int code){
	int num = 0;
	for (int i = 0; i < N; ++i){
		if (code&(1 << i))
			num++;
	}
	return num;
}

bool judge(int p, int code){
	for (int i = 0; i < pc[p].size(); ++i){
		int pianyi = pc[p][i];
		if (!(code & (1 << pianyi)))
			return 0;
	}
	return 1;
}

int dfs(int code){
	if (code == (1 << N) - 1){
		return 0;
	}
	if (dp[code] != -1){
		return dp[code];
	}
	int num = Count(code);
	dp[code] = (1 << 29);
	for (int k = 0; k < N; ++k){
		if (code&(1 << k))
			continue;
		if (judge(k, code)){
			int ret = dfs(code + (1 << k)) + num*W[k];
			if (dp[code] > ret){
				dp[code] = ret;
				pace[code] = k;
			}
		}
	}
	return dp[code];
}

class WarehouseJob {
	public:
	vector <int> stackBoxes(vector <int> weight, vector <string> above) {
		W = weight;
		for (int i = 0; i < 20; ++i)
			pc[i].clear();
		memset(dp, -1, sizeof(dp));

		N = weight.size();
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N;++j)
		if (above[i][j] == '1'){
			pc[i].push_back(j);
		}

	/*	for (int i = 0; i < (1 << N); ++i){
			int h = Count(i);
			for (int k = N-1; k >= 0 ; --k){
				if (i&(1 << k))
					continue;
				if (judge(k,i)){
					int ni = i + (1 << k);
					if (dp[ni] >  dp[i] + h*weight[k]){
						dp[ni] = dp[i] + h*weight[k];
						pace[ni] = k;
					}
				}
			}
		}
		vector<int> ans;
		int code = (1 << N) - 1;
		while (code){
			ans.push_back(pace[code]);
			code -= (1 << pace[code]);
		}
		reverse(ans.begin(), ans.end());
		return ans;*/

		dfs(0);
		vector<int> ans;
		int code = 0;
		while (code != (1 << N) - 1){
			ans.push_back(pace[code]);
			code += (1 << pace[code]);
		}
		return ans;

	}
};



#if DEBUG
int main(){
	
	vector<int> a({ 3, 9, 8, 5, 8, 9, 7, 3, 9, 5, 4, 10 });
	vector<string> b({ "000000000000",
		"000000000000",
		"000000000000",
		"000000000010",
		"000100000000",
		"000000000100",
		"000000001000",
		"000000000000",
		"000000000000",
		"000000000000",
		"000000000000",
		"000000000000" }
	);
	WarehouseJob so;
	vector<int> r = so.stackBoxes(a, b);
	for (int i = 0; i < r.size(); ++i)
		cout << r[i] << " ";
	cout << endl;
















	return 0;
}
#endif



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
