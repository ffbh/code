#include <iostream>
//#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
int A, B, C,K;
struct node{
	int x, y, z;
	int f;
	int step;
	bool operator<(const node& p)const{
		if (p.step==step)
			return f>p.f;
		return step > p.step;
	}
};
bool map[60][60][60];
bool vis[60][60][60];
int dirs[6][3] = {
	0, 1, 0,
	1, 0, 0,
	0, -1, 0,
	-1, 0, 0,
	0, 0, 1,
	0, 0, -1};
bool IN(const node& p){
	return p.x >= 0 && p.x < A&&p.y >= 0 && p.y < B&&p.z >= 0 && p.z < C;
}

int getT(const node& p){
	return abs(p.x - A+1) + abs(p.y - B+1) + abs(p.z - C+1);
}
int bfs(){
	node temp1, temp2;
	priority_queue<node> pn;
	temp1.x = 0;
	temp1.y = 0;
	temp1.z = 0;
	temp1.step = 0;
	pn.push(temp1);
	while (!pn.empty()){
		temp1 = pn.top();
		pn.pop();
		temp1.step++;
		for (int i = 0; i < 6; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			temp2.z += dirs[i][2];
			if (temp2.x == A - 1 && temp2.y == B - 1 && temp2.z == C - 1)
				return temp2.step;
			if (IN(temp2) && !vis[temp2.x][temp2.y][temp2.z] && map[temp2.x][temp2.y][temp2.z] == 0){
				vis[temp2.x][temp2.y][temp2.z] = 1;
				temp2.f = temp2.step + getT(temp2);
				if (temp2.f<=K+2)
					pn.push(temp2);
			}
		}
	}
	return -1;
}
int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	cin >> N;
	while (N--){
		memset(vis, 0, sizeof(vis));
		scanf("%d%d%d%d", &A, &B, &C, &K);
		//in >> A >> B >> C >> K;
		for (int i = 0; i < A;++i)
		for (int j = 0; j < B;++j)
		for (int k = 0; k < C;++k)
			scanf("%d", &map[i][j][k]);
		//	in >> map[i][j][k];
		if (A == 1 && B == 1 && C == 1)
			cout << -1 << endl;
		else if (map[A - 1][B - 1][C - 1])
			cout << -1 << endl;
		else{
			int ans = bfs();
			if (ans <= K&&ans != -1)
				cout << ans << endl;
			else
				cout << -1 << endl;
		}
	}
	return 0;
}