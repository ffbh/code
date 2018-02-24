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



typedef long long LL;
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define pb push_back
#define lson (root<<1)  
#define rson (root<<1|1)  



int main(){

	int n;
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; ++i){
		int rest = n - i;
		if (rest != 0 && rest % i == 0)
			ans++;

	}
	cout << ans << endl;















	return 0;
}





