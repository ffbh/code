#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
struct Node{
	int x, y;
};
int N, M;
int vis[60][60];
bool IN(const Node& p){
	return p.x >= 0 && p.x <= N&&p.y >= 0 && p.y <= M;
}

int dirs[4][2] = { 0, 1, 1, 0, 0, -1, -1, 0 };

void bfs(){
	queue<Node> qn;
	Node temp1, temp2;
	temp1.x = temp1.y = 0;
	qn.push(temp1);
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 4; ++i){
			temp2.x = temp1.x + dirs[i][0];
			temp2.y = temp1.y + dirs[i][1];
			if (IN(temp2) && !vis[temp2.x][temp2.y]){
				vis[temp2.x][temp2.y] = 1;
				qn.push(temp2);
			}
		}
	}
}

int main(){
//	ifstream in("C:\\temp.txt");
	string s;
	while (1){
		s = "";
		N = 1;
		M = 0;
		memset(vis, 0, sizeof(vis));
		while (getline(cin, s) && s.size() == 0);
		if (s.length() == 0)break;
		for (int i = 0; i < s.length(); ++i)
		if (s[i] == ' ')
			vis[N][i + 1] = 0;
		else
			vis[N][i + 1] = 1;
		if (M < s.length())
			M = s.length();
		N++;
		while (getline(cin, s)&&s.length() != 0){
			for (int i = 0; i < s.length();++i)
			if (s[i] == ' ')
				vis[N][i+1] = 0;
			else
				vis[N][i+1] = 1;
			if (M < s.length())
				M = s.length();
			N++;
			
		}
		N++;
		M++;
		bfs();
		bool flagA = 0;
		for (int i = 1; i < N&&!flagA;++i)
		for (int j = 1; j < M;++j)
		if (!vis[i][j]){
			flagA = 1;
			break;
		}
		if (flagA)
			cout << "A" << endl;
		else
			cout << "C" << endl;
	}
	return 0;
}