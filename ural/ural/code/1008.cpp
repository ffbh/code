#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
#include <sstream>
using namespace std;
int N, x, y;
bool mark[20][20];
int dirs[4][2] = { 1, 0, 0,1, -1,0, 0, -1 };
string pace = "RTLB";
int h[266];

struct Node{
	int x, y;
	Node(int a, int b){
		x = a;
		y = b;
	}
	Node() {}
	bool IN(){
		return x >= 1 && x <= 10 && y >= 1 && y <= 10;
	}
};


void bfs(){
	queue<Node> qn;
	cout << x << " " << y << endl;
	mark[x][y] = 0;
	qn.push(Node(x, y));
	int num = 0;
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		num++;
		if (num == N){
			cout << "." << endl;
		}
		else{
			string ans = "";
			for (int i = 0; i < 4; ++i){
				v.x = u.x + dirs[i][0];
				v.y = u.y + dirs[i][1];
				if (v.IN() && mark[v.x][v.y]){
					ans += pace[i];
					mark[v.x][v.y] = 0;
					qn.push(v);
				}
				
			}
			cout << ans << "," << endl;
		}
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	string s;
	getline(cin, s);
	stringstream ss;
	ss.clear();
	ss.str(s);
	int a, b;
	a = b = -1;
	ss >> a >> b;
	if (b == -1){
		N = a;
		x = y = 1111111;
		memset(mark, 0, sizeof(mark));
		for (int i = 1; i <= N; ++i){
			int tx, ty;
			cin >> tx >> ty;
			if (tx < x || tx == x&&ty < y){
				x = tx;
				y = ty;
			}
			mark[tx][ty] = 1;
		}
		if (N)
			bfs();
		else
			cout << "." << endl;
	}
	else{
		h['R'] = 0;
		h['T'] = 1;
		h['L'] = 2;
		h['B'] = 3;
		memset(mark, 0, sizeof(mark));
		mark[a][b] = 1;
		queue<Node> qn;
		qn.push(Node(a, b));
		int num = 0;
		while (!qn.empty()){
			Node u = qn.front(), v;
			qn.pop();

			num++;
			string dd;
			cin >> dd;
			for (int i = 0; i < dd.length() - 1; ++i){
				int d = h[dd[i]];
				v.x = u.x + dirs[d][0];
				v.y = u.y + dirs[d][1];
				mark[v.x][v.y] = 1;
				qn.push(v);
			}
		}
		cout << num << endl;
		for (int i = 1; i <= 10;++i)
		for (int j = 1; j <= 10;++j)
		if (mark[i][j])
			cout << i << " " << j << endl;
	}

	return 0;
}