#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int a, b, c;
bool vis[1001][1001][1001];
struct Node{
	int num[3];
	int step;
};

bool OK(Node& p){
	if (p.num[0] == 0)
		return p.num[1] == 0 || p.num[2] == 0;
	else if (p.num[1] == 0)
		return p.num[2] == 0;
	else
		return 0;
}

int bfs(){
	queue<Node> qn;
	memset(vis, 0, sizeof(vis));
	Node temp1, temp2;
	temp1.num[0] = a;
	temp1.num[1] = b;
	temp1.num[2] = c;
	temp1.step = 0;
	vis[a][b][c] = 1;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		if (OK(temp1))
			return temp1.step;
		temp1.step++;
		for (int i = 0; i < 3; ++i){
			temp2 = temp1;
			int k1 = (i + 1) % 3;
			int k2 = (i + 2) % 3;
			if (temp2.num[k1] && temp2.num[k2]){
				temp2.num[i] += 2;
				temp2.num[k1]--;
				temp2.num[k2]--;
				if (!vis[temp2.num[0]][temp2.num[1]][temp2.num[2]]){
					vis[temp2.num[0]][temp2.num[1]][temp2.num[2]] = 1;
					qn.push(temp2);
				}
			}
		}
	}
	return -1;
}

int main(){
	ifstream in("C:\\temp.txt");
	while (cin >> a >> b >> c){
		int step = bfs();
		if (step > 0)
			cout << step << endl;
		else
			cout << "):" << endl;
	}
	return 0;
}