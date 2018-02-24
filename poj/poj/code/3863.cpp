#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;

int main(){
	ifstream in("C:\\input.txt");
	int N, M;
	cin >> N >> M;
	int ans = INT_MAX;
	while (M--){
		int mmin = INT_MAX;
		int u, d;
		cin >> u >> d;
		int lower = int((double(d*N)) / (u + d));
		while (lower <= N){
			int tmp = lower*u - (N - lower)*d;
			if (tmp > 0){
				mmin = tmp;
				break;
			}
			lower++;
		}
		if (mmin < ans)
			ans = mmin;
	}
	cout << ans << endl;
	return 0;
}