#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;

typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back

#define INF ((LL)1e17)
int N;
LL K;
LL dp[5010][5010][2];
struct Node{
	int c, d, f;
}data[5010];
vector<int> vi[5010];

int size[5010];




void dfs(int p){
	dp[p][0][0] = dp[p][0][1] = 0;
	dp[p][1][0] = data[p].c;
	dp[p][1][1] = data[p].c - data[p].d;

	size[p] = 1;
	for (int son : vi[p]){
		dfs(son);
		
		for (int i = size[p] + size[son]; i >= 1; --i){
			for (int j = 1; j <= size[son]; ++j){
				if (i - j >= 0)
					dp[p][i][0] = min(dp[p][i][0], dp[p][i - j][0] + dp[son][j][0]);
				if (i>1 && i - j >= 1)
					dp[p][i][1] = min(dp[p][i][1], dp[p][i - j][1] + min(dp[son][j][0], dp[son][j][1]));
			}
		}	
		size[p] += size[son];



	}





}



int main(){
	ifstream in("C:\\input.txt");
//	istream& in = cin;

	for (int i = 0; i < 5010;++i)
	for (int j = 0; j < 5010;++j)
	for (int k = 0; k < 2; ++k)
		dp[i][j][k] = INF;

	in >> N >> K;
	in >> data[1].c >> data[1].d;
	data[1].c -= data[1].d;
	data[1].d = 0;
	for (int i = 2; i <= N; ++i){
		in >> data[i].c >> data[i].d >> data[i].f;
	//	scanf("%d%d%d", &data[i].c, &data[i].d, &data[i].f);
	}

	for (int i = 2; i <= N; ++i){
		vi[data[i].f].push_back(i);
	}

	dfs(1);
	int ans;
	for (int i = N; i >= 0;--i)
	if (dp[1][i][0] <= K || dp[1][i][1] <= K){
		ans = i;
		break;
	}

	

	cout << ans << endl;









	return 0;
}





