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
int val[1010];
int sum[1010];
int dp[1010][1010];
int premax[1010];
int tmp[1010];
int N;
class ElectiveSystem {
	public:
	int maximalGoodness(vector <string> values, int D, int K) {
		string all = "";
		for (int i = 0; i < values.size(); ++i){
			all += values[i];
		}
		N = all.length();
		for (int i = 0; i < all.length(); ++i){
			val[i+1] = all[i] - 'a' + 1;
		}
		sum[0] = 0;
		for (int i = 1; i <= N; ++i){
			sum[i] = sum[i - 1] + val[i];
		}
		if (D*K >= all.length()){
			return sum[N];
		}

		memset(premax, 0, sizeof(premax));

		memset(dp, 0, sizeof(dp));
		for (int k = 1; k <= K; ++k){
			tmp[0] = 0;
			for (int i = 1; i <= N; ++i){
				int low = max(0, i - D);
				int vals = sum[i] - sum[low];
				dp[k][i] = max(dp[k][i - 1], premax[low] + vals);
				tmp[i] = max(tmp[i - 1], dp[k][i]);
			}
			for (int i = 0; i <= N; ++i)
				premax[i] = tmp[i];
		}
		return dp[K][N];
	}
};



#if DEBUG
int main(){
	
	ElectiveSystem so;
	cout<<so.maximalGoodness()<<endl;
















	return 0;
}
#endif

