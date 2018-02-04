#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
int M, P;
struct Node{
	int a, b;
}data[310];

int dp[310][1010];

int dfs(int pos, int rest){
	if (dp[pos][rest] != -1)
		return dp[pos][rest];
	if (pos == P + 1)
		return 1;
	if (rest != M)
		dp[pos][rest] = dfs(pos, M) + 1;
	else
		dp[pos][rest] = 1 << 20;
	int sum_a, sum_b, ret;
	sum_a = sum_b = 0;
	for (int i = pos; i <= P; ++i){
		if (sum_a + data[i].a <= M && sum_b + data[i].b <= rest){
			sum_a += data[i].a;
			sum_b += data[i].b;
			ret = dfs(i + 1, M - sum_a) + 1;
			if (ret < dp[pos][rest])
				dp[pos][rest] = ret;
		}
		else
			break;
	}
	return dp[pos][rest];
}

int main(){
	ifstream in("C:\\input.txt");

	cin >> M >> P;
	for (int i = 1; i <= P; ++i)
		cin >> data[i].b >> data[i].a;
	memset(dp, -1, sizeof(dp));
	cout << dfs(1, M) + 1 << endl;

	return 0;
}