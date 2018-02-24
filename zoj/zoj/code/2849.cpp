#include <iostream>
#include <cstring>
#include <fstream>
#include <map>
#include <queue>
#include <cmath>
using namespace std;
struct Node{
	int x, y, leval, type;
	bool operator<(const Node& p)const{
		if (leval != p.leval)
			return leval>p.leval;
		return type > p.type;
	}
};
map<int, int> mii;
int N, M;
priority_queue<Node> qn;
int data[510][510];
int mark[510][510];
bool vis[510][510];
int dirs[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
bool IN(Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= M;
}


void bfs(){
	Node temp1, temp2;
	while (!qn.empty()){
		temp1 = qn.top();
		qn.pop();
		if (vis[temp1.x][temp1.y])
			continue;
		vis[temp1.x][temp1.y] = 1;
		mii[temp1.type]++;
	/*	mark[temp1.x][temp1.y] = temp1.type;
		for (int i = 1; i <= N; ++i){
			for (int j = 1; j <= M; ++j)
				cout << mark[i][j];
			cout << endl;
		}
		cout << endl;*/
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2)&&!vis[temp2.x][temp2.y]){
				if (temp2.leval < abs(data[temp2.x][temp2.y]))
					temp2.leval = abs(data[temp2.x][temp2.y]);
				qn.push(temp2);
			}
		}
	}
}




int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		while (!qn.empty())
			qn.pop();
		mii.clear();
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= M; ++j){
			cin >> data[i][j];
			if (data[i][j] > 0){
				qn.push(Node{ i, j, 1, data[i][j] });
			}
		}
		bfs();
		int Q;
		cin >> Q;
		while (Q--){
			int q;
			cin >> q;
			cout << mii[q] << endl;
		}
	}
	return 0;
}