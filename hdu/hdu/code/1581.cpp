#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
bool vis[50];
vector<int> ans;
void clean(){
	for (int i = 2; i < 20;++i)
	if (vis[i])
	for (int j = i + 1; j < 20;++j)
	if (vis[j])
		vis[i + j] = 1;
}

bool dfs(int num,bool flag){
	if (num == 0)
		return 0;
	bool K[50];
	memcpy(K, vis, sizeof(K));
	for (int i = 2; i < 20;++i)
	if (!vis[i]){
		vis[i] = 1;
		clean();
		int cnt = 0;
		for (int j = 2; j < 20; ++j)
		if (!vis[j])
			cnt++;
		if (!dfs(cnt,0)){
			if (!flag)
				return 1;
			else
				ans.push_back(i);
		}
		memcpy(vis, K, sizeof(vis));
	}
	return 0;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	int CASE = 1;
	while (T--){
		ans.clear();
		memset(vis, 1, sizeof(vis));
		int N;
		cin >> N;
		while (N--){
			int t;
			cin >> t;
			vis[t] = 0;
		}
		int cnt = 0;
		for (int i = 2; i < 20; ++i)
		if (!vis[i])
			cnt++;
		dfs(cnt, 1);
		printf("Scenario #%d:\n", CASE++);
		if (ans.empty())
			cout << "There is no winning move." << endl;
		else{
			cout << "The winning moves are: ";
			for (int i = 0; i < ans.size() - 1; ++i)
				cout << ans[i] << " ";
			cout << ans[ans.size() - 1];
			printf(".\n");
		}
	}
	return 0;
}