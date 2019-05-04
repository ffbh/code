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
#define FFLUAHALL 	fflush(stdin);fflush(stdout);

int N;
string S[300];
bool vis[1000];

void input(){
	in >> N;
	for (int i = 1; i <= N; ++i)
		in >> S[i];


}



void _init(){

	memset(vis, 0, sizeof(vis));

}

char beat[300];

char rbeat[300];
int main(){

	beat['P'] = 'R';
	beat['R'] = 'S';
	beat['S'] = 'P';

	rbeat['R'] = 'P';
	rbeat['S'] = 'R';
	rbeat['P'] = 'S';

	int CPP = 1;

	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		

		int ok = -1;
		string ans = "";
		for (int p = 0; p < 130000; ++p){
			set<char> SS;
			for (int k = 1; k <= N; ++k){
				if (!vis[k]){
					SS.insert(S[k][p % S[k].length()]);
				}
			}
			if (SS.size() == 1){
				ok = 1;
				ans += rbeat[*(SS.begin())];
				break;
			}
			else if (SS.size() == 2){
				char c1 = *(SS.begin());
				char c2 = *(--SS.end());
				if (beat[c1] == c2){
					ans += c1;
					//SS.erase(c2);
					for (int k = 1; k <= N; ++k){
						if (S[k][p % S[k].length()] == c2){
							vis[k] = 1;
						}
					}
				}
				else{
					ans += c2;
				//	SS.erase(c1);
					for (int k = 1; k <= N; ++k){
						if (S[k][p % S[k].length()] == c1){
							vis[k] = 1;
						}
					}
				}
			}
			else if (SS.size() == 3){
				ok = 0;
				break;
			}
			else{
			//	assert(0);
			}
		}

		if (ok == -1){
			for (int p = 0; p < 130000; ++p){
				set<char> SS;
				for (int k = 1; k <= N; ++k){
					if (!vis[k]){
						SS.insert(S[k][p % S[k].length()]);
					}
				}
				if (SS.size() == 1){
					ok = 1;
					ans += rbeat[*(SS.begin())];
					break;
				}
				else if (SS.size() == 2){
					char c1 = *(SS.begin());
					char c2 = *(--SS.end());
					if (beat[c1] == c2){
						ans += c1;
						//SS.erase(c2);
						for (int k = 1; k <= N; ++k){
							if (S[k][p % S[k].length()] == c2){
								vis[k] = 1;
							}
						}
					}
					else{
						ans += c2;
						//	SS.erase(c1);
						for (int k = 1; k <= N; ++k){
							if (S[k][p % S[k].length()] == c1){
								vis[k] = 1;
							}
						}
					}
				}
				else if (SS.size() == 3){
					ok = 0;
					break;
				}
				else{
					//	assert(0);
				}
			}


		}
		

		printf("Case #%d: ", CPP++);
		if (ok){
			cout << ans << endl;
		}
		else{
			cout << "IMPOSSIBLE" << endl;
		}











	}


	return 0;
}





