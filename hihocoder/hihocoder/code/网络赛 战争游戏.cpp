#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
int  N, M, C, E;
struct Map{
	int G, GR;
}map[110][110];
struct Character{
	int HP, AT, MV, AD1, AD2, x, y, GR;
	bool dead;
}data[110];
struct Node{
	int x, y,d;
	bool operator<(const Node& p)const{
		return d > p.d;
	}
};
char s[100];
bool vis[110][110];
int nowG, nowID, moveX, moveY, d, j, dis;
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= M;
}
int Move(){
	priority_queue<Node> pq;
	memset(vis, 0, sizeof(vis));
	Node u, v;
	u.x = data[nowID].x;
	u.y = data[nowID].y;
	vis[u.x][u.y] = 1;
	u.d = 0;
	pq.push(u);
	while (!pq.empty()){
		u = pq.top();
		pq.pop();
		if (u.x == moveX && u.y == moveY){
			return u.d;
		}
		for (int i = 0; i < 4; ++i){
			v.x = u.x + dirs[i][0];
			v.y = u.y + dirs[i][1];
			if (IN(v) && !vis[v.x][v.y] &&map[v.x][v.y].GR == -1 ){
				vis[v.x][v.y] = 1;
				v.d = u.d + map[v.x][v.y].G;
				if (v.d <= data[nowID].MV){
					for (int j = 0; j < 4; ++j){
						Node t;
						t.x = v.x + dirs[j][0];
						t.y = v.y + dirs[j][1];
						if (IN(t) && map[t.x][t.y].GR >= 0 && map[t.x][t.y].GR != data[nowID].GR){
							v.d = data[nowID].MV;
							break;
						}
					}
					pq.push(v);
				}
			}
		}
	}
	return -1;
}




int main(){
   // ifstream in("C:\\input.txt");

	ios::sync_with_stdio(false);
	while (cin >> N >> M >> C >> E){
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j){
			cin >> map[i][j].G;
			map[i][j].GR = -1;
		}
		for (int i = 1; i <= C; ++i){
			cin >> data[i].HP >> data[i].AT >> data[i].MV
				>> data[i].AD1 >> data[i].AD2 >> data[i].x >> data[i].y >> data[i].GR;
			data[i].dead = 0;
			map[data[i].x][data[i].y].GR = data[i].GR;
		}
		while (E--){
			cin >> s;
			switch (s[0]){
			case 'A':
				if (s[1] == 'c'){
					cin >> s >> s >> nowID;
				}
				else{
					int attackedId;
					cin >> attackedId;
					dis = abs(data[nowID].x - data[attackedId].x) + abs(data[nowID].y - data[attackedId].y);
					if ( data[attackedId].dead || dis<data[nowID].AD1 || dis>data[nowID].AD2){
						printf("INVALID\n");
					}
					else{
						if (data[attackedId].HP <= data[nowID].AT)
							printf("INVALID\n");
						else{
							data[attackedId].HP -= data[nowID].AT;
							printf("%d\n", data[attackedId].HP);
						}
					}
				}
				break;
			case 'D':
				int attackedId;
				cin >> s >> attackedId;
				dis = abs(data[nowID].x - data[attackedId].x) + abs(data[nowID].y - data[attackedId].y);
				if ( data[attackedId].dead || dis<data[nowID].AD1 || dis>data[nowID].AD2){
					printf("INVALID\n");
				}
				else{
					if (data[attackedId].HP > data[nowID].AT)
						printf("INVALID\n");
					else{
						data[attackedId].dead = 1;
						map[data[attackedId].x][data[attackedId].y].GR = -1;
						data[attackedId].HP -= data[nowID].AT;
						printf("%d\n", data[attackedId].HP);
					}
				}
				break;
			case 'M':
				cin >> s >> s;
				moveX = moveY = 0;
				for (j = 1; s[j] != ','; ++j)
					moveX = moveX * 10 + s[j] - '0';
				for (j++; s[j] != ')'; ++j)
					moveY = moveY * 10 + s[j] - '0';
				//	cout << moveX << " " << moveY << endl;
				d = Move();
				if (d == -1){
					printf("INVALID\n");
				}
				else{
					printf("%d\n", data[nowID].MV - d);
					if (moveX != data[nowID].x || moveY != data[nowID].y){
						map[data[nowID].x][data[nowID].y].GR = -1;
						map[moveX][moveY].GR = data[nowID].GR;
						data[nowID].x = moveX;
						data[nowID].y = moveY;
					}
				}
				break;
			case 'R':
				cin >> s >> nowG;

				break;
			default:
				cout << "error" << endl;
				break;
			}

		}
	}

	return 0;
}

/*
5 5 2 3
1 11 1 4 4
1 11 1 2 4
1 11 1 1 2
1 1 1 7 3
1 1 1 6 1
20 10 10 1 2 1 1 0
19 10 5 1 2 2 1 1
Round of 0
Action of character 1
Move to (1,1)

*/