#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
int N, M;
struct Node{
	int d[12];
	int idx, n;

	void Sort(){
		sort(d, d + n);
	}

	bool operator<(const Node& p)const{
		return d[0] < p.d[0];
	}

	bool ok(Node& p){
		for (int i = 0; i < M;++i)
		if (d[i] >= p.d[i])
			return 0;
		return 1;
	}

}data[50];
int dp[50], pace[50];

void dfs(int p){
	if (p == -1)
		return;
	dfs(pace[p]);
	printf("%d ", data[p].idx);

}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	while (in >> N >> M){
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= N; ++i){
			for (int j = 0; j < M; ++j)
				in >> data[i].d[j];
			data[i].idx = i;
			data[i].n = M;
		}
		for (int i = 1; i <= N; ++i)
			data[i].Sort();

		sort(data + 1, data + N + 1);
		dp[1] = 1;
		pace[1] = -1;
		for (int i = 2; i <= N; ++i){
			dp[i] = 1;
			pace[i] = -1;
			for (int j = 1; j < i; ++j){
				if (data[j].ok(data[i])){
					if (dp[i] < dp[j] + 1){
						dp[i] = dp[j] + 1;
						pace[i] = j;
					}
				}

			}

		}
		int ans = 0, idx;
		for (int i = 1; i <= N; ++i){
			if (ans < dp[i]){
				ans = dp[i];
				idx = i;
			}
		}
		cout << ans << endl;
		dfs(idx);
		cout << endl;
	}
















	return 0;
}