#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;
int N, M;
vector<int> vi[2010];
stack<int> temp;
int map[3001];
int cnt;
bool mark[2010];


bool dfs(int x){
	if (mark[x ^ 1])
		return 0;
	if (mark[x])
		return 1;
	mark[x] = 1;
	temp.push(x);
	for (int i = 0; i < vi[x].size();++i)
	if (!dfs(vi[x][i]))
		return 0;
	return 1;
}


int main(){
//	ifstream in("C:\\temp.txt");
	while (cin >> N >> M){
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i <= 2 * N; ++i)
			vi[i].clear();
		int a, b, c;
		cnt = 0;
		for (int i = 0; i < N; ++i){
			//in >> a >> b >> c;
			scanf("%d%d%d", &a, &b, &c);
			map[a] = cnt++;
			map[b] = map[c] = cnt++;
		}
		while (M--){
			//in >> a >> b;
			scanf("%d%d", &a, &b);
			if (map[a] == map[b])
				mark[map[a] ^ 1] = 1;
			else{
				vi[map[a]].push_back(map[b] ^ 1);
				vi[map[b]].push_back(map[a] ^ 1);
			}
		}
		bool flag = 1;
		for (int i = 0; i < 2 * N;i+=2)
		if (!mark[i] && !mark[i + 1]){
			while (!temp.empty())
				temp.pop();
			if (!dfs(i)){
				while (!temp.empty()){
					mark[temp.top()] = 0;
					temp.pop();
				}
				if (!dfs(i + 1)){
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}