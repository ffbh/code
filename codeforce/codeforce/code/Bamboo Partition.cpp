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

long long a[110];
long long N, K;

long long ok(long long m){
	long long need = 0;
	for (int i = 1; i <= N; ++i){
		if (a[i]%m !=0)
			need += m - a[i] % m;
	}
	return need ;
}
long long P[110], ans;
void cale(long long L, long long R){

	while (L <= R){
		long long mid = (L + R) / 2;
		if (ok(mid) <= K){
			ans = max(ans, mid);
			L = mid + 1;
		}
		else{
			R = mid - 1;
		}
	}
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	in >> N >> K;
	for (int i = 1; i <= N; ++i)
		in >> a[i];
	sort(a + 1, a + N + 1);


	
	for (int i = 1; i <= N; ++i)
		P[i] = ok(a[i]);
	ans = 1;
	cale(1, a[1]-1);
	cale(a[N], (long long)1e15);
	for (int i = 1; i < N; ++i){
		cale(a[i], a[i + 1]-1);
	}
	


	cout << ans << endl;
	return 0;
}





