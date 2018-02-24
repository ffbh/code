#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <queue>
using namespace std;
ifstream in("C:\\temp.txt");
struct Point{
	double x, y;
	bool operator==(const Point& p)const{
		return x == p.x&&y == p.y;
	}
	bool operator<(const Point& p)const{
		return x * 10 + y < 10 * p.x + p.y;
	}
};
struct Node{
	int x, y;
	string pace;
};

string ff = "ESWN";
set<Point> sp;
int sx, sy, ex, ey;
bool vis[7][7];

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

bool IN(Node& p){
	return p.x >= 1 && p.x <= 6 &&p.y >= 1 && p.y <= 6;
}

void Init(){
	sp.clear();
	double x1, y1, x2, y2;
	Point p;
	int T = 3;
	while (T--){
	//	scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2){
			p.x = x1;
			for (double i = y1; i < y2; ++i){
				p.y = (2 * i + 1) / 2;
				sp.insert(p);
			}
		}
		else{
			p.y = y1;
			for (double i = x1; i < x2; ++i){
				p.x = (2 * i + 1) / 2;
				sp.insert(p);
			}
		}
	}
}

bool OK(const Node& t1, const Node& t2){
	Point p;
	p.x = (double(t1.x) + t2.x-1) / 2;
	p.y = (double(t1.y) + t2.y-1) / 2;
	return !sp.count(p);
}

string bfs(){
	queue<Node> qn;
	vis[sx][sy] = 1;
	Node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	temp1.pace = "";
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.pace += ff[i];
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2)&&OK(temp1,temp2)&&!vis[temp2.x][temp2.y]){
				vis[temp2.x][temp2.y] = 1;
				if (temp2.x == ex&&temp2.y == ey)
					return temp2.pace;
				qn.push(temp2);
			}
		}
	}
	return "";
}



int main(){


	while (cin >> sx >> sy&&sx + sy){
		memset(vis, 0, sizeof(vis));
		cin >> ex >> ey;
		Init();
		cout << bfs() << endl;
	}

	return 0;
}