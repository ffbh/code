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

void _init(){



}

int n, m, h;
int a[110], b[110];
int c[110][110];
int ans[110][110];
void input(){
	in >> n >> m >> h;
	for (int i = 1; i <= m; ++i)
		in >> a[i];
	for (int i = 1; i <= n; ++i)
		in >> b[i];
	for (int i = 1; i <= n;++i)
	for (int j = 1; j <= m; ++j)
		in >> c[i][j];


}


int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		_init();
		input();

		for (int i = 1; i <= n;++i)
		for (int j = 1; j <= m; ++j){
			if (c[i][j] == 0){
				ans[i][j] = 0;
			}
			else{
				ans[i][j] = min(b[i], a[j]);
			}

		}

		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= m; ++j){
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}











	}


	return 0;
}





