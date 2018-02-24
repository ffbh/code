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
#define MMAX (((int)2e5)+10)
typedef long long LL;

int gcd(int a,int b){
	if (a < b)
		swap(a, b);
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int n;
int val[MMAX];
vector<int> vi[MMAX];
void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> val[i];
	for (int i = 1; i < n; ++i){
		int x, y;
		in >> x >> y;
		vi[x].pb(y);
		vi[y].pb(x);
	}

}

int ans[MMAX];
vector<int> all;

int MAX(int a,int b){
	return max(a, b);
}

void p_dfs(int pos,int f){
	if (f == -1){
		ans[pos] = 0;
	
	}
	else{
		ans[pos] = gcd(ans[f], val[pos]);
		
	}
	for (int son : vi[pos]){
		if (son != f){
			p_dfs(son,pos);
		}
	}
}


void dfs(int pos,int f,bool del,int num){
	if (val[pos] % num != 0 && del){
		return;
	}

	ans[pos] = max(ans[pos], num);
	bool next = (val[pos] % num != 0) || del;
	for (int son : vi[pos]){
		if (son != f){
			dfs(son, pos, next, num);
		}
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		p_dfs(1, -1);

		ans[1] = val[1];

		for (int i = 1; i <= val[1]; ++i){
			if (val[1] % i == 0)
				all.push_back(i);
		}
		for (int p : all){
			dfs(1, -1, 0, p);

		}

		for (int i = 1; i <= n; ++i)
			printf("%d ", ans[i]);
		cout << endl;












	}


	return 0;
}





