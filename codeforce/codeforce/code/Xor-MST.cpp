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
#define pbb pair<bool,bool>
#define mp make_pair
#define pb push_back

int n;
struct Node{
	int next[2];
	
}data[7000000];
int root, size;


int MALLOC(){
	data[size].next[0] = data[size].next[1] = -1;
	return size++;
}

void Insert(int val){
	int p = root;
	for (int i = 30; i >= 0; --i){
		int now = ((1 << i)&val) == 0 ? 0 : 1;
		if (data[p].next[now] == -1){
			data[p].next[now] = MALLOC();
		}
		p = data[p].next[now];
	}
}



void input(){
	in >> n;
	for (int i = 1; i <= n; ++i){
		int t;
		in >> t;
		Insert(t);
	}
}


LL ans;

void add(int k){
	ans += (1 << k);
}

LL dfs(int a, int b,int limit){
	if (limit == -1){
		return 0;
	}


	if (limit == 0){
		int t = 0;
	}
	
	int a1 = data[a].next[0];
	int a2 = data[a].next[1];
	int b1 = data[b].next[0];
	int b2 = data[b].next[1];

	bool ok = 0;
	LL ret = 1e18;
	if (a1 != -1 && b1 != -1){
		ok = 1;
		LL tmp = dfs(a1, b1, limit - 1);
		ret = min(ret, tmp);
	}

	if (a2 != -1 && b2 != -1){
		ok = 1;
		LL tmp = dfs(a2, b2, limit - 1);
		ret = min(ret, tmp);
	}
	if (ok){
		return ret;
	}
	else{
		int na, nb;
		if (a1 != -1){
			na = a1;
		}
		else{
			na = a2;
		}

		if (b1 != -1){
			nb = b1;
		}
		else{
			nb = b2;
		}

		ret = dfs(na, nb, limit - 1) + (1 << limit);
	}
	return ret;


}

void slove(int p, int limit){

	

	if (data[p].next[0] != -1){
		slove(data[p].next[0], limit - 1);
	}

	if (data[p].next[1] != -1){
		slove(data[p].next[1], limit - 1);
	}

	if (data[p].next[0] != -1 && data[p].next[1] != -1){
		if (p == 28){
			int t = 0;
		}
		add(limit);
		ans += dfs(data[p].next[0], data[p].next[1], limit - 1);
	}
}




int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		size = 0;
		root = MALLOC();


		input();
		
	

		ans = 0;

		slove(root,30);

		cout << ans << endl;
	}


	return 0;
}





