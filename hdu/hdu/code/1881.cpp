#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int dp[5000];
struct Node{
	int a, b, c;
};
bool cmp(const Node& p1, const Node& p2){
	return p1.c < p2.c;
}
Node data[50];

int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N >= 0){
		memset(dp, 0, sizeof(dp));
		int m = 0;
		for (int i = 0; i < N; ++i){
			cin >> data[i].a >> data[i].b >> data[i].c;
			if (m < data[i].c)
				m = data[i].c;
		}
		sort(data, data + N, cmp);
		for (int k = 0; k < N; ++k)
		for (int i = data[k].c; i >= data[k].b; --i)
		if (dp[i] < dp[i - data[k].b] + data[k].a)
			dp[i] = dp[i - data[k].b] + data[k].a;
		else
			dp[i] = dp[i];
		int max = 0;
		for (int i = 0; i <= m; ++i)
		if (dp[i]>max)
			max = dp[i];
		cout << max << endl;
	}
	return 0;
}