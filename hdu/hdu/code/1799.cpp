#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int C(int n, int m){
	int ans = 1;
	while (m){
		ans *= n;
		ans /= m;
		n--;
		m--;
		ans %= 1007;
	}
	return ans;
}

int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int N, M;
		cin >> M >> N;
		cout << C(N, M) << endl;

	}





	return 0;
}