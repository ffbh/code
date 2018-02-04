#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int data[10010];
int ans[10010];
int Hash[10010];


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		memset(data, 0, sizeof(data));
		int M = N;
		N = N*(N - 1) / 2;
		int MAX;
		cin >> MAX;
		data[MAX]++;
		for (int i = 2; i <= N; ++i){
			int t;
		//	in >> t;
			scanf("%d", &t);
			data[t]++;
		}
		for (int i = 1; i < MAX; ++i){
			ans[1] = i;
			int u;
			memcpy(Hash, data, sizeof(Hash));
			u = 2;
			while (u <= M){
				for (int k = 0; k < 10010; ++k)
				if (Hash[k]){
					ans[u] = k - i;
					break;
				}
				int j;
				for (j = 1; j < u; ++j)
				if (Hash[ans[j] + ans[u]])
					Hash[ans[j] + ans[u]]--;
				else
					break;
				if (j<u)
					break;
				u++;
			}
			if (u > M)
				break;
		}
		sort(ans + 1, ans + M + 1);
		for (int i = 1; i < M; ++i)
			printf("%d ", ans[i]);
		printf("%d\n", ans[M]);
	}
	return 0;
}