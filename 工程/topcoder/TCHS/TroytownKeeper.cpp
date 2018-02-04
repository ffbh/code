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
using namespace std;
struct Node{
	int x, y;
	Node(int a, int b){
		x = a;
		y = b;
	}
	Node(){}
};
bool mmp[60][60];
bool vis[60][60];
int N, M;

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

bool IN(Node& p){
	return p.x >= 0 && p.x <= N&&p.y >= 0 && p.y <= M;
}


class TroytownKeeper{
public:
	int bfs(){
		queue<Node> qn;
		qn.push(Node(0, 0));
		int ans = 0;
		while (!qn.empty()){
			Node u = qn.front(), v;
			qn.pop();

			for (int i = 0; i < 4; ++i){
				v.x = u.x + dirs[i][0];
				v.y = u.y + dirs[i][1];
				if (IN(v) && !vis[v.x][v.y]){
					if (mmp[v.x][v.y] == 1){
						ans++;
					}
					else{
						vis[v.x][v.y] = 1;
						qn.push(v);
					}

				}
			}
		}
		return ans;

	}


	int limeLiters(vector <string> maze){
		memset(mmp,0, sizeof(mmp));
		memset(vis, 0, sizeof(vis));
		N = maze.size();
		M = maze[0].size();
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j)
			mmp[i + 1][j + 1] = (maze[i][j] == '#');
		N++;
		M++;

		return bfs();



	}




};





int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;

















	return 0;
}





