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
unordered_set<int> S[200010];
unordered_set<int> ORIGIN[200010];
int degree[200010];

void input(){
	in >> n;
//	scanf("%d", &n);
	for (int i = 1; i < n; ++i){
		int a, b;
		in >> a >> b;
	//	scanf("%d%d", &a, &b);
		S[a].insert(b);
		S[b].insert(a);
		ORIGIN[a].insert(b);
		ORIGIN[b].insert(a);
		degree[a]++;
		degree[b]++;
	}


}





bool mark[200010];
int dfs(int p,int f){
	int num = 0;
	for (int son : S[p]){
		if (son == f)
			continue;
		int ret = dfs(son, p);

		int X = n - ret;
		if (X > ret){
			mark[son] = 1;
		}
		else if (X < ret){
			mark[p] = 1;
		}
		
		num += ret;
	}
	
	return num + 1;
}

int a[400010], b[400010], c[400010], NUM;

void add(int x, int y1, int y2){
	a[NUM] = x;
	b[NUM] = y1;
	c[NUM] = y2;
	NUM++;
}


inline void add_edge(int a,int b){
	S[a].insert(b);
	S[b].insert(a);
}

inline void del_edge(int a,int b){
	S[a].erase(b);
	S[b].erase(a);
}

pii update(int p,int f){
	if (p == 9){
		int t = 0;
	}
	vector<pii> leaf;
	for (int son : ORIGIN[p]){
		if (son == f)
			continue;
		pii ll = update(son, p);
		leaf.push_back(ll);
	}
	if (leaf.empty()){
		return mp(p,p);
	}
	else {
		int F = f;
		int sss = -1;
		while (leaf.size() > 1){
			int down = leaf.back().first;
			int up = leaf.back().second;
			add(F, p, down);
			add_edge(F, down);
			del_edge(F, p);
			F = up;
			if (sss == -1){
				sss = down;
			}
			leaf.pop_back();
		}
		if (sss == -1)
			sss = p;
		return mp(leaf.back().first,sss);
	}
}


int arr[200010], len;
void get(int p,int f){
	//cout << p << " " << f << endl;
	if (S[p].size() > 2){
		int t = 0;
	}
	for (int son : S[p]){
		if (son == f){
			continue;
		}
		get(son, p);
	}
	arr[len++] = p;
//	cout << len << endl;
}


int rrr(int a, int b){
	int lll = b - a + 1;
	int rr = abs(rand()) % lll;
	return a + rr;

}

void general(int n){
	ofstream out("C:\\input.txt");
	srand(time(0));
	out << n << endl;
	for (int i = 2; i <= n; ++i){
		out << i << " " << rrr(1, i - 1) << endl;
	}
	out.close();
}

int main(){

	//general(20);
	


	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		NUM = 0;
		int root = -1;
		for (int i = 1; i <= n; ++i){
			if (degree[i] == 1){
				root = i;
				break;
			}
		}

		dfs(root, -1);
		vector<int> boss;
		for (int i = 1; i <= n; ++i){
			if (!mark[i]){
				boss.push_back(i);
			}
		}

		if (boss.size()==2){
			int p1 = boss[0];
			int p2 = boss[1];
			del_edge(p1, p2);
			ORIGIN[p1].erase(p2);
			ORIGIN[p2].erase(p1);
		}

		for (int R : boss){
			for (int son : ORIGIN[R]){
			//	cout << R << "　" << son << endl;
				update(son, R);
			}
		}

		for (int R : boss){
			
			for (int son : S[R]){
				len = 0;
				get(son, R);
	//			cout << endl;
				arr[len++] = R;
				for (int k = 3; k < len; ++k){
					add(arr[k], arr[k - 1], arr[1]);
				}
			}
		}

		printf("%d\n", NUM);
		for (int k = 0; k < NUM; ++k){
			printf("%d %d %d\n", a[k], b[k], c[k]);
		}



	}


	return 0;
}





