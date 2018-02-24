#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define INF (1<<29)
struct Node{
	int  w, v;
}data[1010];
int dp[1010];

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N, V;
		cin >> N >> V;
		for (int i = 0; i < N; ++i)
			cin >> data[i].v;
		for (int i = 0; i < N; ++i)
			cin >> data[i].w;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < N; ++i){
			for (int j = V; j >= data[i].w;--j)
			if (dp[j]<dp[j - data[i].w] + data[i].v)
				dp[j] = dp[j - data[i].w] + data[i].v;
		}
	
		cout << dp[V] << endl;
	}
	return 0;
}