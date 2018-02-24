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


long long dp[113010][7][7];
class StringBeads {
public:
	int N;
	vector<int> B;
	int encode(vector<int>& p){
		int code = 0;
		for (int i = 1; i <= N; ++i)
			code = code * 11 + p[i];
		return code;
	}
/*	vector<int> decode(int p){ 
		vector<int> ans(N+1);
		ans[0] = -1;
		for (int i = ans.size() - 1; i > 0; --i){
			ans[i] = p % 11;
			p /= 11;
		}
		return ans;
	}*/
	vector<int> tmp;
	void dfs(int pos,int rest){
		if (pos == N + 1){
			if (rest != 0)
				return;
			int hcode = encode(tmp);
			for (int i = 0; i <= N;++i)
			for (int j = 0; j <= N; ++j){
				long long& ref = dp[hcode][i][j];
				
				if (ref != 0){
					
					for (int k = 1; k <= N; ++k){
						if (k != i&&k != j&&tmp[k] < B[k]){
							tmp[k]++;
							int ncode = encode(tmp);

							dp[ncode][j][k] += ref;
						
							tmp[k]--;
						}
					}
				}
			}
			return;
		}
		for (int i = 0; i <= min(rest, B[pos]); ++i){
			tmp.push_back(i);
			dfs(pos + 1, rest - i);
			tmp.pop_back();
		}
	}

	long long numWays(vector <int> b) {
		sort(b.begin(), b.end());
		B.clear();
		B.push_back(-1);
		tmp.clear();
		tmp.push_back(-1);
		int sum = 0;
		for (int i = 0; i < b.size(); ++i){
			B.push_back(b[i]);
			sum += b[i];
		}
		N = b.size();
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (int i = 0; i <= sum;++i)
		dfs(1, i);
		long long ans = 0;
		int anscode = encode(B);
		for (int i = 0; i <= N;++i)
		for (int j = 0; j <= N; ++j)
			ans += dp[anscode][i][j];
		return ans;
	}
};



/*int main(){
	vector<int> p({ 10,10,8,7,10});
	StringBeads so;
	cout<<so.numWays(p)<<endl;

	int ppp = 0;
	ppp++;














	return 0;
}

*/


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
