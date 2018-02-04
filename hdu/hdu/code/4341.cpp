#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
	int x, y, t, v;
	bool operator<(const Node& p)const{
		if (x*p.y == y*p.x){
			return (x*x + y*y) < (p.x*p.x + p.y*p.y);
		}
		return double(x) / y < double(p.x) / p.y;
	}
	bool operator==(const Node& p)const{
		return x*p.y == y*p.x;
	}
}data[210];
vector<int> vi[210];
int dp[40010];


int main(){
	ifstream in("C:\\temp.txt");
	int N, M, num;
	int CASE = 1;
	while (cin >> N >> M){
		num = 0;
		for (int i = 0; i < N; ++i){
			cin >> data[i].x >> data[i].y >> data[i].t >> data[i].v;
			vi[i].clear();
		}
		sort(data, data + N);
		vi[num].push_back(0);
		for (int i = 1; i < N; ++i){
			if (data[i] == data[i - 1]){
				data[i].v += data[i - 1].v;
				data[i].t += data[i - 1].t;
				vi[num].push_back(i);
			}
			else{
				num++;
				vi[num].push_back(i);
			}
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i <= num;++i)
		for (int j = M; j >= 0;--j)
		for (int k = 0; k < vi[i].size(); ++k){
			int index = vi[i][k];
			if (j >= data[index].t&&dp[j] < dp[j - data[index].t] + data[index].v)
				dp[j] = dp[j - data[index].t] + data[index].v;
		}
		printf("Case %d: %d\n", CASE++, dp[M]);
	}
	return 0;
}