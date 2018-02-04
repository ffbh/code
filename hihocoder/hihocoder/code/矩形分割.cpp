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
struct Node{
	int x, y, z;
	Node(int a, int b, int c){
		x = a;
		y = b;
		z = c;
	}
};

int N, M;
vector<Node> vn[110][110][4];
bool vis[110][110][4];

int dirs[4][2] = { 1,0,0,1,-1,0,0,-1 };
bool IN(int x,int y){
	return x >= 1 && x <= N&&y >= 1 && y <= M;
}
int num;
void dfs(int x, int y, int z){
	if (vis[x][y][z])
		return;
	num++;
	vis[x][y][z] = 1;
	for (int k = 0; k < vn[x][y][z].size(); ++k){
		dfs(vn[x][y][z][k].x, vn[x][y][z][k].y, vn[x][y][z][k].z);
	}
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	string s;
	getline(cin, s);
	for (int i = 1; i <= N; ++i){
		getline(cin, s);
		for (int j = 1; j <= M; ++j){
			char c = s[j - 1];
			int nx, ny;
			if (c == ' '){
				for (int a = 0; a < 4; ++a)
				for (int b = 0; b < 4; ++b){
					if (a == b)
						continue;
					vn[i][j][a].push_back(Node(i, j, b));
				}

				for (int k = 0; k < 4; ++k){
					nx = i + dirs[k][0];
					ny = j + dirs[k][1];
					if (IN(nx, ny)){
						vn[i][j][k].push_back(Node(nx, ny, (k+2)%4));
					}
				}
			}
			else if (c == '/'){
				vn[i][j][0].push_back(Node(i, j, 1));
				vn[i][j][1].push_back(Node(i, j, 0));
				vn[i][j][2].push_back(Node(i, j, 3));
				vn[i][j][3].push_back(Node(i, j, 2));

				for (int k = 0; k < 4; ++k){
					nx = i + dirs[k][0];
					ny = j + dirs[k][1];
					if (IN(nx, ny)){
						vn[i][j][k].push_back(Node(nx, ny, (k+2)%4));
					}
				}

			}
			else{
				vn[i][j][0].push_back(Node(i, j, 3));
				vn[i][j][1].push_back(Node(i, j, 2));
				vn[i][j][2].push_back(Node(i, j, 1));
				vn[i][j][3].push_back(Node(i, j, 0));
				for (int k = 0; k < 4; ++k){
					nx = i + dirs[k][0];
					ny = j + dirs[k][1];
					if (IN(nx, ny)){
						vn[i][j][k].push_back(Node(nx, ny, (k+2)%4));
					}
				}
			}
		}

	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	for (int j = 1; j <= M; ++j)
	for (int k = 0; k < 4; ++k){
		if (!vis[i][j][k]){
			ans++;
			num = 0;
			dfs(i, j, k);
		//	cout << num << endl;
		}

	}
	cout << ans << endl;



	return 0;
}