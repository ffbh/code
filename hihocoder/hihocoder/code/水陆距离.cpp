#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <queue>
using namespace std;
struct Node{
	int x, y;
	Node(int a, int b){
		x = a;
		y = b;
	}
	Node(){}
};
bool vis[810][810];
int N, M;
int ans[810][810];

bool IN(Node& p){
	return p.x >= 0 && p.x < N&&p.y >= 0 && p.y < M;
}


int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	queue<Node> qn;
	for (int i = 0; i < N; ++i){
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); ++j){
			if (s[j] == '0'){
				qn.push(Node(i, j));
				ans[i][j] = 0;
				vis[i][j] = 1;
			}
			else{
				ans[i][j] = 1 << 26;
			}
		}

	}
	
	while (!qn.empty()){
		Node u = qn.front(), v;
		qn.pop();
		for (int i = 0; i < 4; ++i){
			v.x = u.x + dirs[i][0];
			v.y = u.y + dirs[i][1];
			if (IN(v)){
				if (ans[v.x][v.y] > ans[u.x][u.y] + 1){
					ans[v.x][v.y] = ans[u.x][u.y] + 1;
					if (!vis[v.x][v.y]){
						vis[v.x][v.y] = 1;
						qn.push(v);
					}
				}

			}
		}
	}

	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M - 1; ++j)
			printf("%d ", ans[i][j]);
		printf("%d\n", ans[i][M - 1]);
	}





	return 0;
}