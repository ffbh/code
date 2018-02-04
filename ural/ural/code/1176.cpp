#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;

int N, S;
bool mark[1010][1010];
bool vis[1010];
vector<int> vi[1010];
void Init(){
	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < 1010; ++i)
		vi[i].clear();
}

void dfs(int s){


	for (int i = 1; i <= N; ++i){
		if (i == s)
			continue;
		if (!mark[s][i]){
			mark[s][i] =  1;
			printf("%d %d\n",s, i);
			dfs(i);
			
		}
	}
}


int main(){
	ifstream in("C:\\input.txt");
	while (in >> N >> S){
		Init();
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			in >> mark[i][j];
		dfs(S);
	}

	return 0;
}