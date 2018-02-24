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
int T, N, M;
int sr, sc, tr, tc;
string mmp[510];
struct Node{
	int x, y, d, kill;
	Node(int _a, int _b, int _c = -1, int _d = -1){
		x = _a;
		y = _b;
		d = _c;
		kill = _d;

	}
	Node(){}
	bool operator<(const Node& p)const{
		if (kill != p.kill)
			return kill>p.kill;
		return d > p.d;

	}

};
vector<Node> vi[510][510];
vector<Node> temp;
short kill[510][510];
short trap[510][510];
struct T{
	int d, kill;
}data[510][510];

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M &&mmp[x][y] !='#';
}

void Init(){
	for (int i = 0; i < 510; ++i)
	for (int j = 0; j < 510; ++j){
		vi[i][j].clear();
		data[i][j].d = data[i][j].kill = (1 << 22);
	}
	memset(kill, 0, sizeof(kill));
	memset(trap, 0, sizeof(trap));
}

void build(){
	int x, y;
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j){
		if (mmp[i][j] >= 'A'&&mmp[i][j] <= 'Z'){
			for (int k = 0; k < 4; ++k){
				x = i + dirs[k][0];
				y = j + dirs[k][1];
				if (IN(x, y) ){
					kill[x][y] += mmp[i][j] - 'A' + 1;
				}
			}
			//	mmp[i][j] = '#';
		}
		else if (mmp[i][j] >= 'a' && mmp[i][j] <= 'z'){
			trap[i][j] = mmp[i][j] - 'a' + 1;
		}
	}

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j){
		if ( mmp[i][j] == '#' || mmp[i][j] >= 'A'&&mmp[i][j] <= 'Z')
			continue;
		for (int k = 0; k < 4; ++k){
			x = i + dirs[k][0];
			y = j + dirs[k][1];
			if (IN(x, y)){
				vi[i][j].push_back(Node(x, y, 1, kill[x][y] + trap[x][y]));
			}
		}

	}

	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j){
		if (mmp[i][j] >= 'A'&&mmp[i][j] <= 'Z'){
			temp.clear();
			for (int k = 0; k < 4; ++k){
				x = i + dirs[k][0];
				y = j + dirs[k][1];
				if (IN(x, y) ){
					temp.push_back(Node(x, y));
				}
			}
			for (int k1 = 0; k1 < temp.size(); ++k1)
			for (int k2 = 0; k2 < temp.size(); ++k2){
				if (k1 == k2)
					continue;
				short t_kill = 0;
				for (int k = 0; k < 4; ++k){
					x = temp[k2].x + dirs[k][0];
					y = temp[k2].y + dirs[k][1];
					if (IN(x, y) &&abs(x-temp[k1].x)+abs(y-temp[k1].y) != 1 && mmp[x][y] >= 'A' && mmp[x][y] <= 'Z'){
						t_kill += mmp[x][y] - 'A' + 1;
					}
				}
				vi[temp[k1].x][temp[k1].y].push_back(Node(temp[k2].x, temp[k2].y, 2, t_kill + trap[temp[k2].x][temp[k2].y]));
			}

			
		}
	}


}

void dijstra(){
	priority_queue<Node> pq;
	data[sr][sc].d = data[sr][sc].kill = 0;
	pq.push(Node(sr, sc, 0, 0));
	while (!pq.empty()){
		Node u = pq.top(), v;
		pq.pop();
		for (int i = 0; i < vi[u.x][u.y].size(); ++i){
			v = vi[u.x][u.y][i];
			v.d += u.d;
			v.kill += u.kill;
			if (v.kill < data[v.x][v.y].kill || v.kill == data[v.x][v.y].kill && v.d < data[v.x][v.y].d){
				data[v.x][v.y].d = v.d;
				data[v.x][v.y].kill = v.kill;
				pq.push(v);
			}
		}
	}
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T-- > 0){
		Init();
		cin >> N >> M;
		cin >> sr >> sc >> tr >> tc;
		sr--;
		sc--;
		tr--;
		tc--;
		for (int i = 0; i < N; ++i)
			cin >> mmp[i];
		
		build();
		dijstra();
		cout << data[tr][tc].kill << " " << data[tr][tc].d << endl;
	}


	return 0;
}