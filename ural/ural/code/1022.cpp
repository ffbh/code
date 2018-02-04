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
int N, t;
vector<int> vi[110];
int INnum[110];
void Init(){
	for (int i = 0; i < 110; ++i)
		vi[i].clear();
	memset(INnum, 0, sizeof(INnum));
}

void topsort(){
	queue<int> qi;
	for (int i = 1; i <= N;++i)
	if (INnum[i] == 0){
		qi.push(i);
	}
	bool f = 1;
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		if (f){
			f = 0;
			printf("%d", u);
		}
		else{
			printf(" %d", u);
		}

		for (int i = 0; i < vi[u].size(); ++i){
			int v = vi[u][i];
			if (--INnum[v] == 0){
				qi.push(v);
			}
		}
	}
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N){
		for (int i = 1; i <= N; ++i){
			while (cin >> t&&t){
				vi[i].push_back(t);
				INnum[t]++;
			}
		}
		topsort();
	}
















	return 0;
}