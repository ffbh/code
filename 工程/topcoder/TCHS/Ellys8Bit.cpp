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
long long dp[70][10], sum[70][10];

class Ellys8Bit {
	public:
	long long getNumber(int N) {
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int len = 1; len < 70;++len)
		for (int i = 1; i < 10; ++i){
			dp[len][i] = dp[len - 1][i] + dp[len - 1][i - 1];
		}
		for (int i = 1; i < 70; ++i)
		for (int j = 0; j < 10;++j)
			sum[i][j] = sum[i - 1][j] + dp[i][j];
		

		vector<int> ans(65,0);
		int rest = 8;
		for (int i = 64; i >= 1&&rest; --i){
			if (sum[i - 1][rest] < N){
				ans[i] = 1;
				N -= sum[i - 1][rest];
				rest--;
			}
		}
		long long ret = 0;
		for (int i = 64; i >= 1; --i)
			ret = ret * 2 + ans[i];



		return ret;
	}
};



#if 0
int main(){
	
	Ellys8Bit so;
	cout<<so.getNumber(1)<<endl;
















	return 0;
}
#endif

