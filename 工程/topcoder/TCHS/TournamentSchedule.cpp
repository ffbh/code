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
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
using namespace std;
#define DEBUG 0

stringstream ss;
class TournamentSchedule {
public:
	bool vis[6];
	vector<vector< pair<int, int> > > all;
	vector<pair<int, int> > tmp;
	void slove(int n){
		if (tmp.size() == n / 2){
			all.push_back(tmp);
			sort(all.back().begin(), all.back().end());
			return;
		}
		for (int i = 0; i < n; ++i){
			for (int j = i+1; j < n; ++j){
				if (!vis[i] && !vis[j] && i!= j){
					vis[i] = vis[j] = 1;
					tmp.push_back(make_pair(i, j));
					slove(n);
					tmp.pop_back();
					vis[i] = vis[j] = 0;
				}
			}
		}
	}


	int match[6][6];
	int test[6][6];
	int end_round;
	int ans = 0;
	vector<int> temp;
	void dfs(int round){
		if (round == end_round){
			bool ok = 1;
			for (int i = 0; i < 6; ++i)
			for (int j = 0; j < 6; ++j){
				if (test[i][j] != -1 && match[i][j] != test[i][j]){
					ok = 0;
				}
			}
			if (ok){
				ans++;

			}
			return;
		}
		for (int i = 0; i < all.size(); ++i){
			bool ok = 1;
			for (int j = 0; j < all[i].size(); ++j){
				if (match[all[i][j].first][all[i][j].second] != -1){
					ok = 0;
					break;
				}
			}
			if (ok){
				
				for (int j = 0; j < all[i].size(); ++j){

					match[all[i][j].first][all[i][j].second] = match[all[i][j].second][all[i][j].first] = round;

				}
				temp.push_back(i);
				dfs(round + 1);
				temp.pop_back();
				for (int j = 0; j < all[i].size(); ++j){

					match[all[i][j].first][all[i][j].second] = match[all[i][j].second][all[i][j].first] = -1;

				}
			}
		}
	}



	int ways(int numTeams, vector <string> preferences) {
		memset(match, -1, sizeof(match));
		memset(test, -1, sizeof(test));
		memset(vis, 0, sizeof(vis));
		tmp.clear();
		temp.clear();
		ans = 0;
		end_round = numTeams - 1;
		bool ok = 1;
		for (int i = 0; i < preferences.size(); ++i){
			string t = preferences[i];
			for (int j = 0; j < t.size(); ++j){
				if (!isdigit(t[j])){
					t[j] = ' ';
				}
			}
			ss.clear();
			ss.str(t);
			int a, b, c;
			ss >> a >> b >> c;
			if (test[b][c] == -1 || test[b][c]==a){
				test[b][c] = test[c][b] = a;
			}
			else{
				ok = 0;
			}
		}
		if (!ok)
			return 0;
		slove(numTeams);
		sort(all.begin(), all.end());
		all.erase(unique(all.begin(), all.end()), all.end());
		

		dfs(0);


		return ans;

	}
};



#if DEBUG
int main(){
	vector<string> p({ "0:3-4", "3:2-1", "4:1-4" });
	TournamentSchedule so;
	cout<<so.ways(6,p)<<endl;
















	return 0;
}
#endif

