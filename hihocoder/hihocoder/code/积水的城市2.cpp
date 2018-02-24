#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int x, y, dis;
	bool operator<(const Node& p)const{
		return dis > p.dis;
	}
};

bool mark[1010][1010];
bool vis[1010][1010];
int A[1010], B[1010], N, M, K, Q, sx, sy, ex, ey;

bool IN(Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= M;
}

int spfa(){

	memset(vis, 0, sizeof(vis));

	priority_queue<Node> qn;
	Node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	temp1.dis = 0;
	vis[sx][sy] = 1;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.top();
		qn.pop();

		if (temp1.x == ex&& temp1.y == ey)
			return temp1.dis;

		temp2.x = temp1.x + 1;
		temp2.y = temp1.y;
		if (IN(temp2) && !mark[temp2.x][temp2.y] && !vis[temp2.x][temp2.y]){
			vis[temp2.x][temp2.y] = 1;
			temp2.dis = temp1.dis + B[temp1.x];
			qn.push(temp2);
		}

		temp2.x = temp1.x - 1;
		temp2.y = temp1.y;
		if (IN(temp2) && !mark[temp2.x][temp2.y] && !vis[temp2.x][temp2.y]){
			vis[temp2.x][temp2.y] = 1;
			temp2.dis = temp1.dis + B[temp2.x];
			qn.push(temp2);

		}

		temp2.x = temp1.x;
		temp2.y = temp1.y + 1;
		if (IN(temp2) && !mark[temp2.x][temp2.y] && !vis[temp2.x][temp2.y]){
			vis[temp2.x][temp2.y] = 1;
			temp2.dis = temp1.dis + A[temp1.y];
			qn.push(temp2);
			
		}

		temp2.x = temp1.x;
		temp2.y = temp1.y - 1;
		if (IN(temp2) && !mark[temp2.x][temp2.y] && !vis[temp2.x][temp2.y]){
			vis[temp2.x][temp2.y] = 1;
			temp2.dis = temp1.dis + A[temp2.y];
			qn.push(temp2);
		}

	}
	return -1;

}





int main(){
	ifstream in("C:\\input.txt");
	in >> N >> M;
	for (int i = 1; i < N; ++i)
		in >> B[i];
	for (int i = 1; i < M; ++i)
		in >> A[i];
	in >> K;
	while (K--){
		int x, y;
		in >> x >> y;
		mark[x][y] = 1;
	}
	in >> Q;
	while (Q--){
		in >> sx >> sy >> ex >> ey;
		cout << spfa() << endl;


	}
	return 0;
}