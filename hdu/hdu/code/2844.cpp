#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Node{
	int v, count;
}data[110];
bool dp[100010];

int main(){
	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M&&N + M){
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int ans = 0;
		for (int i = 0; i < N; ++i)
		//	in >> data[i].v;
			scanf("%d", &data[i].v);
		for (int i = 0; i < N; ++i)
		//	in >> data[i].count;
			scanf("%d", &data[i].count);
		for (int i = 0; i < N; ++i){
			int num = data[i].count;
			int k = 1;
			int v;
			while (k < num){
				v = k*data[i].v;
				for (int i = M; i >= v;--i)
				if (dp[i - v]){
					if (!dp[i]){
						dp[i] = 1;
						ans++;
					}
				}
				num -= k;
				k *= 2;
			}
			if (num){
				k = num;
				v = k*data[i].v;
				for (int i = M; i >= v; --i)
				if (dp[i - v]){
					if (!dp[i]){
						dp[i] = 1;
						ans++;
					}
				}
				num -= k;
				k *= 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}