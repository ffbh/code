#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
long long A[60010];
deque<long long> qi;


int main(){
	ifstream in("C:\\input.txt");
	int T, N;
//	cin >> T;
	scanf("%d", &T);
	while (T--){
		qi.clear();
	//	cin >> N;
		scanf("%d", &N);
		for (int i = 0; i < N; ++i)
			//		cin >> A[i];
			scanf("%lld", &A[i]);
		for (int i = 0; i < N; ++i){
			long long  t;
	//		cin >> t;
			scanf("%lld", &t);
			qi.push_back(t);
		}
		long long ans = 1e18;
		for (int k = 0; k < N; ++k){
			long long sum = 0;
			for (int i = 0; i < N; ++i){
				sum += (qi[i] - A[i])*(qi[i] - A[i]);
				if (sum > ans)
					break;
			}
			if (sum < ans)
				ans = sum;
			qi.push_back(qi.front());
			qi.pop_front();
		}
		printf("%lld\n", ans);
	}

	return 0;
}