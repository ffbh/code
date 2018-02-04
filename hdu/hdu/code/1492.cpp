#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
	ifstream in("C:\\input.txt");
	unsigned long long n;
	int num[4];
	int p[4] = { 2, 3, 5, 7 };
	while (cin >> n&&n){
		memset(num, 0, sizeof(num));
		for (int i = 0; i < 4; ++i){
			while (n%p[i] == 0){
				n /= p[i];
				num[i]++;
			}
		}

		int ans = 1;
		for (int i = 0; i < 4; ++i)
			ans *= num[i] + 1;
		cout << ans << endl;

	}
















	return 0;
}