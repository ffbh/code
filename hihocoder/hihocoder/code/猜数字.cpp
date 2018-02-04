#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int dp[210][210];
int N;
int dfs(int l, int r){
	if (dp[l][r] != -1)
		return dp[l][r];
	int mmin, ret;
	if (l == r)
		return 0;
	else if (l + 1 == r)
		return l;
	else{
		mmin = (1 << 30);
		ret = l + dfs(l + 1, r);
		if (mmin > ret)
			mmin = ret;
		ret = dfs(l, r - 1) + r;
		if (mmin > ret)
			mmin = ret;
		for (int i = l + 1; i < r; ++i){
			ret = max(dfs(l, i - 1) , dfs(i + 1, r)) + i;
			if (mmin > ret)
				mmin = ret;
		}
	}
	return dp[l][r] = mmin;

}
int main(){
	ifstream in("C:\\input.txt");
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << dfs(1, N) << endl;
	return 0;
}