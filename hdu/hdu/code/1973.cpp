#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <cmath>
using namespace std;
struct Node{
	int now, step; 
};
bool prime[10000];
bool vis[11111];
int S, E;
void Init(){
	for (int i = 2; i < 10000; ++i)
	if (!prime[i])
		for (int j = 2; i*j < 10000; ++j)
			prime[i*j] = 1;
}
bool IN(int x,int y){
	if (x<1000 || x>9999)
		return 0;
	int dif = 0;
	while (x){
		if (x % 10 != y % 10)
			dif++;
		x /= 10;
		y /= 10;
	}
	return dif == 1;
}
int dirs[8] = { 1, -1, 10, -10, 100, -100, 1000, -1000 };


int bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.now = S;
	temp1.step = 0;
	qn.push(temp1);
	vis[S] = 1;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (temp1.now == E)
			return temp1.step;
		temp2.step = temp1.step + 1;
		for (int i = 0; i < 8; ++i)
			for (int j = 1; j < 10; ++j){
				temp2.now = temp1.now + dirs[i] * j;
				if (!prime[temp2.now]&&IN(temp2.now, temp1.now)){
					if (!vis[temp2.now]){
						vis[temp2.now] = 1;
						qn.push(temp2);
					}
				}
			}
	}
	return -1;
}




int main(){
	//ifstream in("C:\\temp.txt");
	Init();
	int T;
	cin >> T;
	while (T--){
		memset(vis, 0, sizeof(vis));
		cin >> S >> E;
		int ans = bfs();
		if (ans >= 0)
			cout << ans << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}