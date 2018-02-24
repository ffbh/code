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
int N, P, W, H;
int A[1010];

bool ok(int fs){
	int sum = 0;
	int w = W / fs;	
	int h = H / fs;
	if (w == 0 || h==0)
		return 0;
	for (int i = 1; i <= N; ++i){
		if (A[i] % w == 0){
			sum += A[i] / w;
		}
		else{
			sum += A[i] / w + 1;
		}
	}


	int ansp = sum / h;
	if (sum%h != 0)
		ansp++;
	return ansp <= P;


}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	int T;
	in >> T;
	while (T-- > 0){
		in >> N >> P >> W >> H;
		for (int i = 1; i <= N; ++i)
			in >> A[i];
		int L = 1, R = 1010;
		int ans = 0;
		while (L <= R){
			int mid = (L + R) / 2;
			if (mid == 2){
				int t = 0;
			}
			if (ok(mid)){
				ans = max(mid, ans);
				L = mid + 1;
			}
			else{
				R = mid - 1;
			}
		}
		cout << ans << endl;
	}



	return 0;
}