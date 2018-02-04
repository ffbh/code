#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int MOD(int n){
	int ans = 0;
	while (n){
		ans += n % 10;
		n /= 10;
	}
	return ans % 9;
}


int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N&&N){
		int ans = 1;
		int  K = N;
		while (K > 0){
			if (K % 2)
				ans = MOD(ans*MOD(N));
			N = MOD(N*N);
			K /= 2;
		}
		if (ans == 0)
			cout << 9 << endl;
		else
			cout << ans <<  endl;

	}

	return 0;
}