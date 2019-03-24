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

int N, M;
string str[300];


void input(){
	in >> N >> M;
	for (int i = 0; i < N; ++i)
		in >> str[i];


}

inline int get_dis(int x1,int y1,int x2,int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int dirs[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int D[300][300];

inline bool IN(pii p){
	return p.first >= 0 && p.first < N&&p.second >= 0 && p.second < M;
}
void first_bfs(){
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M; ++j)
		D[i][j] = (int)1e8;

	queue<pii> Q;
	for (int i = 0; i < N;++i)
	for (int j = 0; j < M; ++j){
		if (str[i][j] == '1'){
			Q.push(mp(i, j));
			D[i][j] = 0;
		}
	}

	while (!Q.empty()){
		pii u = Q.front();
		Q.pop();
		for (int k = 0; k < 4; ++k){
			pii v = mp(u.first + dirs[k][0], u.second + dirs[k][1]);
			if (IN(v) && D[v.first][v.second] > D[u.first][u.second] + 1){
				D[v.first][v.second] = D[u.first][u.second] + 1;
				Q.push(v);
			}
		}
	}
}


int special_bfs(int a,int b){
	assert(str[a][b] == '0');
	str[a][b] = '1';
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j)
		D[i][j] = (int)1e8;

	queue<pii> Q;
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j){
		if (str[i][j] == '1'){
			Q.push(mp(i, j));
			D[i][j] = 0;
		}
	}

	while (!Q.empty()){
		pii u = Q.front();
		Q.pop();
		for (int k = 0; k < 4; ++k){
			pii v = mp(u.first + dirs[k][0], u.second + dirs[k][1]);
			if (IN(v) && D[v.first][v.second] > D[u.first][u.second] + 1){
				D[v.first][v.second] = D[u.first][u.second] + 1;
				Q.push(v);
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < M; ++j){
		ret = max(ret, D[i][j]);
	}

	str[a][b] = '0';
	return ret;
}



int main(){
	int CPP = 1;

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		int num = 0;
		for (int i = 0; i < N;++i)
		for (int j = 0; j < M;++j)
		if (str[i][j] == '0'){
			num++;
		}
		int ans = (int)1e8;
		if (num <= 1){
			ans = 0;
		}
		else if (num == N * M){
			int mid_x = N / 2;
			int mid_y = M / 2;
			ans = min(ans, get_dis(mid_x, mid_y, 0, 0));
			ans = min(ans, get_dis(mid_x, mid_y, 0, M-1));
			ans = min(ans, get_dis(mid_x, mid_y, N-1, 0));
			ans = min(ans, get_dis(mid_x, mid_y, N-1, M-1));
		}
		else{
			first_bfs();
			vector<pair<int, pii>> VP;
			for (int i = 0; i < N;++i)
			for (int j = 0; j < M; ++j){
				if (D[i][j] != 0)
				VP.push_back(mp(D[i][j], mp(i, j)));

			}
			
			sort(VP.begin(), VP.end(), greater<pair<int, pii>>());
			for (int i = 0; i < N;++i)
			for (int j = 0; j < M; ++j){
				if (str[i][j] == '0'){
					int ret = 0;
					for (auto p : VP){
						if (p.first <= ret)
							break;
						ret = max(ret, min(p.first,get_dis(p.second.first, p.second.second, i, j)));
						if (ret >= ans)
							break;
					}
					ans = min(ans, ret);
				}
			}



		}


		printf("Case #%d: %d\n", CPP++, ans);









	}


	return 0;
}





