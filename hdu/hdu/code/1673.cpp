#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int mmin = INT_MAX;
		int mmax = INT_MIN;
		int K;
		cin >> K;
		while (K--){
			int n;
			scanf("%d", &n);
			if (n < mmin)mmin = n;
			if (n > mmax)mmax = n;
		}
		cout << (mmax - mmin) * 2 << endl;
	}

	return 0;
}