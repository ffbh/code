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

int n, m1, m2, t;
int sm1[1000010], sm2[1000010];
bool stone[2][3000010];
int dis[3000010], size;
int dp[2][3000010];
pii pace[2][3000010];
void input(){
	in >> n >> m1 >> m2 >> t;

	for (int i = 1; i <= m1; ++i)
		//		in >> sm1[i];
		scanf("%d", &sm1[i]);

	for (int i = 1; i <= m2; ++i)
		//		in >> sm2[i];
		scanf("%d", &sm2[i]);
}


void adddis(int f1,int f2,int x){
	if (dis[size - 1] < x - 2){
		dis[size] = dis[size - 1] + 1;
		size++;
		dis[size++] = x - 1;
	}
	else if (dis[size - 1] == x - 2){
		dis[size++] = x - 1;
	}
	else{

	}
	if (f1)
		stone[0][size] = 1;
	if (f2)
		stone[1][size] = 1;
	dis[size++] = x;
}



void construct_map(){
	size = 1;
	int a, b;
	a = b = 1;
	dis[0] = 0;
	while (a <= m1 && b <= m2){
		if (sm1[a] == sm2[b]){
			adddis(1, 1, sm1[a++]);
			b++;
		}
		else if (sm1[a] < sm2[b]){

			adddis(1, 0, sm1[a++]);
		}
		else{
			
			adddis(0, 1, sm2[b++]);
		}
	}
	while (a <= m1){
		adddis(1, 0, sm1[a++]);
	}
	while (b <= m2){
		adddis(0, 1, sm2[b++]);
	}
	dis[size] = dis[size - 1] + 1;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		memset(dp, -1, sizeof(dp));
		construct_map();

		dp[0][0] = 0;
		pace[0][0] = mp(-1, -1);
		dp[1][0] = 0;
		pace[1][0] = mp(0, 0);

		for (int i = 0; i < size; ++i){
			for (int k = 0; k <= 1; ++k){
				if (dp[k][i] != -1){
					int cost = 0, time = dis[i + 1] - dis[i];
					if (stone[k][i + 1]){
						cost = t;
					}
					int val = dp[k][i] + time - cost;

					if (val>0 && dp[k][i + 1] < val){
						dp[k][i + 1] = val;
						pace[k][i + 1] = mp(k, i);
						if (stone[1 - k][i + 1] == 0){
							int now = min(t, dp[k][i + 1]);
							if (dp[1 - k][i + 1] < now){
								dp[1 - k][i + 1] = now;
								pace[1 - k][i + 1] = mp(k, i + 1);
							}
						}
					
					}
				}
			}
		}

		if (dp[0][size] != -1){
			cout << "Yes" << endl;
			int a, b;
			a = 0;
			b = size;
			vector<int> pp;
			vector<pii> block;
			while (a + b){
				if (stone[a][b]){
					block.push_back(mp(b,a));
				}
				pii& pre = pace[a][b];
				if (a != pre.first){
					pp.push_back(dis[pre.second]);
				}
				a = pre.first;
				b = pre.second;
			}
			printf("%d\n", pp.size());
			for (int i = (int)pp.size() - 1; i >= 0; --i){
				printf("%d ", pp[i]);
			}
			printf("\n");
			printf("%d\n", block.size());
			if (!block.empty()){
				vector<pii> fire;
				int limit = dis[block[0].first];
				for (pii d : block){
					int now = dis[d.first] - 1;
					now = min(now, limit);
					fire.push_back(mp(now,d.second));
					limit = now - t;
				}
				
				for (int i = (int)fire.size() - 1; i >= 0; --i){
					printf("%d %d\n", fire[i].first, fire[i].second + 1);
				}
			
			}
			
		}
		else{
			cout << "No" << endl;
		}







	}


	return 0;
}





