#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int num[20];


int main(){
	ifstream in("C:\\temp.txt");
	num[1] = 1;
	for (int i = 2; i < 16; ++i)
		num[i] = num[i - 1] * i;
	int T;
	cin >> T;
	int N;
	while (T--){
		int k = 15;
		cin >> N;
		int ans;
		int r;
		int mmin = INT_MAX;
		while (k >= 0 && num[k]>N) k--;
			ans = 0;
			r = N;
			int j = k;
			while (r>0){
				while (r >= num[j]){
					r -= num[j];
					ans++;
				}
				j--;
			}
			if (ans < mmin)
				mmin = ans;
		cout << mmin << endl;
	}
	return 0;
}