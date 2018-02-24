#include <iostream>
#include <string>
#include <fstream>
#include<queue>
#include <cmath>
using namespace std;
struct node{
	int x, y;
	double f;
	int step;
	bool operator<(const node& p)const{
		if (step==p.step)
			return f > p.f;
		return step > p.step;
	}
};
bool vis[10][10];
int dirs[8][2] = { 1, 2, 2, 1, -1, 2, 2, -1, 1, -2, -2, 1, -1, -2, -2, -1 };
int sx, sy, ex, ey;
bool IN(node& p){
	return p.x >= 0 && p.x < 8 && p.y >= 0 && p.y < 8;
}
double getNum(node& p){
	return sqrt(pow(p.x - ex, 2) + pow(p.y - ey, 2));
}

int Astar(){
	priority_queue<node> pp;
	node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	temp1.step = 0;
	vis[temp1.x][temp1.y] = 1;
	pp.push(temp1);
	while (!pp.empty()){
		temp1 = pp.top();
		pp.pop();
		temp1.step++;
		for (int i = 0; i < 8; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (temp2.x == ex&&temp2.y == ey)
				return temp2.step;
			if (IN(temp2) && !vis[temp2.x][temp2.y]){
				vis[temp2.x][temp2.y] = 1;
				temp2.f = temp2.step + getNum(temp2);
				pp.push(temp2);
			}
		}
	}
	return 0;
}



int main(){
	//ifstream in("C:\\temp.txt");
	string s1, s2;
	while (cin >> s1 >> s2){
		memset(vis, 0, sizeof(vis));
		sx = s1[0] - 'a';
		sy = s1[1] - '1';
		ex = s2[0] - 'a';
		ey = s2[1] - '1';
		if (sx == ex&&sy == ey) printf("To get from %s to %s takes %d knight moves.\n", s1.c_str(), s2.c_str(), 0);
		else printf("To get from %s to %s takes %d knight moves.\n", s1.c_str(), s2.c_str(), Astar());
	}

	return 0;
}