#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int N, K;
int data[1010][1010];
int ans, mmax;

int main(){
	ifstream in("C:\\input.txt");
	in >> N >> K;
	for (int i = 1; i <= N;++i)
	for (int j = K; j >= 0; --j){
		int t;
		in >> t;
		data[i][t] = j;
	}
	mmax = -1;
	for (int i = 0; i <= K; ++i){
		int sum = 0;
		for (int j = 1; j <= N; ++j)
			sum += data[j][i];
		cout << sum << endl;
		if (sum > mmax){
			mmax = sum;
			ans = i;
		}
		else if (sum == mmax){
			if (ans == 0)
				ans = i;
		}
	}
	if (ans)
		cout << ans << endl;
	else
		cout << "otaku" << endl;
	return 0;
}