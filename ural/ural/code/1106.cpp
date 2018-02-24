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
int N, num;
void Init(){
	for (int i = 0; i < 110; ++i)
		vi[i].clear();
	memset(mark, -1, sizeof(mark));
	num = 0;
}

void bfs(int s){
	queue<int> qi;
	mark[s] = 0;
	qi.push(s);
	while (!qi.empty()){
		int u = qi.front();
		if (mark[u] == 0)
			num++;
		qi.pop();
		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i];
			if (mark[v] != -1)
				continue;
			mark[v] = 1 - mark[u];
			qi.push(v);
		}
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	while (cin >> N){
		Init();
		bool f = 1;
		for (int i = 1; i <= N; ++i){
			int v;
			while (cin >> v&&v){
				vi[i].push_back(v);
			}
			if (vi[i].size() == 0)
				f = 0;
		}
		if (!f)
			cout << 0 << endl;
		else{
			for (int i = 1; i <= N;++i)
			if (mark[i] == -1){
				bfs(i);
			}
			cout << num << endl;
			bool kk = 0;
			for (int i = 1; i <= N; ++i){
				if (mark[i] == 0){
					if (kk){
						printf(" %d", i);
					}
					else{
						kk = 1;
						printf("%d", i);
					}
				}

			}
			cout << endl;
		}



	}

















	return 0;
}