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
using namespace std;
int Q;
long long N;
__int64 ans;
bool cale(long long m){
	long long  bridge = m;
	long long rest = N - bridge;
	long long num = rest * (rest - 1) / 2;
	ans = max(ans, min(bridge * 2, num + bridge));
	return num >= bridge;
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	//in >> Q;
	scanf("%d", &Q);
	while (Q-- > 0){
		//in >> N;
		scanf("%I64d", &N);
		ans = 0;
		long long L = 1;
		long long R = N-1;
		while (L <= R){
			long long mid = (L + R) / 2;
			if (cale(mid)){
				L = mid + 1;
			}
			else{
				R = mid - 1;
			}
		}
		//cout << ans << endl;
		printf("%I64d\n", ans);

	}

















	return 0;
}





