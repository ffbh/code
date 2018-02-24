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

int dp[110][110][110];

class ProductionOptimization {
public:
	vector<int> c, t;
	int final_type;
	int dfs(int tottime, int totcost, int type){

		if (tottime < 0 || totcost < 0)
			return 0;
		if (dp[tottime][totcost][type] != -1){
			return  dp[tottime][totcost][type];
		}
		if (type == final_type){
				return dp[tottime][totcost][type] = min(tottime / t[type], totcost / c[type]) + 1;

		}

		int& ref = dp[tottime][totcost][type];

		dp[tottime][totcost][type] = 0;
		if (tottime == 43 && totcost == 60){
			int t = 0;
		}
		for (int i = 0; i <= totcost; ++i){
			int a = dfs(tottime - t[type + 1], totcost - i - c[type + 1], type + 1);
			int b = dfs(tottime - t[type], i - c[type], type);
			dp[tottime][totcost][type] = max(dp[tottime][totcost][type], a + b);

		}

		return 	dp[tottime][totcost][type];

	}



	int getMost(vector <int> costs, vector <int> times, int totCost, int totTime) {



		c = costs;
		t = times;
		final_type = costs.size() - 1;
		memset(dp, -1, sizeof(dp));

		return dfs(totTime - t[0], totCost - c[0], 0);
	}
};


int main(){
	vector<int> c({ 16, 23, 1 });
	vector<int> t({ 4, 32, 6 });


	ProductionOptimization so;
	cout << so.getMost(c, t, 99, 79) << endl;




}