#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
using namespace std;
#define INF (1<<28)
int  N, M, S, T;
int num[20];
int temp[20];
int A[1010];

bool slove(int m){
	int ac = m;
	int wa = M - m;
	memcpy(temp, num, sizeof(num));
	for (int i = 10; i >= 1; --i){
		if (ac){
			if (temp[i] <= ac){
				ac -= temp[i];
				temp[i] = 0;
			}
			else{
				temp[i] -= ac;
				ac = 0;
			}
		}
		if (temp[i]){
			int tnum = i / T + (i%T ? 1 : 0);
			if (temp[i] * tnum <= wa){
				wa -= temp[i] * tnum;
				temp[i] = 0;
			}
		}
		if (temp[i]){
			return 0;
		}
	}
	return 1;

}

int main(){
	ifstream in("C:\\input.txt");
	int Case;
	in >> Case;
	while (Case-- > 0){
		in >> N >> M >> S >> T;
		for (int i = 1; i <= N; ++i)
			in >> A[i];
		memset(num, 0, sizeof(num));

		for (int i = 1; i <= N; ++i){
			num[A[i] % S]++;
			num[S] += A[i] / S;

		}


		int L = 0, R = M;
		int ans = M + 1;
		while (L <= R){
			int mid = (L + R) / 2;
			if (slove(mid)){
				ans = min(ans, mid);
				R = mid - 1;
			}
			else{
				L = mid + 1;
			}
		}
		if (ans > M)
			cout << "No" << endl;
		else
			cout << ans << endl;

	}

	return 0;
}