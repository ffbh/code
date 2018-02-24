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
#define DEBUG (0)


class Touchdown {
public:
	int ans;
	int yard;
	vector<int> tmp, p;
	bool dp[5][40];
	int pace[5][40];
	bool vis[20];
	bool AJ(vector<int>& arr){
		int sum = 0;
		for (int i = 0; i < arr.size(); ++i)
			sum += arr[i];
		return sum >= 10;
	}
	bool BJ(vector<int>& arr){


		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		dp[0][0] = 1;
		for (int k = 0; k < arr.size(); ++k){
			int& val = arr[k];
			for (int i = 4; i > 0; --i)
			for (int j = 29; j >= val; --j){
				if (!dp[i][j] && dp[i - 1][j - val]){
					dp[i][j] = 1;
					pace[i][j] = k;
				}
			}
		}
		vector<int> P;
		bool ok = 0;
		for (int i = 10; i < 30; ++i){
			if (dp[4][i]){
				ok = 1;
				int all = i;
				int k = 4;
				while (k>0){
					vis[pace[k][all]] = 1;
					all -= arr[pace[k][all]];
					k--;
				}
				break;
			}
		}
		for (int i = 0; i < arr.size(); ++i){
			if (!vis[i]){
				P.push_back(arr[i]);
			}
		}
		return ok && AJ(P);


	}


	bool CJ(vector<int>& arr){
		memset(dp, 0, sizeof(dp));
		memset(vis, 0, sizeof(vis));
		dp[0][0] = 1;
		for (int k = 0; k < arr.size(); ++k){
			int& val = arr[k];
			for (int i = 4; i > 0; --i)
			for (int j = 29; j >= val; --j){
				if (!dp[i][j] && dp[i - 1][j - val]){
					dp[i][j] = 1;
					pace[i][j] = k;
				}
			}
		}
		vector<int> P;
		bool ok = 0;
		for (int i = 10; i < 30; ++i){
			if (dp[4][i]){
				ok = 1;
				int all = i;
				int k = 4;
				while (k>0){
					vis[pace[k][all]] = 1;
					all -= arr[pace[k][all]];
					k--;
				}
				break;
			}
		}
		for (int i = 0; i < arr.size(); ++i){
			if (!vis[i]){
				P.push_back(arr[i]);
			}
		}
		return ok && BJ(P);
	}


	bool judge(vector<int> play){
		sort(play.begin(), play.end());
		int move = play.size() % 4;
		if (move == 0){
			move = 4;
		}
		int st = move;
		int en = play.size() - 1;
		while (en >= 0 && play[en] >= 7){
			en--;
			st += 3;
		}
		vector<int> P;
		for (int i = st; i <= en; ++i)
			P.push_back(play[i]);
		switch (P.size() / 4){
		case 1:
			return AJ(P);
			break;
		case 2:
			return BJ(P);
			break;
		case 3:
			return CJ(P);
			break;
		}
		return 1;


	}


	void dfs(int pos, int sum){
		if (pos == p.size()){
			if (sum >= yard && sum <= yard + 10){
				if (judge(tmp)){
					if (ans == -1 || ans > tmp.size()){
						ans = tmp.size();
					}
				}

			}
			return;
		}
		dfs(pos + 1, sum);

		tmp.push_back(p[pos]);
		dfs(pos + 1, sum + p[pos]);
		tmp.pop_back();
	}



	int howMany(int yardsToGo, vector <int> plays) {
		ans = -1;
		tmp.clear();

		p = plays;
		yard = yardsToGo;

		dfs(0, 0);
		return ans;

	}
};


#if DEBUG
int main(){
	vector<int> p({ 2, 1, 2, 3, 1, 3, 3, 1, 2, 2 });
	Touchdown so;
	cout << so.howMany(19, p) << endl;
















	return 0;
}
#endif

