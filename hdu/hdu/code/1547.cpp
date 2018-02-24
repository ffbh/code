#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;
int N, M,X,Y;
struct node{
	int x, y;
};
string map[110];
bool vis[110][110];
int dirs[6][2] = {0,1,0,-1,1,0,-1,0,1,-1,-1,-1};
bool IN(const node& p){
	if (p.x >= 0 && p.x < N){
		if (p.x % 2 == 0)
			return p.y >= 0 && p.y < M;
		else
			return p.y >= 0 && p.y < M - 1;
	}
	else
		return 0;
}

void Walk(node& p,int i){
	if (i <= 3){
		p.x += dirs[i][0];
		p.y += dirs[i][1];
		return;
	}
	else{
		if (p.x % 2 == 0){
			p.x += dirs[i][0];
			p.y += dirs[i][1];
			return;
		}
		else{
			p.x += dirs[i][0];
			p.y -= dirs[i][1];
			return;
			
		}
	}
}


int BFS(){
	queue<node> qn;
	int ans = 0;
	char ff = map[X][Y];
	node temp1, temp2;
	temp1.x = X;
	temp1.y = Y;
	vis[X][Y] = 1;
	qn.push(temp1);
	ans++;
	while (!qn.empty()){
		temp1 = qn.front();
		qn.pop();
		for (int i = 0; i < 6; ++i){
			temp2 = temp1;
			Walk(temp2, i);
			if (IN(temp2) && !vis[temp2.x][temp2.y] && map[temp2.x][temp2.y] == ff){
				vis[temp2.x][temp2.y] = 1;
				qn.push(temp2);
				ans++;
			}
		}
	}
	return ans;
}

int dfs(const node& temp1){
	int res = 1;
	vis[temp1.x][temp1.y] = 1;
	node temp2;
	for (int i = 0; i < 6; ++i){
		temp2 = temp1;
		Walk(temp2, i);
		if (IN(temp2) && !vis[temp2.x][temp2.y]&&map[temp2.x][temp2.y]!='E')
			res += dfs(temp2);
	}
	return res;
}




int main(){
	//ifstream in("C:\\temp.txt");
	node dd;
	while (cin >> N >> M >> X >> Y){
		X--;
		Y--;
		int ttl = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < N; ++i)
			cin >> map[i];
		for (int i = 0; i < N; ++i){
			int len = map[i].length();
			for (int j = 0; j < len;++j)
			if (map[i][j] != 'E')ttl++;
			else
				vis[i][j] = 1;
		}
		if (BFS() <= 2)//加上新来的超过三个
			cout << 0 << endl;
		else{
			int ans = 0;
			dd.x = 0;
			for (int i = 0; i < M;++i)
			if (!vis[0][i]&&map[0][i]!='E'){
				dd.y = i;
				ans += dfs(dd);
			}
			cout << ttl - ans << endl;
		}
			
	}

	return 0;
}