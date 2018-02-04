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
#include <set>
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;
#define INF (1<<29)
int n, arr[1010], sum[1010];
int dp[1010][1010];

void input(){
	in >> n;

	for (int i = 1; i <= n; ++i){
		in >> arr[i];

	}


}

int dfs(int l,int r){
	int& ref = dp[l][r];
	if (ref != INF)
		return ref;
	ref = -INF;


	if (l == r)
		return ref = arr[l];
	else{
		int L = arr[l] + sum[r] - sum[l] - dfs(l + 1, r);
		int R = arr[r] + sum[r - 1] - sum[l - 1] - dfs(l, r - 1);
		return ref = max(L, R);
	}

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		sum[0] = 0;
		for (int i = 1; i <= n; ++i)
			sum[i] = sum[i - 1] + arr[i];

		for (int i = 0; i < 1010;++i)
		for (int j = 0; j < 1010; ++j)
			dp[i][j] = INF;

		cout << dfs(1, n) << endl;

















	}


	return 0;
}





