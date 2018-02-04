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
using namespace std;

double dp[110][110];
double p;
bool vis[110][110];
double dp2[110][110][110];
bool vis2[110][110][110];
double p2;
double slove(int time, int h, int k);
double dfs(int h, int k){
	if (h == 0){
		return 1;
	}
	if (k == 0){
		return 0;
	}
	if (vis[h][k])
		return dp[h][k];
	vis[h][k] = 1;
	double t1 = dfs(h - 1, k)*(1 - p) + dfs(h, k - 1)*p;
	double t2 = slove(k, h, k);
	return dp[h][k] = min(t1, t2);
}

double slove(int time, int h, int k){
	if (time == 0){
		return h == 0;
	}
	if (h == 0){
		return 1;
	}
	if (k == 0){
		return 0;
	}
	if (vis2[time][h][k]){
		return dp2[time][h][k];
	}
	vis2[time][h][k] = 1;
	return dp2[time][h][k] = slove(time - 1, h - 1, k)*p2 + slove(time - 1, h, k - 1)*(1 - p2);

}
class Dragon {
public:
	double winFight(int h, int k, int probDragon, int probKnight) {
		p = 0.01*probDragon;
		p2 = probKnight*0.01;
		memset(vis, 0, sizeof(vis));
		memset(vis2, 0, sizeof(vis2));
		return  dfs(h, k);
	}
};



/*int main(){

Dragon so;
cout<<so.winFight(39, 93, 80, 43)<<endl;
















return 0;
}


*/