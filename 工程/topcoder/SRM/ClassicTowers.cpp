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
string ans;
int dig[70];
long long K;
int dp[60][60][60][3];
int len;
int dfs(int a, int b, int c, int aim, int pos){
	if (a < 0 || b < 0 || c < 0)
		return 0;
	if (pos == -1){
		return 1;
	}
	int& ref = dp[a][b][c][aim];
	if (ref != -1)
		return ref;

	if (dig[pos] == 1 && pos != len){
		if (aim == 0){
			ans[pos] = 'B';
			ref = dfs(a, b - 1, c, 2, pos - 1);
			if (ref == 1)
				return ref;
			ans[pos] = 'C';
			ref = dfs(a, b, c - 1, 1, pos - 1);
			if (ref == 1)
				return ref;
		}
		else if (aim == 1){
			ans[pos] = 'A';
			ref = dfs(a - 1, b, c, 2, pos - 1);
			if (ref == 1)
				return ref;
			ans[pos] = 'C';
			ref = dfs(a, b, c - 1, 0, pos - 1);
			if (ref == 1)
				return ref;
		}
		else {
			ans[pos] = 'A';
			ref = dfs(a - 1, b, c, 1, pos - 1);
			if (ref == 1)
				return ref;
			ans[pos] = 'B';
			ref = dfs(a, b - 1, c, 0, pos - 1);
			if (ref == 1)
				return ref;

		}
	}
	else{
		if (aim == 0){
			ans[pos] = 'A';
			ref = dfs(a - 1, b, c, aim, pos - 1);
		}
		else if (aim == 1){
			ans[pos] = 'B';
			ref = dfs(a, b - 1, c, aim, pos - 1);

		}
		else{
			ans[pos] = 'C';
			ref = dfs(a, b, c - 1, aim, pos - 1);
		}
	}
	return ref;

}

class ClassicTowers {
public:
	string findTowers(long long k, vector <int> count) {
		K = k;

		int sum = 0;
		for (int i = 0; i < count.size(); ++i)
			sum += count[i];
		for (int i = 0; i < sum-1; ++i){
			dig[i] = k % 2;
			k /= 2;
		}
		if (k)
			return "";
		memset(dp, -1, sizeof(dp));
		ans.resize(sum);
		len = sum - 1;
		for (int i = 0; i < ans.size(); ++i)
			ans[i] = '-';
		for (int i = 0; i < 3; ++i){
			if (dfs(count[0], count[1], count[2], i, sum - 1)){
				return ans;
			}
		}
		return "";
	}
};


#if 0
int main(){
	vector<int> p({ 0, 1, 2 });
	ClassicTowers so;
	cout << so.findTowers(7, p) << endl;















	return 0;
}
#endif



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
