#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
map<unsigned int, int> dp;
unsigned int p[40];
int MIN(int a, int b){
	return min(a, b);
}
void Init(){
	p[0] = 1;
	dp[p[0]] = 1;
	for (int i = 1; i < 32; ++i){
		p[i] = p[i - 1] << 1;
		dp[p[i]] = 1;
	}
}
int dfs(unsigned int k){
	if (dp.count(k))
		return dp[k];
	int L = lower_bound(p, p + 32, k) - p -1;
	int R = L + 1;
	return dp[k] = min(dfs(k - p[L]), dfs(p[R] - k)) + 1;
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	unsigned int N;
	cin >> N;
	cout << dfs(N) << endl;
	return 0;
}