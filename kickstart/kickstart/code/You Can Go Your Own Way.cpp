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

int n;
string p;


void input(){
	in >> n;
	in >> p;

	n--;
}

void run(int& x, int& y, char c){
	if (c == 'E'){
		x++;
	}
	else{
		y++;
	}
	assert(x <= n&&y <= n);
}

int main(){
	int CPP = 1;
	int TEST_CASE = 1;
	in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		
		string ans = "";
		int now_x, now_y, m_x, m_y;
		int need = n;
		now_x = now_y = m_x = m_y = 0;
		if (p.back() == 'E'){
			for (int i = 0; i < p.length() && need; ++i){
				if (now_x != m_x || now_y != m_y){
					ans += 'E';
					need--;
					run(now_x, now_y, 'E');
					run(m_x, m_y, p[i]);
				}
				else{
					if (p[i] == 'E'){
						ans += 'S';
						run(now_x, now_y, 'S');
						run(m_x, m_y, p[i]);
					}
					else{
						ans += 'E';
						need--;
						run(now_x, now_y, 'E');
						run(m_x, m_y, p[i]);
					}
				}
			}

			while (ans.length() < 2 * n){
				ans += 'S';
			}

		}
		else{
			for (int i = 0; i < p.length() && need; ++i){
				if (now_x != m_x || now_y != m_y){
					ans += 'S';
					need--;
					run(now_x, now_y, 'S');
					run(m_x, m_y, p[i]);
				}
				else{
					if (p[i] == 'S'){
						ans += 'E';
						run(now_x, now_y, 'E');
						run(m_x, m_y, p[i]);
					}
					else{
						ans += 'S';
						need--;
						run(now_x, now_y, 'S');
						run(m_x, m_y, p[i]);
					}
				}
			}

			while (ans.length() < 2 * n){
				ans += 'E';
			}



		}
		printf("Case #%d: ", CPP++);

		cout << ans << endl;











	}


	return 0;
}





