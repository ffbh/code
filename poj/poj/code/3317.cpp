#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int Hash[60010];
bool vis[60010];
int map[10][10], N;
bool mark[10][10];
int zero, one, play, ans, ansx, ansy;
struct Node{
	int x, y;
	Node(int _x, int _y){
		x = _x;
		y = _y;
	}
};
vector<Node> vn;

void Init(){
	vn.clear();
	memset(vis, 0, sizeof(vis));
	zero = one = 0;
}

int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < N;
}
int count(int x,int y){
	int sum = 0;
	mark[x][y] = 1;
	for (int i = 0; i < 4; ++i){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (IN(nx, ny) && !mark[nx][ny] && map[x][y] == map[nx][ny]){
			sum += count(nx, ny);
		}
	}
	return sum + 1;
}


int getHash(){
	int h = 0;
	for (int i = 0; i < vn.size(); ++i){
		h = h * 3 + map[vn[i].x][vn[i].y];
	}
	return h;
}

int dfs(int f,int num,bool choose){
	int h = getHash();
	if (vis[h]){
		return Hash[h];
	}
	vis[h] = 1;


	if (num == 0){
		memset(mark, 0, sizeof(mark));
		int O, Z;
		O = Z = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j){
			if (!mark[i][j]){
				int n = count(i, j);
				if (map[i][j] == 0){
					Z = max(Z, n);
				}
				else{
					O = max(O, n);
				}
			}
		}
		if (play == 0){
			
	
			return Hash[h] = Z - O;
		}
		else {
		
			return Hash[h] = O - Z;
		}
	}

	int val = 0;
	if (f == play)
		val = -5555;
	else
		val = 5555;
	for (int i = 0; i < vn.size(); ++i){
		if (map[vn[i].x][vn[i].y] == 2){
			map[vn[i].x][vn[i].y] = f;
			int ret = dfs(1 - f, num - 1,false);
			if (f == play){
				if (val < ret){
					val = ret;
					if (choose){
						ans = val;
						ansx = vn[i].x;
						ansy = vn[i].y;
					}
				}
				
			}
			else{
				val = min(val, ret);
			}
			map[vn[i].x][vn[i].y] = 2;
		}
	}
	return Hash[h] = val;
}


int main(){
	ifstream in("C:\\input.txt");
	
	while (cin >> N && N){
		Init();
		ans = -9999;
		for (int i = 0; i < N; ++i){
			string s;
			cin >> s;
			for (int j = 0; j < N; ++j){
				if (s[j] == '.'){
					map[i][j] = 2;
					vn.push_back(Node(i, j));
				}
				else{
					map[i][j] = s[j] - '0';
					if (map[i][j])
						one++;
					else
						zero++;
				}
			}
		}
		play = zero - one;
		dfs(zero - one, vn.size(),true);
		printf("(%d,%d) %d\n", ansx, ansy, ans);




	}
















	return 0;
}