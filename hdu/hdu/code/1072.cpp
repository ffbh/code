#include<iostream>
#include <deque>
#include <fstream>
using namespace std;

struct node {
	int x, y;
	int step;
	int time;
};
deque<node> dn;
int N, M;
int sx, sy;
struct MAP{
	int value;
};
MAP map[9][9];

int dirs[4][2] = { { 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 1 } };

bool IN(node n){
	return n.x >= 0 && n.x < N&&n.y >= 0 && n.y < M;
}
int fun(){
	node temp1, temp2;
	while (!dn.empty()){
		temp1 = dn[0];
		dn.pop_front();
		if (temp1.time == 1)
			continue;
		temp1.step++;
		temp1.time--;
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2) && map[temp2.x][temp2.y].value != 0){
				if (map[temp2.x][temp2.y].value == 3)
					return temp2.step;
				else if (map[temp2.x][temp2.y].value == 4){
					temp2.time = 6;
					map[temp2.x][temp2.y].value = 0;
				}
				if (map[temp2.x][temp2.y].value == 2)
					continue;
				dn.push_back(temp2);
			}

		}
	}
	return -1;
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	in >> T;
	while (T-->0){
		in >> N >> M;
		for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j){
			//scanf("%d", &map[i][j].value);
			in >> map[i][j].value;
			if (map[i][j].value == 2){
				sx = i;
				sy = j;
			}
		}
		dn.clear();
		node  nn;
		nn.x = sx;
		nn.y = sy;
		nn.step = 0;
		nn.time = 6;
		dn.push_back(nn);
		cout << fun() << endl;


	}


	return 0;
}