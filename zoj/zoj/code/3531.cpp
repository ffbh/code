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
#include <cassert>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  

int n, m;
char str[20][20];
char c;
bool mmp[20][20];
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
string fx = "SENW";


int Kight_x, Kight_y, A_x, A_y, B_x, B_y;
pii E1, E2;
vector<pii> M;
int memory_piece[20][20];


//int dp[25][11][11][11][11][35];
bool vis[50][11][11][11][11][65];
vector<pii> pace;

bool IN(int x,int y){
	return x >= 0 && x < n&&y >= 0 && y < m&&mmp[x][y] == 0;
}

bool IN(pii a){
	return IN(a.first, a.second);
}
void Init(){
	memset(mmp, 0, sizeof(mmp));
	E1.first = -1;
	M.clear();
	pace.clear();
	memset(memory_piece, 0, sizeof(memory_piece));
	memset(vis, 0, sizeof(vis));
}

void getCycle(){
	int D;
	for (int i = 0; i < 4;++i)
	if (fx[i] == c){
		D = i;
		break;
	}
	int x = Kight_x, y = Kight_y, nowD = D;
	bool ok = 0;
	while (1){
	//	cout << x << " " << y << endl;
		if (ok == 1){
			if (x == Kight_x && y == Kight_y && nowD == D){
				break;
			}
		}
		ok = 1;
		pace.push_back(mp(x, y));
		int nx = x + dirs[nowD][0];
		int ny = y + dirs[nowD][1];
		if (IN(nx, ny)){
			x = nx;
			y = ny;
		}
		else{
			nowD = (nowD + 2) % 4;
		}
	}
}

void input(){
	//in >> n >> m;
	for (int i = 0; i < n; ++i)
		in >> str[i];
	in >> c;
}

void ps_map(){
	for (int i = 0; i < n;++i)
	for (int j = 0; j < m; ++j){
		if (str[i][j] == '*'){

		}
		else if (str[i][j] == 'R'){
			mmp[i][j] = 1;
		}
		else if (str[i][j] == 'K'){
			Kight_x = i;
			Kight_y = j;

		}
		else if (str[i][j] == 'A'){
			A_x = i;
			A_y = j;
		}
		else if (str[i][j] == 'B'){
			B_x = i;
			B_y = j;
		}
		else if (str[i][j] == 'E'){
			if (E1.first == -1){
				E1 = mp(i, j);
			}
			else{
				E2 = mp(i, j);
			}


		}
		else{// M
			M.push_back(mp(i, j));

		}
	}


}



struct Node{
	int m;
	pii A, B;
	int key;
	int val;
	bool update() const{
		if (!vis[m][A.first][A.second][B.first][B.second][key]){
			vis[m][A.first][A.second][B.first][B.second][key] = 1;
//			dp[m][A.first][A.second][B.first][B.second][key] = val;
			return 1;
		}
		return 0;
	}
	bool dead()const {
		return pace[m] == A || pace[m] == B;
	}
	bool end()const{
		return A == E1 && B == E2 || A == E2&&B == E1;

	}
	bool operator!=(const Node& p)const{
		return m != p.m || A != p.A || B != p.B || key != p.key;
	}

};
//Node pre[50][11][11][11][11][65];

bool can_move(int m,pii pos){
	return pace[m] != pos;
//	return 1;
}

//void dfs(Node now,Node start){
//	if (now !=  start)
//		dfs(pre[now.m][now.A.first][now.A.second][now.B.first][now.B.second][now.key],start);
//	cout << now.A.first << " " << now.A.second << " " << now.B.first << " " << now.B.second << endl;
//}

int bfs(){
	queue<Node> Q;
	Node S;
	S.m = 0;
	S.A = mp(A_x, A_y);
	S.B = mp(B_x, B_y);
	S.key = 0;
	S.val = 0;
	S.update();
	Q.push(S);
	
	while (!Q.empty()){
		const Node u = Q.front();
		Node v;
		Q.pop();
	//	assert(u.m < 25 && IN(u.A) && IN(u.B) && u.key < (1 << M.size()));
	//	cout << u.A.first << " " << u.A.second << endl;
		

		if (u.end()){
			if (u.key == (1 << M.size()) - 1){
		//		dfs(u,S);

				return u.val;
			}
			continue;
		}
		if (u.dead())
			continue;

		for (int i = 0; i < 4; ++i){
			int j = (i + 2) % 4;
			v.m = (u.m + 1) % pace.size();
			v.A = mp(u.A.first + dirs[i][0], u.A.second + dirs[i][1]);
			v.val = u.val + 1;
			if (IN(v.A.first, v.A.second) && can_move(u.m, v.A)  && v.A != u.B){//A cannot move to B
				v.key = u.key | memory_piece[v.A.first][v.A.second];
				v.B = mp(u.B.first + dirs[j][0], u.B.second + dirs[j][1]);
				if (IN(v.B.first, v.B.second) && can_move(u.m, v.B) && v.B != v.A){
					//already move 
				}
				else{
					v.B = u.B;
				}
				if ( v.update()){
	//				pre[v.m][v.A.first][v.A.second][v.B.first][v.B.second][v.key] = u;
					Q.push(v);
				}
			}
		}
	}
	return -1;
}


int main(){

	while (in >> n >> m){
		Init();
		input();
		ps_map();
		for (int i = 0; i < M.size(); ++i){
			memory_piece[M[i].first][M[i].second] = 1 << i;
		}
		getCycle();
		printf("%d\n", bfs());

	}
	


	return 0;
}





