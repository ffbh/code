#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <ctime>
using namespace std;
struct node{
	int x, y;
};
int dirs[4][2]={1,0,0,1,-1,0,0,-1};
queue<node> qn;
string num[100];
bool vis[100][100];
int N, M;
bool IN(const node& nn){
	return nn.x >= 0 && nn.x < N&&nn.y >= 0 && nn.y < M;
}
void bfs(){
	int sum = 0;
	node temp1, temp2;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2 = temp1;
			temp2.x += dirs[i][0];
			temp2.y += dirs[i][1];
			if (IN(temp2)){
				if (num[temp2.x][temp2.y] == '0'){
					vis[temp2.x][temp2.y] = 1;
				}
				else if (!vis[temp2.x][temp2.y]){
					qn.push(temp2);
					vis[temp2.x][temp2.y] = 1;
				}
			}
			
		}
		
	}

}

int main(){
	long t = clock();
	ifstream in("C:\\temp.txt");
	in >> N >> M;
	for (int i = 0; i < N; ++i)
		in >> num[i];
	int sum = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M;++j)
	if (num[i][j] != '0'&&!vis[i][j]){
		node nn;
		nn.x = i;
		nn.y = j;
		vis[i][j] = 1;
		qn.push(nn);
		bfs();
		sum++;
	}
	cout << sum << endl;
	cout << clock() - t << endl;
	



	return 0;
}