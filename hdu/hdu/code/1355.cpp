#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
int N, M;
int map[50][50];
struct Point{
	int x, y;
	bool operator<(const Point& p)const{
		return map[x][y] < map[p.x][p.y];
	}
};


int main(){
	ifstream in("C:\\temp.txt");
	int T, K;
	Point p;
	cin >> T;
	while (T--){
		cin >> N >> M >> K;
		priority_queue<Point> qp;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M; ++j){
			//in >> map[i][j];
			scanf("%d", &map[i][j]);
			if (map[i][j]){
				p.x = i;
				p.y = j;
				qp.push(p);
			}
		}
		int time = 0;
		int v = 0;
		Point pre, now;
		int need;
		bool flag = 1;
		while (!qp.empty() && time <= K){
			now = qp.top();
			qp.pop();
			if (flag){
				need = now.x + 2;
				flag = 0;
			}
			else
			  need = abs(now.x - pre.x) + abs(now.y - pre.y)+1;
			time += need;
			if (now.x + 1 + time > K)
				break;
			pre = now;
			v += map[now.x][now.y];
		}
		cout << v <<  endl;


	}

	return 0;
}