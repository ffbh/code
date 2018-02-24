#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, M, K;
int A[100010];

bool slove(int m){
	int k = K, i, f = M;
	for (i = 1; i <= N && k; ++i){
		f -= A[i];
		if (f <= 0){
			k--;
			f = M;
		}
		f += m;
		if (f > M)
			f = M;
	}
	return k > 0;
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> N >> M >> K;
	int L, R;
	L = R = 0;
	for (int i = 1; i <= N; ++i){
		cin >> A[i];
		if (A[i] > R)
			R = A[i];
	}
	int ans = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (slove(mid)){
			ans = mid;
			R = mid - 1;
		}
		else
			L = mid + 1;
			
	}
	if (ans == 0)
		ans = 1;
	cout << ans << endl;
	return 0;
}