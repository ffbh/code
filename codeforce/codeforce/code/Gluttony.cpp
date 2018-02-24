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

ifstream in("C:\\input.txt");
//istream& in = cin;


typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back


int n;
LL a[30], b[30];
LL sum[30];



void input(){
	in >> n;
	for (int i = 0; i < n; ++i)
		in >> a[i];


}


bool vis[23][4200000];
int p[30];
bool dfs(int pos,int mask,LL all){
	if (vis[pos][mask])
		return 0;
	vis[pos][mask] = 1;
	if (pos == n - 1){
		for (int i = 0; i < n; ++i){
			if ((mask & p[i]) == 0){
				b[pos] = a[i];
				break;
			}
		}
		return 1;
	}
	else{
		for (int i = 0; i < n; ++i){
			if ((mask & p[i]) == 0 && all + a[i] != sum[pos]){
				b[pos] = a[i];
				if (dfs(pos + 1, mask + p[i], all + a[i]))
					return 1;
			}

		}


	}


	return 0;
}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		sum[0] = a[0];
		for (int i = 1; i < n; ++i)
			sum[i] = a[i] + sum[i - 1];

		for (int i = 0; i < 30; ++i)
			p[i] = 1 << i;

		if (dfs(0, 0, 0)){
			for (int i = 0; i < n; ++i)
				cout << b[i] << " ";
			cout << endl;
		}
		else{
			cout << -1 << endl;
		}


	}


	return 0;
}





