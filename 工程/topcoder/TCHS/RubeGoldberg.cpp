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

unordered_map<string, int> usi;
bool dp[4][500100];

struct Node{
	int to, d;
	Node(int a, int b){
		to = a;
		d = b;
	}
};
int MAX_T;
vector<Node> V[4];
stringstream ss;
class RubeGoldberg {
public:
	int howClose(vector <string> parts, string last, int target) {

		memset(dp, 0, sizeof(dp));
		usi.clear();
		for (int i = 0; i < 4; ++i)
			V[i].clear();
		usi["CHEMICAL"] = 0;
		usi["ELECTRIC"] = 1;
		usi["MECHANICAL"] = 2;
		usi["THERMAL"] = 3;
		MAX_T = target * 2 + 10;
	
		for (int i = 0; i < parts.size(); ++i){
			ss.clear();
			ss.str(parts[i]);
			string a, b;
			int t;
			ss >> a >> b >> t;
			V[usi[a]].push_back(Node(usi[b], t));
		}
		int LAST = usi[last];
		for (int i = 0; i < 4; ++i)
			dp[i][0] = 1;
		int ans = target;
		for (int k = 0; k <= MAX_T; ++k){
			for (int j = 0; j < 4; ++j){
				if (dp[j][k]){
					for (int i = 0; i < V[j].size(); ++i){
						int nk = k + V[j][i].d;
						int to = V[j][i].to;
						if (nk <= MAX_T){
							dp[to][nk] = 1;
							if (to == LAST){
								ans = min(ans, abs(target - nk));
							}
						}
					}
				}
			}
		}
		return ans;
	}
};



#if DEBUG
int main(){
	vector<string> p({ "MECHANICAL THERMAL 12", "CHEMICAL ELECTRIC 228",
		"CHEMICAL CHEMICAL 3361", "ELECTRIC ELECTRIC 4312",
		"ELECTRIC CHEMICAL 1123", "THERMAL MECHANICAL 15000",
		"MECHANICAL MECHANICAL 15000", "THERMAL THERMAL 20000" });


	RubeGoldberg so;
	cout << so.howClose(p, "THERMAL", 13579) << endl;
















	return 0;
}
#endif

