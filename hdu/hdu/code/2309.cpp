#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	int mmax, mmin, sum;
	while (cin >> N&&N){
		mmax = INT_MIN;
		mmin = INT_MAX;
		sum = 0;
		for (int i = 0; i < N; ++i){
			int t;
			cin >> t;
			if (t>mmax)
				mmax = t;
			if (t < mmin)
				mmin = t;
			sum+=t;
		}
		sum -= mmax + mmin;
		cout << sum / (N - 2) << endl;
	}
	return 0;
}