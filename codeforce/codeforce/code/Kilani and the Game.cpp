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

#ifndef ONLINE_JUDGE
ifstream in("C:\\input.txt");
#endif

#ifdef ONLINE_JUDGE
istream& in = cin;
#endif


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  


int n, m, p;
LL s[10];
string str[1010];


void input(){
	in >> n >> m >> p;
	for (int i = 1; i <= p; ++i)
		in >> s[i];
	for (int i = 0; i < n; ++i){
		in >> str[i];
	}


}


int ans[10];
queue<pair<pii, int> > Q[10];
bool empty(){
	for (int i = 1; i <= p;++i)
	if (!Q[i].empty()){
		return 0;
	}
	return 1;
}

int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
bool IN(pii O){
	return O.first >= 0 && O.first < n &&O.second >= 0 && O.second < m;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		

		for (int i = 0; i < n;++i)
		for (int j = 0; j < m; ++j){
			if (str[i][j] == '.'){

			}
			else if (str[i][j] == '#'){

			}
			else{
				int k = str[i][j] - '0';
				ans[k]++;
				Q[k].push(mp(mp(i, j), 0));
			}
		}

		LL num = 0;
		while (!empty()){
			num++;
			for (int k = 1; k <= p; ++k){
				LL step = num * s[k];
				while (!Q[k].empty() && Q[k].front().second < step){
					pair<pii, int> now = Q[k].front();

					

					Q[k].pop();
					for (int d = 0; d < 4; ++d){
						pair<pii, int> son = mp(mp(now.first.first+dir[d][0],now.first.second+dir[d][1]), now.second + 1);
						if (IN(son.first) && str[son.first.first][son.first.second] == '.'){
							str[son.first.first][son.first.second] = '0' + k;
							ans[k]++;
							Q[k].push(son);
						}
					}
				}
			}
		}




		for (int i = 1; i <= p; ++i)
			cout << ans[i] << " ";
		cout << endl;








	}


	return 0;
}





