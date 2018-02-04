#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vi[10];

void Init(){
	vi[0].push_back(0);

	for (int i = 9; i >= 0; --i)
		vi[1].push_back(i);

	vi[2].push_back(9);
	vi[2].push_back(8);
	vi[2].push_back(6);
	vi[2].push_back(5);
	vi[2].push_back(3);
	vi[2].push_back(2);
	vi[2].push_back(0);

	vi[3].push_back(9);
	vi[3].push_back(6);
	vi[3].push_back(3);

	vi[4].push_back(9);
	vi[4].push_back(8);
	vi[4].push_back(7);
	vi[4].push_back(6);
	vi[4].push_back(5);
	vi[4].push_back(4);
	vi[4].push_back(0);

	vi[5].push_back(9);
	vi[5].push_back(8);
	vi[5].push_back(6);
	vi[5].push_back(5);
	vi[5].push_back(0);

	vi[6].push_back(9);
	vi[6].push_back(6);

	vi[7].push_back(9);
	vi[7].push_back(8);
	vi[7].push_back(7);
	vi[7].push_back(0);
	
	vi[8].push_back(9);
	vi[8].push_back(8);
	vi[8].push_back(0);

	vi[9].push_back(9);
}
int N;
char d[510];
int data[510], size, ans[510];
bool vis[10][510][2];

bool dfs(int pre,int dept,bool f){
	if (dept == size)
		return 1;
	if (vis[pre][dept][f])
		return 0;
	vis[pre][dept][f] = 1;
	for (int i = 0; i < vi[pre].size(); ++i){
		ans[dept] = vi[pre][i];
		if (!f && ans[dept] > data[dept])
			continue;
		bool nextf = f;
		if (!nextf)
			nextf = ans[dept] < data[dept];
		if (dfs(ans[dept], dept + 1,nextf))
			return 1;
	}
	return 0;
}

int main(){
	ifstream in("C:\\input.txt");
	Init();
	cin >> N;
	while (N--){
		cin >> d;
		memset(vis, 0, sizeof(vis));
		for (size = 0; d[size]; ++size)
			data[size] = d[size] - '0';
		dfs(1, 0, 0);
		for (int i = 0; i < size; ++i)
			printf("%d", ans[i]);
		printf("\n");




	}
	return 0;
}