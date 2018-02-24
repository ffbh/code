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
#define INF (1<<20)
stringstream ss;
bool ok[11];
int N;
bool judge(int code){
	for (int i = 0; i < N; ++i){
		if ((1 << i)&code){
			if (!ok[i])
				return 0;
		}
	}
	return 1;
}

int cnt(int code){
	int num = 0;
	for (int i = 0; i < N; ++i){
		if ((1 << i)&code){
			num++;
		}
	}
	return num;
}

int num[11];
string tmp;
int dfs(int pos,int c){
	if (pos == N){
		return INF;
	}
	bool E = 1;
	for (int i = 0; i < N; ++i){
		if (tmp[i] == '*' && num[i] == 0){
			E = 0;
			break;
		}
	}
	if (E){
		return c;
	}
	int ret = dfs(pos + 1,c);
	if (pos + 4 < N){
		bool p = 1;
		for (int i = pos; i < pos + 5; ++i){
			if (tmp[i] == '.'){
				p = 0;
				break;
			}
		}
		if (p){
			for (int i = pos; i < pos + 5; ++i){
				num[i]++;
			}
			int r = dfs(pos + 1, c + 1);
			ret = min(ret, r);
			for (int i = pos; i < pos + 5; ++i){
				num[i]--;
			}
		}
	}
	return ret;
}

int cale(string s,int code){
	tmp = s;
	memset(num, 0, sizeof(num));
	for (int i = 0; i < N; ++i){
		if ((1 << i)&code){
			num[i] = 1;
		}
	}
	return dfs(0,0);
}


class FiveStarPatterns {
	public:
	int leastLines(vector <string> layout) {
		memset(ok, 0, sizeof(ok));	
		N = layout[0].size();
		if (layout.size() == 5){
			for (int i = 0; i < N; ++i){
				bool p = 1;
				for (int j = 0; j < 5; ++j){
					if (layout[j][i] == '.'){
						p = 0;
						break;
					}
				}
				ok[i] = p;
			}
		}





		int ans = INF;
		for (int i = 0; i < (1 << N); ++i){
			if (!judge(i))
				continue;
			int ret = cnt(i);
			for (int j = 0; j < layout.size(); ++j){
				ret += cale(layout[j], i);
			}
			ans = min(ans, ret);
		}
		if (ans >= INF)
			return -1;
		else
			return ans;

	}
};



#if 0
int main(){
	vector<string>p(
	{
		"......",
		".****.",
		".****.",
		".****.",
		".****."
	});
	FiveStarPatterns so;
	cout<<so.leastLines(p)<<endl;
















	return 0;
}
#endif

