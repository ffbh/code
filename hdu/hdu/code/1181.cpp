#include <iostream>
#include <string>
//#include <fstream>
using namespace std;
bool dp[30][30];
bool link[30];
bool vis[30];
void dfs(int dd){
	vis[dd] = 1;
	for (int i = 0; i < 30;++i)
	if (dp[dd][i]&&!vis[i]&&i!=dd){
		link[i] = 1;
		dfs(i);
	}

}
int main(){
	//ifstream in("C:\\temp.txt");
	string s;
	while (cin >> s){
		memset(dp, 0, sizeof(dp));
		memset(link, 0, sizeof(link));
		memset(vis, 0, sizeof(vis));
		dp[s[0] - 'a'][s[s.length() - 1] - 'a'] = 1;
		while (cin >> s&&s != "0")dp[s[0] - 'a'][s[s.length() - 1] - 'a'] = 1;
		dfs(1);
		if (link['m' - 'a'])
			cout << "Yes." << endl;
		else cout << "No." << endl;
	
	}

	return 0;
}