#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<int> vi[110];
int mark[110];
int N, tmp;
void Init(){
	for (int i = 0; i < 110; ++i)
		vi[i].clear();
	memset(mark, -1, sizeof(mark));
}

bool bfs(int start){
	queue<int> qi;
	mark[start] = 0;
	qi.push(start);
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i];
			if (mark[v] == -1){
				mark[v] = 1 - mark[u];
				qi.push(v);
			}
			else{
				if (mark[u] != 1 - mark[v])
					return 0;

			}
		}
	}

	return 1;

}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N){
		Init();
		for (int i = 1; i <= N; ++i){
			while (cin >> tmp&&tmp){
				vi[i].push_back(tmp);
				vi[tmp].push_back(i);
			}
		}
		
		bool f = 1;

		for (int i = 1; i <= N; ++i){
			if (mark[i] == -1){
				if (!bfs(i)){
					f = 0;
					break;
				}
			}
		}

		if (f){
			for (int i = 1; i <= N; ++i)
				cout << mark[i];
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}

	}
















	return 0;
}