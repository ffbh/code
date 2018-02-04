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





int main(){
	ifstream in("C:\\input.txt");
	int N;
	while (cin >> N){
		int ans = N - 1;
		for (int i = 2; i <= sqrt(N)+1000; ++i){
			if (N%i == 0 ){
				int a = N / i - 1;
				int b = i - 1;
				if (a >= 2 && ans > a)
					ans = a;
				if (b >= 2 && ans > b)
					ans = b;
			}
		}
		cout << ans << endl;
	}

	return 0;
}