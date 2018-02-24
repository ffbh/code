#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stack>
using namespace std;
struct node{
	int x, y;//保存改node的坐标，输出时用的
	int step;
	int f;//g代表走的step，h代表当前node与终点的距离（忽略障碍物），f=g+h
	bool operator <(const node& kk)const{//优先队列插入时的比较函数
		if (step==kk.step)
			return f > kk.f;
		return step > kk.step;
	}
};
int N, M;


bool IN(const node& kk){//判断node是否越界
	return kk.x >= 0 && kk.x < N&&kk.y >= 0 && kk.y < M;
}

struct Point{
	int x, y;
};

int dirs[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };//可以走的四个方向
int map[110][110];
bool vis[110][110];
Point pace[110][110];
int Time;

int Astar(){
	priority_queue<node> pn;
	Point pre;
	node temp1, temp2;
	temp1.x = N-1;
	temp1.y = M-1;
	temp1.step = map[N-1][M-1]-1;
	vis[temp1.x][temp1.y] = 1;
	pn.push(temp1);
	while (!pn.empty()){
		temp1 = pn.top();
		pn.pop();
		pre.x = temp1.x;
		pre.y = temp1.y;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (temp2.x == 0 && temp2.y == 0){
				pace[temp2.x][temp2.y] = pre;
				return temp2.step + map[temp2.x][temp2.y];
			}
			if (IN(temp2) && !vis[temp2.x][temp2.y]&&map[temp2.x][temp2.y]!=0){
				vis[temp2.x][temp2.y] = 1;
				temp2.step += map[temp2.x][temp2.y];
				pace[temp2.x][temp2.y] = pre;
				pn.push(temp2);
			}
		}
	}
	return -1;
}

void Print_Pace(const Point& p){
	Point pre = pace[p.x][p.y];
	bool flag = 1;
	if (pre.x == 0 && pre.y == 0)
		flag = 0;
	if (map[p.x][p.y] == 1){
		if (flag)
			printf("%ds:(%d,%d)->(%d,%d)\n", Time++, p.x, p.y, pre.x, pre.y);
	}
	else {
		for (int i = 0; i < map[p.x][p.y] - 1; ++i)
			printf("%ds:FIGHT AT (%d,%d)\n", Time++, p.x, p.y);
		if (flag)
		printf("%ds:(%d,%d)->(%d,%d)\n", Time++, p.x, p.y, pre.x, pre.y);
	}
	if (pre.x != 0 || pre.y != 0)
		Print_Pace(pre);
}
int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	node ok;
	while (cin >> N >> M){
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < M; ++j)
			if (s[j] == '.')
				map[i][j] = 1;
			else if (s[j] == 'X')
				map[i][j] = 0;
			else
				map[i][j] = s[j] - '0' + 1;
		}
		int ans = Astar();
		if (ans == -1)
			printf("God please help our poor hero.\n");
		else{
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans);
			Point end;
			pace[N-1][M-1].x = pace[N-1][M-1].y = 0;
			Time = 1;
			end.x = 0;
			end.y = 0;
			Print_Pace(end);
		}
		printf("FINISH\n");


	}
		
		

	return 0;
}