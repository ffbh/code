#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
struct Node{
	int x, y;
	Node(int _x, int _y){
		x = _x;
		y = _y;
	}
	Node(){}
};
int map[110][110];
bool vis[110][110];
int N;
bool IN(Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= N;

}

bool bfs(int low,int high){
	if (map[1][1]<low || map[1][1]>high)
		return 0;
	queue<Node> qn;
	Node temp1, temp2;
	memset(vis, 0, sizeof(vis));
	vis[1][1] = 1;
	temp1.x = 1;
	temp1.y = 1;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		if (temp1.x == N&&temp1.y == N)
			return 1;
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y] && map[temp2.x][temp2.y] >= low
				&&map[temp2.x][temp2.y] <= high){
				vis[temp2.x][temp2.y] = 1;
				qn.push(temp2);
			}
		}
	}
	return 0;
}




int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		int l = INT_MAX;
		int h = INT_MIN;
		cin >> N;
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j){
			cin >> map[i][j];
			if (map[i][j] > h)
				h = map[i][j];
			if (map[i][j] < l)
				l = map[i][j];
		}
		int left, mid, right;
		left = 0;
		right = h - l;
		int ans;
		while (left <= right){
			mid = (left + right) / 2;
			bool f = 0;
			for (int i = l; i + mid <= h; ++i){
				if (bfs(i, i + mid)){
					f = 1;
					break;
				}
			}
			if (f){
				right = mid - 1;
				ans = mid;
			}
			else
				left = mid + 1;
		
		}
		printf("Scenario #%d:\n", CASE++);
		cout << ans << endl;
		if (T)
			cout << endl;
	}






	return 0;
}