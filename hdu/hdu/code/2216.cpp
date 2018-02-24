#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
int N, M;
bool map[21][21];
int vis[21][21][21][21];
int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
struct Point{
	int x, y;
};
struct Node{
	Point S, Z;
	int step;
}St;

/*bool Ok(Node& temp){
if (temp.S.x == temp.Z.x)
return abs(temp.S.y - temp.Z.y) <= 1;
else if (temp.S.y == temp.Z.y)
return abs(temp.S.x - temp.Z.x) <= 1;
else
return 0;
}*/
bool Ok(Node& temp)
{
	int distance = abs(temp.S.x - temp.Z.x) + abs(temp.S.y - temp.Z.y);
	if (distance == 0 || distance == 1)
		return true;
	return false;
}

bool IN(int x, int y){
	return x >= 0 && x < N&&y >= 0 && y < M&&!map[x][y];
}

bool Move(Point& p, int i){
	int x, y;
	x = p.x + dirs[i][0];
	y = p.y + dirs[i][1];
	if (IN(x, y) && !map[x][y]){
		p.x = x;
		p.y = y;
		return 1;
	}
	return 0;
}

int bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	memset(vis, 0, sizeof(vis));
	vis[St.S.x][St.S.y][St.Z.x][St.Z.y] = 1;
	qn.push(St);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (Ok(temp1))
			return temp1.step;
		temp1.step++;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			/*if (!Move(temp2.Z, i))
			continue;
			Move(temp2.S, (i + 2) % 4);*/
			temp2.Z.x += dirs[i][0];
			temp2.Z.y += dirs[i][1];
			if (!IN(temp2.Z.x, temp2.Z.y))
				continue;
			temp2.S.x -= dirs[i][0];
			temp2.S.y -= dirs[i][1];
			if (!IN(temp2.S.x, temp2.S.y)){
				temp2.S.x += dirs[i][0];
				temp2.S.y += dirs[i][1];
			}
			if (!vis[temp2.S.x][temp2.S.y][temp2.Z.x][temp2.Z.y]){
				vis[temp2.S.x][temp2.S.y][temp2.Z.x][temp2.Z.y] = 1;
				qn.push(temp2);
			}
		}
	}
	return -1;
}




int main(){
	//ifstream in("C:\\temp.txt");
	while (~scanf("%d%d",&N,&M)){
		St.step = 0;
		for (int i = 0; i < N; ++i){
			char temp[30];
			scanf("%s", temp);
			for (int j = 0; j < M; ++j)
			if (temp[j] == 'X')
				map[i][j] = 1;
			else if (temp[j] == '.')
				map[i][j] = 0;
			else if (temp[j] == 'Z'){
				St.Z.x = i;
				St.Z.y = j;
				map[i][j] = 0;
			}
			else{
				St.S.x = i;
				St.S.y = j;
				map[i][j] = 0;
			}
		}
		int step = bfs();
		if (step >= 0)
			cout << step << endl;
		else
			cout << "Bad Luck!" << endl;
	}
	return 0;
}
