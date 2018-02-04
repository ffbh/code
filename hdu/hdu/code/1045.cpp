/*#include<iostream>
#include <string>
//#include <fstream>
using namespace std;
#define WALL 1
#define HOUSE 3
#define BLANK 0
int map[5][5];
int n;
int m;

bool empty(){
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n;++j)
	if (map[i][j] == BLANK)
		return true;
	return false;

}
bool in(int x, int y){
	return !(x < 0 || y < 0 || x >= n || y >= n);
}
int dirs[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
bool  _fun(int x, int y,int flag){
	int _x, _y;
	for	(int i = 0; i < 4; ++i){
		_x = x + dirs[i][0];
		_y = y + dirs[i][1];
		while (in(_x, _y)){
			if (map[_x][_y] == WALL)
				break;
			else if (map[_x][_y] == HOUSE)
					return false;
			else if (map[_x][_y]==BLANK)
					map[_x][_y] = flag;
			_x = _x + dirs[i][0];
			_y = _y + dirs[i][1];
		}
	}
	return true;

}


void clear(int nn){
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	if (map[i][j] == nn)
		map[i][j] = BLANK;

}

void fun(int nn){
	
	if (!empty())
	{
		int sum = 0;
		for (int i = 0; i < n;++i)
		for (int j = 0; j < n;++j)
		if (map[i][j] == HOUSE)
			sum++;
		m = m>sum ? m : sum;
		return ;
	}
	for (int i = 0; i < n;++i)
	for (int j = 0; j < n;++j)
	if (map[i][j]== 0){
		map[i][j] = 3;
		if (!_fun(i, j,nn)){
			clear(nn);
			continue;
		}
		
		fun(nn+1);
		clear(nn);
		
		map[i][j] = 0;

	}



}
int main(){
	string s;
	//ifstream inn("C:\\temp.txt");
	while (cin >> n&&n){
		int i = 0;
		for(int i=0;i<n;++i) {
			cin >> s;
			for (int j = 0; j < n;++j)
				if (s[j] == '.')
					map[i][j] = BLANK;
				else if (s[j] == 'X')
					map[i][j] = WALL;
				else
					cout << "error" << endl;
		}	
		fun(10);
		cout << m << endl;
		m = 0;

	
	}

}*/



#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool map[5][5];
bool match[30][30];
struct Point {
	int x, y;
};
Point pp[5][5];
int link[30];
bool vis[30];

bool dfs(int n){
	for (int i = 0; i < 30;++i)
	if (!vis[i] && match[n][i]){
		vis[i] = 1;
		if (link[i] == -1 || dfs(link[i])){
			link[i] = n;
			return 1;
		}
	}



	return 0;
}


int main(){
//	ifstream in("C:\\temp.txt");
	int N;
	string s;
	while (cin >> N&&N){
		memset(match, 0, sizeof(match));
		memset(link, -1,  sizeof(link));
		for (int i = 0; i < N; ++i){
			cin >> s;
			for (int j = 0; j < N;++j)
			if (s[j] == '.')
				map[i][j] = 0;
			else
				map[i][j] = 1;
		}
		int x,y;
		x = y = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j){
			if (map[i][j] == 1 || j == 0)
				x++;
			if (map[i][j]==0)
			pp[i][j].x = x;
			if (map[j][i] == 1 || j == 0)
				y++;
			if (map[j][i]==0)
			pp[j][i].y = y;
		}
		for (int i = 0; i < N;++i)
		for (int j = 0; j < N; ++j)
			if(map[i][j]==0)
				match[pp[i][j].x][pp[i][j].y] = 1;

		int ans = 0;
		for (int i = 1; i < 30; ++i){
			memset(vis, 0, sizeof(vis));
			if (dfs(i))ans++;
		}
		cout << ans << endl;


	
	
	}

	return 0;
}