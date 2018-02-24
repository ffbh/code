#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
#define MMAX (11111111)
int data[50], num[50], hire[50];

int cale(int n){
	memset(hire, 0, sizeof(hire));
	int s = n, e = n + 16;
	int ans = 0;
	for (int pos = s; pos <= e;++pos){
		if (hire[pos] + num[pos] < data[pos])
			return MMAX;
		int minhire = data[pos] - hire[pos];
		if (minhire > 0){
			for (int k = 0; k < 8; ++k){
				hire[k + pos] += minhire;
			}
			ans += minhire;
		}
		int sum = 0, MAX = 0;
		for (int j = pos + 1; j <= pos + 7; ++j){
			sum += num[j];
			if (sum < data[j] - hire[j]){
				MAX = max(MAX, data[j] - hire[j] - sum);
			}
		}
		if (MAX + minhire < num[pos]){
			return MMAX;
		}
		for (int k = 0; k < 8; ++k){
			hire[k + pos] += MAX;
		}
		ans += MAX;
	}
	return ans;
}

int main(){
	ifstream in("C:\\input.txt");
	int T,N;
	in >> T;
	while (T--){
		for (int i = 0; i < 24; ++i){
			in >> data[i];
			data[i + 24] = data[i];
			num[i] = num[i + 24] = 0;
		}
		in >> N;
		while (N--){
			int t;
			in >> t;
			num[t]++;
			num[t + 24]++;
		}
		int ans = MMAX;
		for (int i = 0; i < 24; ++i){
			int ret = cale(i);
			ans = min(ans, ret);
		}

		cout << ans << endl;
	}
















	return 0;
}