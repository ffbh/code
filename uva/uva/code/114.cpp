#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int N, M, p;
struct Node{
	int v, c;
	bool bumper;
}mmp[60][60];
int wall_cost;

bool isWall(int x,int y){
	return x == 1 || y == 1 || x == N || y == M;
}

void Init(){
	for (int i = 0; i < 60;++i)
	for (int j = 0; j < 60; ++j){
		mmp[i][j].v = 0;
		mmp[i][j].c = 0;
		mmp[i][j].bumper = 0;
	}
}

int cale(int x, int y, int d, int f){
	int val = 0;
	while (f>0){
		f--;
		if (f <= 0)
			break;
		int nx = x + dirs[d][0];
		int ny = y + dirs[d][1];
		if (isWall(nx, ny)){
			f -= wall_cost;
			d = (d + 3) % 4;
		}
		else if(mmp[nx][ny].bumper){
			val += mmp[nx][ny].v;
			
			f -= mmp[nx][ny].c;
			d = (d + 3) % 4;
		}
		else{
			x = nx;
			y = ny;
		}
	}
	return val;
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;


	in >> N >> M;
	in >> wall_cost >> p;
	for (int i = 0; i < p; ++i){
		int x, y, v, c;
		in >> x >> y >> v >> c;
		mmp[x][y].v = v;
		mmp[x][y].c = c;
		mmp[x][y].bumper = 1;
	}

	int a, b, c, d;
	int sum = 0;
	while (in >> a >> b >> c >> d){
		int ret = cale(a, b, c, d);
		cout << ret << endl;
		sum += ret;
	}
	cout << sum << endl;

	return 0;
}