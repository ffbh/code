#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
ifstream in("C:\\input.txt");
char str[100010];
bool ok[30][30];
int dp[100010][30];

void initOk(){
	int M;
	cin >> M;
	char inlegal[5];
	while (M--){
		cin >> inlegal;
		ok[inlegal[0]-'a'][inlegal[1]-'a'] = 1;
		ok[inlegal[1]-'a'][inlegal[0]-'a'] = 1;
	}
}

int main(){
	
	int N;
	cin >> N;
	cin >> (str+1);
	initOk();
	for (int i = 1; i <= N; ++i){
		for (char c = 'a'; c <= 'z'; ++c)
			dp[i][c - 'a'] = dp[i - 1][c - 'a'];
		for (char c = 'a'; c <= 'z'; ++c){
			if (!ok[c - 'a'][str[i] - 'a'])
				dp[i][str[i] - 'a'] = max(dp[i][str[i] - 'a'], dp[i - 1][c - 'a'] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < 30;++i)
	if (dp[N][i] > ans)
		ans = dp[N][i];
	cout << N - ans << endl;














	return 0;
}