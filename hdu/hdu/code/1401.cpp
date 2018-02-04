#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
struct Point{
	int x, y;
	bool operator==(const Point& p)const{
		return x == p.x&&y == p.y;
	}
	bool operator<(const Point& p)const{
		if (x != p.x)
			return x < p.x;
		return y< p.y;
	}
};

struct Board{
	Point data[4];
	int step;
};

char vis[20000000];
Board Sboard, Eboard;

int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

bool IN(const Point& p){
	return p.x >= 0 && p.x < 8 &&p.y >= 0 && p.y < 8;
}

int getHash(const Board& p){
	int res = 0;
	Board k = p;
	sort(k.data, k.data + 4);
	for (int i = 0; i < 4; ++i){
		res = res * 8 + k.data[i].x;
		res = res * 8 + k.data[i].y;
	}
	return res;
}

bool OK(const Board& b,const Point& p){
	for (int i = 0; i < 4;++i)
	if (b.data[i] == p)return 0;
	return 1;

}

void First_Bfs(){
	queue<Board> qb;
	Board temp1, temp2;
	Point temp;
	vis[getHash(Sboard)] = 1;
	Sboard.step = 0;
	qb.push(Sboard);
	while(!qb.empty()){
		temp1 = qb.front();
		qb.pop();
		temp1.step++;
		if (temp1.step >= 5)continue;
		for (int i = 0; i < 4; ++i){
			for (int k = 0; k < 4; ++k){
				temp = temp1.data[i];
				temp2 = temp1;
				temp.x += dirs[k][0];
				temp.y += dirs[k][1];
				if (IN(temp)){
					if (!OK(temp1, temp)){
						temp.x += dirs[k][0];
						temp.y += dirs[k][1];
						if (!IN(temp) || !OK(temp1, temp)) continue;
					}
					temp2.data[i] = temp;
					int hh = getHash(temp2);
					if (vis[hh])continue;
					vis[hh] = 1;
					qb.push(temp2);
				}

			}
		}
	}
}

bool Last_Bfs(){
	queue<Board> qb;
	Board temp1, temp2;
	Point temp;
	if (vis[getHash(Eboard)]==0)
		vis[getHash(Eboard)] = -1;
	else return 1;
	Eboard.step = 0;
	qb.push(Eboard);
	while (!qb.empty()){
		temp1 = qb.front();
		qb.pop();
		temp1.step++;
		if (temp1.step >= 5)continue;
		for (int i = 0; i < 4; ++i){
			for (int k = 0; k < 4; ++k){
				temp = temp1.data[i];
				temp2 = temp1;
				temp.x += dirs[k][0];
				temp.y += dirs[k][1];
				if (IN(temp)){
					if (!OK(temp1, temp)){
						temp.x += dirs[k][0];
						temp.y += dirs[k][1];
						if (!IN(temp) || !OK(temp1, temp)) continue;
					}
					temp2.data[i] = temp;
					int hh = getHash(temp2);
					if (vis[hh] == 1)return 1;
					if (!vis[hh]){
						vis[hh] = -1;
						qb.push(temp2);
					}
				}

			}
		}
	}
	return 0;
}






int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> Sboard.data[0].x >> Sboard.data[0].y){
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i < 4; ++i)
			cin >> Sboard.data[i].x >> Sboard.data[i].y;
		for (int i = 0; i < 4; ++i)
			cin >> Eboard.data[i].x >> Eboard.data[i].y;
		for (int i = 0; i < 4; ++i){
			Sboard.data[i].x--;
			Sboard.data[i].y--;
			Eboard.data[i].x--;
			Eboard.data[i].y--;
		}
		First_Bfs();
		if (Last_Bfs())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}



	return 0;
}