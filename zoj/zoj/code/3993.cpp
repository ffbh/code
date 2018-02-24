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
#include <set>
#include <cassert>
using namespace std;

//ifstream in("C:\\input.txt");
istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back





LL N, R, r;

bool judge(LL x,LL y){
	if (R - r >= r){
		return x*x + y*y <= (R - r - r)*(R - r - r);

	}
	else{
		return x*x + y*y <= (2*r-R)*(2*r-R);
	}


}

int main(){

	int T;
	in >> T;
	while (T-- > 0){
		in >> N >> R >> r;
		vector<pll> all;
		for (int i = 1; i <= N; ++i){
			LL x, y;
			in >> x >> y;
			if (x*x+y*y > (R)*(R)){
				all.push_back(mp(-1e18, i));
			}
			else if (judge(x,y)){
				all.push_back(mp(1e18, i));
			}
			else{
				all.push_back(mp(-x*x-y*y, i));

			}



		}

		sort(all.begin(), all.end());
		LL aim = (--all.end())->first;
		vector<int> ans;
		for (pll p : all){
			if (p.first == aim){
				ans.push_back(p.second);
			}

		}


		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int i = 0; i < (int)ans.size() - 1; ++i){
			printf("%d ", ans[i]);
		}
		cout << ans.back() << endl;





	}


	return 0;
}





