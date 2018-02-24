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


stringstream ss;

int dp[110][2][210][210];
vector<int> L, R;
int MAXT, UNITS, CROSST;
int cale(int bank, int a, int b, int time){
	int ref = 0;
	if (bank == 1){
		swap(a, b);
	}
	while (a > 0 || b > 0){
		if (a >= UNITS){
			ref += time * UNITS;
			a -= UNITS;
		}
		else{
			ref += time * a;
			a = 0;
		}
		time += CROSST;
		swap(a, b);
	}
	return ref;
}
int dfs(int time, int bank, int a, int b){
	if (time >= MAXT){
		return cale(bank, L.size() - a, R.size() - b, time);
	}
	else{
		int& ref = dp[time][bank][a][b];
		if (ref != -1)
			return ref;
		ref = dfs(time + CROSST, 1 - bank, a, b);

		if (bank == 0){
			int st = a, en = min(a + UNITS, (int)L.size());
			int tmp = 0;
			for (int i = st; i < en; ++i){
				tmp += max(time, L[i]);
				int ret = tmp + dfs(max(time, L[i]) + CROSST, 1 - bank, i + 1, b);
				ref = min(ref, ret);
			}
		}
		else{
			int st = b, en = min(b + UNITS, (int)R.size());
			int tmp = 0;
			for (int i = st; i < en; ++i){
				tmp += max(time, R[i]);
				int ret = tmp + dfs(max(time, R[i]) + CROSST, 1 - bank, a, i + 1);
				ref = min(ref, ret);
			}
		}
	}
	return dp[time][bank][a][b];
}



class RiverCrossing {
public:
	int minimalWait(vector <string> cargo, int units, int T) {

		memset(dp, -1, sizeof(dp));
		int sum = 0;
		MAXT = 0;
		UNITS = units;
		CROSST = T;
		L.clear();
		R.clear();
		for (int i = 0; i < cargo.size(); ++i){
			ss.clear();
			ss.str(cargo[i]);
			int unit, time;
			string bank;
			ss >> unit >> time >> bank;
			MAXT = max(MAXT, time);
			if (bank == "left"){
				for (int i = 0; i < unit; ++i){
					L.push_back(time);
				}
			}
			else{
				for (int i = 0; i < unit; ++i){
					R.push_back(time);
				}
			}
			sum += unit*time;
		}

		return dfs(0, 0, 0, 0) - sum;

	}
};



#if DEBUG
int main(){

	RiverCrossing so;
	cout << so.minimalWait() << endl;
















	return 0;
}
#endif



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
