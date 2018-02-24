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


#define pii pair<int,int>
#define mp make_pair
#define pb push_back
typedef long long LL;

int n, start, x;
int ask;
pii Q[50010];

pii query(int idx){
	while (idx <= n && Q[idx].first != -1)
		idx++;
	if (idx == n + 1){
		idx = 1;
		while (idx <= n && Q[idx].first != -1)
			idx++;
	}
	if (idx <= n && Q[idx].first == -1){
		ask++;
		fflush(stdout);
		printf("? %d\n", idx);
		fflush(stdout);
		in >> Q[idx].first >> Q[idx].second;
		return Q[idx];
	}
	else
		return mp(-1, -1);
}
int ans;
void update(int p){
	if (p >= x){
	//	cout << "update start : ";
	//	cout << p << endl;
		if (ans == -1){
			ans = p;
		}
		else{
			ans = min(ans, p);
		}
	}
}

void input(){
	in >> n >> start >> x;



}

pii MIN, MAX;
void upd(pii& p){
	if (p.first < x){
		MIN = max(MIN, p);
	}
	else{
		MAX = min(MAX, p);
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		memset(Q, -1, sizeof(Q));
		MIN.first = MIN.second = -1;
		MAX.first = MAX.second = (int)1e9 + 10;
		input();
		ans = -1;
		ask = 0;
		pii mmin = query(start);
		if (mmin.first >= x){
			update(mmin.first);
			fflush(stdout);
			printf("! %d\n", ans);
			fflush(stdout);
			return 0;
		}


		if (n <= 1999){
			for (int i = 1; i <= n; ++i){
				pii ret = query(i);
				update(ret.first);
			}

			fflush(stdout);
			printf("! %d\n", ans);
			fflush(stdout);
			return 0;
		}

		srand(time(0));
		while (ask <= 1999){
			if (MAX.first - MIN.first - 1 + ask <= 1998){
				int now = MIN.second;
				while (ask <= 1999){
					pii ret = query(now);
					update(ret.first);
					now = ret.second;
				}
				break;
			}
			int idx = rand() % n + 1;
			pii ret = query(idx);
			update(ret.first);
			upd(ret);
		}

		fflush(stdout);
		printf("! %d\n", ans);
		fflush(stdout);





	}


	return 0;
}





