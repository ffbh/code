#include <iostream>
#include <string>
#include <fstream> 
#include <map> 
using namespace std;
map<char, int> mci;
struct Point{ int x, y; int dir; }
data[110];
int N, M, K, K2;
int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };
bool IN(int x, int y){
	return x >= 1 && x <= N&&y >= 1 && y <= M;
}
int mmap[110][110];
int mark, robot;
void run(int u, int time){
	int nowx, nowy, nextx, nexty;
	nowx = data[u].x;
	nowy = data[u].y;
	int dir = data[u].dir;
	mmap[nowx][nowy] = 0;
	while (time--){
		nextx = nowx + dirs[dir][0];
		nexty = nowy + dirs[dir][1];
		if (!IN(nextx, nexty)){
			mark = 1; return;
		}
		else if (mmap[nextx][nexty]){
			mark = 2;
			robot = mmap[nextx][nexty];
			return;
		}
		nowx = nextx;
		nowy = nexty;
	}
	data[u].x = nowx;
	data[u].y = nowy;
	mmap[nowx][nowy] = u;
}
int main(){
	//ifstream in("C:\\temp.txt");
	mci['N'] = 0;
	mci['E'] = 1;
	mci['S'] = 2;
	mci['W'] = 3;
	int T;
	cin >> T;
	char c;
	while (T--){
		memset(mmap, 0, sizeof(mmap));
		cin >> N >> M >> K >> K2;
		for (int i = 1; i <= K; ++i){
			cin >> data[i].x >> data[i].y >> c; data[i].dir = mci[c]; mmap[data[i].x][data[i].y] = i;
		}
		int num, time;
		bool flag = 1;
		while (K2--){
			cin >> num >> c >> time;
			if (c == 'L' || c == 'R'){
				time %= 4;
				if (c == 'L')
					data[num].dir = (data[num].dir + 4 - time) % 4; else
					data[num].dir = (data[num].dir + time) % 4;
			}
			else{
				mark = 0;
				run(num, time);
				if (mark){
					flag = 0;
					if (mark == 1)
						printf("Robot %d crashes into the wall\n", num);
					else printf("Robot %d crashes into robot %d\n", num, robot); break;
				}
			}
		}
		while (K2-->0){
			cin >> num >> c >> time;
		}
		if (flag) cout << "OK" << endl;
	}
	return 0;
}