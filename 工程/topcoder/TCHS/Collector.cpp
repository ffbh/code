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
int dp[500010];
int pa[500010];
class Collector {
	public:
	int minimalSum(vector <int> coins) {
		sort(coins.begin(), coins.end());
		for (int i = 1; i < coins.size(); ++i){
			if (coins[i] == coins[i - 1])
				return -1;
		}
		memset(dp, 0, sizeof(dp));
		memset(pa, 0, sizeof(pa));
		dp[0] = 1;
		pa[0] = 1;
		for (int k = 0; k < coins.size(); ++k){
			int val = coins[k];
			for (int i = 500009; i >= val; --i){
				if (pa[i - val]){
					pa[i] = 1;
					if (dp[i])
						return -1;
				}
			}

			for (int i = val; i < 500010;++i)
			if (dp[i - val]){
				dp[i] = 1;
			}
		}
		int ans = 0;
		for (int i = 0; i < coins.size(); ++i)
			ans += coins[i];
		return ans;

	}
};



#if 0
int main(){
	vector<int> p  ({ 1, 2 });
	Collector so;
	cout<<so.minimalSum(p)<<endl;
















	return 0;
}
#endif



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
