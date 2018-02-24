#include <iostream> 
#include <string> 
#include <fstream> 
#include <queue> 
using namespace std;
struct Node{ short x, y; };
bool map[10300][1010];
bool key[110][110];
bool vis[10300][1010];
short R, C, N, M, deep;
short dirs[3][2] = { 0, 1, 0, -1, 1, 0 };
bool IN(Node& p){
	return p.x >= 0 && p.x < R + N&&p.y >= 0 && p.y + C <= M;
}
bool OK(Node& p){
	for (int i = 0; i < R; ++i)
	for (int j = 0; j < C; ++j)
	if (key[i][j] & map[p.x + i][p.y + j])
		return 0; return 1;
}
void bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	for (int i = 0; i < M; ++i)
	if (IN(Node{ 0, i })){
		vis[0][i] = 1;
		qn.push(Node{ 0, i });
	}
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (temp1.x>deep){
			deep = temp1.x;
			if (deep == R + N - 1)
				return;
		}
		for (int i = 0; i < 3; ++i){
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y] && OK(temp2)){
				vis[temp2.x][temp2.y] = 1; qn.push(temp2);
			}
		}
	}
}
char s[1100];
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	scanf("%d", &T);
	while (T--){
		deep = 0;
		scanf("%d%d", &R, &C);
		for (int i = 0; i < R; ++i){
			for (int j = 0; j < 1010; ++j)
				vis[i][j] = map[i][j] = 0;
			//    string s;
			scanf("%s", s);
			for (int j = 0; j < C; ++j) {
				if (s[j] == '#')
					key[i][j] = 1;
				else key[i][j] = 0;
			}
		}
		scanf("%d%d", &N, &M);
		for (int i = R; i < R + N; ++i){
			//    cin >> s;
			scanf("%s", s);
			for (int j = 0; j < M; ++j){
				vis[i][j] = 0;
				if (s[j] == '#') map[i][j] = 1;
				else map[i][j] = 0;
			}
		}
		bfs();
		if (deep == R + N - 1)
			printf("The key can fall through.\n");
		else
			printf("The key falls to depth %d.\n", deep);
	} return 0;
}