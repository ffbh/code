#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <sstream>
using namespace std;
#define ll long long 
ll cnt[1110][110][110];
ll dp[110][110];
int A[110], B[110];
int digit[110];
int N;
const ll mod = 1000000007;
ll getABCCount(int c,int a,int b){
	if (c < 0)
		return 0;
	if (cnt[c][a][b] != -1)
		return cnt[c][a][b];
	if (a == 0 && b == 0)
		return cnt[c][a][b] = (c == 0);
	cnt[c][a][b] = 0;

	if (a){
		for (int i = 0; i < 10; ++i)
			cnt[c][a][b] = (cnt[c][a][b] + getABCCount(c - i,a - 1, b )) % mod;
	}
	else{
		for (int i = 1; i < 10; ++i)
			cnt[c][a][b] = (cnt[c][a][b] + getABCCount(c - i,a, b - 1 )) % mod;
	}
	return cnt[c][a][b];

}

ll dfs(int n, int k){
	if (dp[n][k] != -1)
		return dp[n][k];
	if (n == 0)
		return dp[n][k] = (k == 0);
	dp[n][k] = 0;
	for (int p = 0; p < 110; ++p){
		ll t1 = getABCCount(10 * p + digit[n] - k, A[N - n + 1], B[N - n + 1])%mod;
		ll t2 = dfs(n-1,p)  % mod;
		dp[n][k] = (dp[n][k] + (t1 * t2)%mod)%mod;
		if (n == N){
	//		cout << 10 * p + digit[n] - k << " " << A[N - n + 1] << " " << B[N - n + 1]<<" "<< t1*t2  << endl;
		}
	}
	return dp[n][k];
}






int main(){
	ifstream in("C:\\input.txt");
	
	memset(cnt, -1, sizeof(cnt));
	memset(dp, -1, sizeof(dp));
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	

	string s;
	cin >> s;
	int index = 1;
	for (int i = 0; i < s.length(); ++i){
		if (s[i] == '?'){
			if (s[i + 1] == '?')
				A[index++]++;
			else
				B[index]++;
		}
		else if (s[i] == '+'){
			index = 1;
		}
		else{
			i++;
			N = 0;
			for (; i < s.length(); ++i){
				digit[++N] = s[i] - '0';
			}
			break;
		}
	}

	/*for (int i = 1; i <= 10; ++i)
		cout << A[i] << " ";
	cout << endl;
	for (int i = 1; i <= 10; ++i)
		cout << B[i] << " ";
	cout << endl;
	for (int i = 1; i <= 10; ++i)
		cout << digit[i] << " "; 
	cout << endl;*/
	cout << dfs(N, 0) << endl;
	return 0;
}