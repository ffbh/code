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
#define lson (root<<1)  
#define rson (root<<1|1)  

LL N;
int mod = 9937;

void add(int& a,int b){
	a %= mod;
	b %= mod;
	a += b;
	a %= mod;
	if (a < 0)
		a += mod;
}

void mul(int a[35][35], int b[35][35], int ret[35][35]){
	int t[35][35];

	for (int i = 0; i < 35;++i)
	for (int j = 0; j < 35; ++j){
		t[i][j] = 0;
		for (int k = 0; k < 35; ++k){
			add(t[i][j], a[i][k] * b[k][j]);
		}
	}
	for (int i = 0; i < 35; ++i)
	for (int j = 0; j < 35; ++j)
		ret[i][j] = t[i][j];

}

void quick_mod(int mat[35][35], LL p){
	int ret[35][35];
	for (int i = 0; i < 35;++i)
	for (int j = 0; j < 35; ++j){
		if (i == j)
			ret[i][j] = 1;
		else{
			ret[i][j] = 0;
		}
	}
	while (p){
		if (p & 1){
			mul(ret, mat, ret);
		}
		mul(mat, mat, mat);
		p /= 2;
	}
	for (int i = 0; i < 35;++i)
	for (int j = 0; j < 35; ++j)
		mat[i][j] = ret[i][j];
}



int mmp[35][35];
int g[4];
int temp[4];
int h[600], ph[50];

void dfs(int pos,int state){
	if (pos == 4){
		int next_state = 0;
		for (int i = 3; i >= 0 ; --i)
			next_state = next_state * 5 + temp[i];
		mmp[h[state]][h[next_state]] ++;
		return;
	}
	else{
		int idx[3];
		idx[0] = pos;
		idx[1] = (pos + 3) % 4;
		idx[2] = (pos + 1) % 4;
		for (int i = 0; i <= g[pos];++i)
		for (int j = 0; j <= g[pos] - i; ++j){
			int k = g[pos] - i - j;
			temp[idx[0]] += i;
			temp[idx[1]] += j;
			temp[idx[2]] += k;
			dfs(pos + 1, state);
			temp[idx[0]] -= i;
			temp[idx[1]] -= j;
			temp[idx[2]] -= k;
		}

	}


}

void build_graph(int state){
	int K = state;

	for (int i = 0; i < 4; ++i){
		g[i] = state % 5;
		state /= 5;
	}

	

	dfs(0, K);
}



void Init(){
	vector<int> state;
	for (int i = 0; i < 600; ++i){
		int num = 0;
		int p = i;
		for(int k=0;k<4;++k){
			num += p % 5;
			p /= 5;
		}
		if (num == 4 && p==0){
			state.push_back(i);
		}
	}
	for (int i = 0; i < state.size(); ++i){
		h[state[i]] = i;
		ph[i] = state[i];
	}
	for (int s : state){
		build_graph(s);
	}
}

int main(){
	
	Init();

	while (~scanf("%lld",&N)){
		int mat[35][35];
		for (int i = 0; i < 35;++i)
		for (int j = 0; j < 35; ++j)
			mat[i][j] = mmp[i][j];
		quick_mod(mat, N);
		
		
		
		printf("%d\n", mat[20][20]);
		//cout << mat[20][20] << endl;



	}




	return 0;
}






