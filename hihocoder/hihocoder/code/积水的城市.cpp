#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
	int x, y;
};

bool mark[510][510];
int data[510][510];
int A[510], B[510], N, M, K, Q, sx, sy, ex, ey;

bool IN(Node& p){
	return p.x >= 1 && p.x <= N&&p.y >= 1 && p.y <= M;
}

int spfa(){
	for (int i = 1; i <= N;++i)
	for (int j = 1; j <= M; ++j)
		data[i][j] = (1 << 30);

	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = sx;
	temp1.y = sy;
	data[sx][sy] = 0;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();

		temp2.x = temp1.x + 1;
		temp2.y = temp1.y;
		if (IN(temp2)&&!mark[temp2.x][temp2.y]){
			if (data[temp2.x][temp2.y] > data[temp1.x][temp1.y] + B[temp1.x]){
				data[temp2.x][temp2.y] = data[temp1.x][temp1.y] + B[temp1.x];
				qn.push(temp2);
			}
		}

		temp2.x = temp1.x - 1;
		temp2.y = temp1.y;
		if (IN(temp2) && !mark[temp2.x][temp2.y]){
			if (data[temp2.x][temp2.y] > data[temp1.x][temp1.y] + B[temp2.x]){
				data[temp2.x][temp2.y] = data[temp1.x][temp1.y] + B[temp2.x];
				qn.push(temp2);
			}
		}

		temp2.x = temp1.x;
		temp2.y = temp1.y + 1;
		if (IN(temp2) && !mark[temp2.x][temp2.y]){
			if (data[temp2.x][temp2.y] > data[temp1.x][temp1.y] + A[temp1.y]){
				data[temp2.x][temp2.y] = data[temp1.x][temp1.y] + A[temp1.y];
				qn.push(temp2);
			}
		}

		temp2.x = temp1.x;
		temp2.y = temp1.y - 1;
		if (IN(temp2) && !mark[temp2.x][temp2.y]){
			if (data[temp2.x][temp2.y] > data[temp1.x][temp1.y] + A[temp2.y]){
				data[temp2.x][temp2.y] = data[temp1.x][temp1.y] + A[temp2.y];
				qn.push(temp2);
			}
		}

	}
	return (data[ex][ey] == (1 << 30)) ? -1 : data[ex][ey];

}





int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M;
	for (int i = 1; i < N; ++i)
		cin >> B[i];
	for (int i = 1; i < M; ++i)
		cin >> A[i];
	cin >> K;
	while (K--){
		int x, y;
		cin >> x >> y;
		mark[x][y] = 1;
	}
	cin >> Q; 
	while (Q--){
		cin >> sx >> sy >> ex >> ey;
		cout << spfa() << endl;


	}


















	return 0;
}