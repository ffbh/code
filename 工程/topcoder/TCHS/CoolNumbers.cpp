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
using namespace std;
#define DEBUG (0)

int getHit(int p){
	for (int i = 30; i >= 0;--i)
	if ((1 << i)&p)
		return i;
	return -1;
}
int dp[40][40][40][2][2][2], val;
int dfs(int pos,int a,int b,int f,int pre,int ok){
	if (pos < 0){
		return a >= 3 || b >= 3||ok;
	}
	int& ref = dp[pos][a][b][f][pre][ok];
	if (ref != -1){
		return ref;
	}
	ref = 0;
	int h = 0;
	if (val & (1 << pos) || f){
		h = 1;
	}

	if (pos == 0 && val==14&&b==3){
//		int t = 0;
	}

	if (pre){
		int nf = f;
		if (!nf && h == 1)
			nf = 1; 
		ref += dfs(pos - 1, a + 1, 0, nf, pre, (a >= 3 || b >= 3||ok));
		if (h == 1)
			ref += dfs(pos - 1, 0, b + 1, f, 1, (a >= 3 || b >= 3||ok));
	}
	else{
		int nf = f;
		if (!nf && h == 1)
			nf = 1;
		ref += dfs(pos - 1, 0, 0, nf, pre, (a >= 3 || b >= 3||ok));
		if (h == 1)
			ref += dfs(pos - 1, 0, b + 1, f, 1, (a >= 3 || b >= 3||ok));
	}
	return ref;
}

int cale(int p){
	if (p <= 0)
		return 0;
	val = p;
	memset(dp, -1, sizeof(dp));
	int hb = getHit(p);
	return dfs(hb, 0, 0, 0, 0,0);
}

class CoolNumbers {
	public:
	int count(int lowerBound, int upperBound) {
	
		int a = cale(lowerBound - 1);
		int b = cale(upperBound);
		return b - a;



	}
};



#if 0
int main(){


	CoolNumbers so;
	cout << so.count(2000000000, 2100000000) << endl;
















	return 0;
}
#endif

