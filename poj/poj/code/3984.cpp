#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int  maze[5][5];

struct Node{
	int x, y;
	Node(int _x, int _y){
		x = _x;
		y = _y;
	}
	Node(){}
}pace[5][5];
vector<Node> vn;
bool IN(Node& p){
	return p.x >= 0 && p.x < 5 && p.y >= 0 && p.y < 5;

}
bool vis[5][5];


void bfs(){
	Node temp1, temp2;
	vn.clear();
	memset(vis, 0, sizeof(vis));
	queue<Node> qn;
	qn.push(Node(4, 4));
	vis[4][4] = 1;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y]&&maze[temp2.x][temp2.y]==0){
				vis[temp2.x][temp2.y] = 1;
				pace[temp2.x][temp2.y] = temp1;
				qn.push(temp2);
			}
		}
	}
}


void print(Node p){
	if (p.x == 4 && p.y == 4)
		printf("(4, 4)\n");
	else{
		printf("(%d, %d)\n", p.x, p.y);
		print(pace[p.x][p.y]);
	}
}




int main(){
	ifstream in("C:\\input.txt");
	for (int i = 0; i<5;++i)
	for (int j = 0; j < 5; ++j)
		cin >> maze[i][j];
	bfs();
	print(Node(0, 0 ));



	return 0;
}