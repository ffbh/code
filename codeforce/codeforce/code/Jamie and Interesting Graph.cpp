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
vector<int> vi[100010];

bool vis[120010];
void Init(){
	vis[0] = vis[1] = 1;
	for (int i = 2; i < 120010; ++i){
		if (!vis[i]){
			for (int j = i + i; j < 120012; j += i)
				vis[j] = 1;
		}
	}
}

void input(){
	in >> n >> m;


}
int ans;

int cale(int n){
	for (int i = n; i < 120010; ++i){
		if (vis[i] == 0){
			ans = i;
			return i - n + 1;
		}


	}

	assert(0);
}

void nx(int & a,int & b){
	if (b == n){
		a++;
		b = a + 2;
	}
	else{
		b++;
	}
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	Init();
	while (TEST_CASE-- > 0){
		input();


		int v = cale(n - 1);
		printf("%d %d\n", ans, ans);
		for (int i = 2; i < n; ++i){
			printf("%d %d %d\n", i - 1, i, 1);
		
		}
		printf("%d %d %d\n", n-1 , n, v);
	
		m -= (n - 1);
		int I = 1, J = 1 + 2;
		while (m-->0){
			printf("%d %d %d\n", I , J , int(1e8));
			nx(I, J);
		}











	}


	return 0;
}





