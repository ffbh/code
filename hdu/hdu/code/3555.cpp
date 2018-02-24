#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
long long dp[30][10];


bool ok(int n){
	int pre = -1;
	while (n){
		int now = n % 10;
		n /= 10;
		if ( pre == 9 && now == 4)
			return 0;
		pre = now;
	}
	return 1;
}

int baoli(int n){
	int sum = 0;
	for (int i = 1; i <= n; ++i){
		if (!ok(i))
			sum++;
	}

	return sum;
}





void Init(){
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 10; ++i)
		dp[1][i] = 1;
	for (int len = 2; len < 30; ++len){
		for (int i = 0; i < 10; ++i){
			if (i == 4){
				for (int j = 0; j < 9; ++j)
					dp[len][i] += dp[len - 1][j];
			}
			else{
				for (int j = 0; j < 10; ++j)
					dp[len][i] += dp[len - 1][j];
			}
		}
	}
	
}

vector<int> vi;

void getDig(long long n){
	vi.clear();
	while (n){
		vi.push_back(n % 10);
		n /= 10;
	}
	int l = 0, r = vi.size() - 1;
	while (l < r){
		swap(vi[l], vi[r]);
		l++;
		r--;
	}
}

long long dfs(int pos, int pre, int len){
	long long sum = 0;
	for (int i = 0; i < vi[pos]; ++i){
		if (pre == 4 && i == 9)
			continue;
		sum += dp[len][i];
	}
	if (len != 1){
		if (pre == 4 && vi[pos] == 9){

		}
		else{
			sum += dfs(pos + 1, vi[pos], len - 1);
		}
	}
	else{
		if (pre == 4 && vi[pos] == 9){

		}
		else{
			sum += 1;
		}
	}

	return sum;
}

long long getAns(long long n){
	getDig(n);
	return dfs(0, -1, vi.size());
}


int main(){
	ifstream in("C:\\input.txt");
	Init();
	/*long long aim = 1e18;
	cout << baoli(aim) << endl;
	cout << aim - getAns(aim) + 1 << endl;*/




	int T;
	cin >> T;
	while (T--){
		long long N;
		cin >> N;
		cout << N - getAns(N) + 1 << endl;
	}


	return 0;
}