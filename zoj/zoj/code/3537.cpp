#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, P;
struct Node{
	int x, y;
	bool operator<(const Node& p)const{
		if (x != p.x)
			return x < p.x;
		return y < p.y;
	}
}data[310];
int dp[310][310];

int chaji(const Node& a,const Node& b,const Node& c){
	return  ((a.x - c.x)*(b.y - c.y)
			- (a.y - c.y)*(b.x - c.x));
}

bool cmp(const Node& a, const Node& b){
	return chaji(a, b, data[0]) < 0;
}

int COST(int i, int j, int k){
	int ret = 0;
	if (i+1 != k)
		ret += (abs(data[i].x + data[k].x)*abs(data[i].y + data[k].y)) % P;
	if (k+1 != j)
		ret += (abs(data[j].x + data[k].x)*abs(data[j].y + data[k].y)) % P;
	return ret;
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> P){
		cin >> data[0].x >> data[0].y;
		for (int i = 1; i < N; ++i){
			cin >> data[i].x >> data[i].y;
			if (data[i] < data[0])
				swap(data[0], data[i]);
		}
		if (N == 3){
			cout << 0 << endl;
			continue;
		}
		sort(data+1, data + N, cmp);
		bool flag = 1;
		for (int i = 0; i < N;++i)
		if (chaji(data[(i+1)%N], data[(i + 2)%N],data[i])>0){
			flag = 0;
			break;
		}
		if (!flag){
			cout << "I can't cut." << endl;
			continue;
		}
		memset(dp, 0, sizeof(dp));
		for (int len = 2; len < N;++len)
		for (int i = 0; i < N-len; ++i){
			int j = i + len;
			dp[i][j] = (1 << 28);
			for (int k = i+1; k < j; k++){
				int cost = dp[i][k] + dp[k][j] + COST(i, j, k);
				if (dp[i][j] > cost)
					dp[i][j] = cost;
			}
		}
		cout << dp[0][N - 1] << endl;
	}
	return 0;
}



