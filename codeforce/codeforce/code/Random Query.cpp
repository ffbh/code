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

#define MMAX (((int)1e6)+10)

double dp[MMAX];
int mark[MMAX];
int n, a[MMAX];


void input(){
	in >> n;
	for (int i = 1; i <= n; ++i)
		in >> a[i];


}

double cale(){

	memset(mark, -1, sizeof(mark));
	int num = 0;
	double pre = 0;
	for (int i = 1; i <= n; ++i){
		double now;
		if (mark[a[i]] == -1){
			num++;
			now = pre + i;
			dp[i] = dp[i - 1] + now;
		}
		else{
			now = pre + i - mark[a[i]];
			dp[i] = dp[i - 1] + now;
		}
		
		mark[a[i]] = i;
		pre = now;
	}
	return dp[n];

}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();

		double ans = cale();
  		reverse(a + 1, a + n + 1);
		ans += cale();
		ans -= n;
		double t = n;
		printf("%.6f\n", ans / (t * t));












	}


	return 0;
}





