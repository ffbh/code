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
typedef long long LL;

LL n, k, m;
LL a[110];


void input(){
	in >> n >> k >> m;
	for (int i = 1; i <= k; ++i)
		in >> a[i];

}

int slove(LL num){
	LL sum = 0;
	for (int i = 1; i <= k; ++i){
		sum += a[i];
	}
	if (sum*num > m)
		return 0;
	LL ret = num*(k + 1);
	LL M = m - sum*num;
	for (int i = 1; i <= k; ++i){
		if (a[i] * (n - num) <= M){
			ret += (n - num);
			M -= a[i] * (n - num);
		}
		else{
			ret += (M / a[i]);
			break;
		}

	}

	return ret;
}

int main(){

	int TEST_CASE = 1;
	//in >> TEST_CASE;
	while (TEST_CASE-- > 0){
		input();
		
		sort(a + 1, a + k + 1);
		LL ans = 0;
		for (int i = 0; i <= n; ++i){
			LL t = slove(i);
			ans = max(ans, t);

		}

		cout << ans << endl;











	}


	return 0;
}





