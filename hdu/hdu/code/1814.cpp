#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
vector<int> vi[16001];
stack<int> si;
bool mark[16001];

bool dfs(int x){
	if (mark[x ^ 1])
		return 0;
	if (mark[x])
		return 1;
	mark[x] = 1;
	si.push(x);
	for (int i = 0; i<vi[x].size();++i)
	if (!dfs(vi[x][i]))
		return 0;
	return 1;
}



int main(){
//	ifstream in("C:\\temp.txt");
	int N, M;
	while (cin >> N >> M){
		queue<int> qi;
		memset(mark, 0, sizeof(mark));
		for (int i = 0; i <= 2 * N; ++i)
			vi[i].clear();
		while (M--){
			int a, b;
		//	cin >> a >> b;
			scanf("%d%d", &a, &b);
			a--;
			b--;
			vi[a].push_back(b ^ 1);
			vi[b].push_back(a ^ 1);
		}
		bool flag = 1;
		for (int i = 0; i < 2 * N;i+=2)
		if (!mark[i] && !mark[i + 1]){
			while (!si.empty())
				si.pop();
			if (!dfs(i)){
				while (!si.empty()){
					mark[si.top()] = 0;
					si.pop();
				}
				if (!dfs(i + 1)){
					flag = 0;
					break;
				}
				else
					qi.push(i + 1);
			}
			else
				qi.push(i);
		}
		else{
			qi.push(mark[i] ? i : i + 1);
		}
		if (!flag)
			cout << "NIE" << endl;
		else
		while (!qi.empty()){
			cout << qi.front()+1 << endl;
			qi.pop();
		}
	}
	return 0;
}