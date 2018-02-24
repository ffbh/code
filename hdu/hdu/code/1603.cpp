#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
struct Node{
	bool map[4][4];
	int area;
	int h, w;
	bool operator<(const Node& p)const{
		return area>p.area;
	}
};

int cnt;
Node data[100];
int map[4][4];
bool DFS(int now,int f){
	if (now == cnt)
		return 1;
	for (int i = 0; i < 4;++i)
	for (int j = 0; j < 4;++j)
	if (data[now].w + j <= 4 && data[now].h + i <= 4){
		bool flag = 0;
		for (int ti = i; ti < i + data[now].h&&flag==0;++ti)
		for (int tj = j; tj < j + data[now].w;++tj)
		if (map[ti][tj] == 0||data[now].map[ti-i][tj-j]==0){
			if (data[now].map[ti - i][tj-j])
				map[ti][tj] = f;
		}
		else{
			flag = 1;
			break;
		}
		if (flag){
			for (int ti = i; ti < i + data[now].h; ++ti)
			for (int tj = j; tj < j + data[now].w; ++tj)
			if (map[ti][tj] == f)
				map[ti][tj] = 0;
		}
		else{
			if (DFS(now + 1, f + 1))
				return 1;
			for (int ti = i; ti < i + data[now].h; ++ti)
			for (int tj = j; tj < j + data[now].w; ++tj)
			if (map[ti][tj] == f)
				map[ti][tj] = 0;
		}
	}
	return 0;
}




int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	while (cin >> cnt&&cnt){
		memset(map, 0, sizeof(map));
		int sum = 0;
		for (int i = 0; i < cnt; ++i){
			data[i].area = 0;
			cin >> data[i].h >> data[i].w;
			for (int j = 0; j < data[i].h; ++j){
				cin >> s;
				for (int now = 0; now < data[i].w; ++now){
					if (s[now] == '1'){
						data[i].area++;
						data[i].map[j][now] = 1;
					}
					else
						data[i].map[j][now] = 0;
				}
			}
			sum += data[i].area;
		}
		if (sum != 16){
			cout << "No solution possible" << endl;
			
		}	
		else{
			if(DFS(0, 1))
			for (int i = 0; i < 4; ++i){
				for (int j = 0; j < 4; ++j)
					cout << map[i][j];
				cout << endl;
			}
			else
				cout << "No solution possible" << endl;

		}
		cout << endl;
	}

	return 0;
}