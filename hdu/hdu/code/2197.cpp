#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N;
int arr[20010], tail;
int quickmod(int m,int p,int mod){
	int ret = 1;
	while (p){
		if (p % 2)
			ret = (ret*m) % mod;
		m = (m*m) % mod;
		p /= 2;
	}
	return ret;
}

int submod(int a, int b, int mod){
	return ((a + mod) - b) % mod;
}

int main(){
	ifstream in("C:\\input.txt");
	while (cin >> N){
		if (N <= 0){
			cout << 0 << endl;
			continue;
		}
		if (N == 1){
			cout << 2 << endl;
			continue;
		}
		tail = 0;
		int ans = quickmod(2, N, 2008);
		int srt = sqrt(N);
		for (int i = 1; i <= srt; ++i){
			if (N%i == 0){
				arr[tail++] = i;
				if (i != 1)
					arr[tail++] = N / i;
			}
		}
		sort(arr, arr + tail);
		tail = unique(arr, arr + tail) - arr;
		for (int i = 0;i < tail; ++i){
			bool f = 1;
			for (int j = i+1; j < tail;++j)
			if (arr[j] % arr[i] == 0){
				f = 0;
				break;
			}
			
			if (f){
				int d = quickmod(2, arr[i], 2008);
				ans = submod(ans, d, 2008);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
