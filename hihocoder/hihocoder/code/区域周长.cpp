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

int mmp[110][110], N, M, X , Y;
bool vis[110][110];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
vector<pair<int, int> > all;
bool IN(int x,int y){
	return x >= 0 && x < N&&y >= 0 && y < M;
}

void dfs(int x,int y){
	
	if (IN(x, y) && mmp[x][y] == mmp[X][Y] && !vis[x][y] ){
		vis[x][y] = 1;
		all.push_back(make_pair(x, y));
		for (int i = 0; i < 4; ++i){
			dfs(x + dirs[i][0], y + dirs[i][1]);
		}
	}
}

int main(){
//	ifstream in("C:\\input.txt");
	istream& in = cin;
	all.clear();
	memset(vis, 0, sizeof(vis));
	in >> N >> M >> X >> Y;
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M; ++j)
		in >> mmp[i][j];
	dfs(X, Y);
	int ans = all.size() * 4;
	for (pair<int, int> p : all){
		for (int i = 0; i < 4; ++i){
			int x = p.first + dirs[i][0];
			int y = p.second + dirs[i][1];
			if (IN(x, y) && mmp[x][y] == mmp[X][Y])
				ans--;
		}
	}

	cout << ans << endl;
















	return 0;
}





