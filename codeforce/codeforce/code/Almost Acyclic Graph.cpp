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

int n, m;
vector<pii> vi[510];




void input(){
	in >> n >> m;
	//scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i){
		int a, b;
		in >> a >> b;
	//	scanf("%d%d", &a, &b);
		vi[a].push_back(mp(b,i));
	}


}




vector<int> edge;
bool g_mark[510], en_mark[510];
bool getcycle(int p){
	if (en_mark[p]){
		return 0;
	}
	if (g_mark[p]){
		return 1;
	}
	g_mark[p] = 1;
	for (pii k : vi[p]){
		edge.push_back(k.second);
		if (getcycle(k.first)){
			return 1;
		}
		edge.pop_back();
	}
	en_mark[p] = 1;
	return 0;
}

int j_mark[510];
bool stack[510];

bool is_cycle(int p,int id,int color){
	if (stack[p])
		return 1;
	
	if (j_mark[p] != 0){
		return 0;
	}
	stack[p] = 1;
	j_mark[p] = color;
	for (pii s : vi[p]){
		if (s.second == id)
			continue;
		if (is_cycle(s.first,id,color)){
			stack[p] = 0;
			return 1;
		}
	}
	stack[p] = 0;
	return 0;
}
bool judge(int id){
	if (id == 6){
		int t = 0;
	}
	memset(j_mark, 0, sizeof(j_mark));
	for (int i = 1; i <= n; ++i){
		if (j_mark[i] != 0)
			continue;
		if (is_cycle(i,id,i))
			return 0;
	}
	return 1;

}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		for (int i = 1; i <= n; ++i)
			vi[0].push_back(mp(i, -1));

		
	
		getcycle(0);
		if (edge.size() == 0){
			cout << "YES" << endl;
			return 0;
		}
		for (int ID : edge){
			if (ID == -1){
				continue;
			}
			if (judge(ID)){
				cout << "YES" << endl;
				return 0;
			}
		}
		cout << "NO" << endl;

	}


	return 0;
}





