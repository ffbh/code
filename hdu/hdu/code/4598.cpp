#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;
vector<int> vi;
int  map[310][310];
bool vis[310];
int mark[310];
int N;

bool bfs(int s,int f){
	queue<int> qi;
	qi.push(s);
	vi.clear();
	mark[s] = f;
	vis[s] = 1;
	vi.push_back(s);
	while (!qi.empty()){
		int temp = qi.front();
		qi.pop();
		int Mark = (mark[temp] ^ 1);
		for (int i = 1; i <= N; ++i)
		if (map[temp][i]){
			if (vis[i]){
				if (Mark != mark[i])
					return 0;
			}
			else{
				vis[i] = 1;
				vi.push_back(i);
				mark[i] = Mark;
				qi.push(i);
			}
		}
	}
	return 1;
}



int main(){
	ifstream in("C:\\temp.txt");
	int T;
	in >> T;
	while (T--){
		in >> N;
		memset(vis, 0, sizeof(vis));
		memset(mark, 0, sizeof(mark));
		for (int i = 1; i <= N; ++i){
			string s;
			in >> s;
			for (int j = 0; j < N; ++j)
				map[i][j + 1] = s[j] - '0';
		}
		bool flag = 1;
		for (int i = 1; i <= N; ++i){
			if (vis[i])
				continue;
			if (!bfs(i, 0)){
				for (int j = 0; j < vi.size(); ++j)
					vis[vi[j]] = 0;
				if (!bfs(i, 1)){
					flag = 0;
					break;
				}
			}
		}
		if (flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}