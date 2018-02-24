#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
long long num[40], N;


int main(){
	ifstream in("C:\\input.txt");
	cin >> N;
	for (int i = 0; i < N; ++i){
		unsigned int t;
		cin >> t;
		for (int i = 0; i < 32;++i)
		if (t &(1 << i))
			num[i]++;
	}
	long long ans = 0;
	for (int i = 0; i < 32; ++i)
		ans += num[i] * (N - num[i]);
	cout << ans << endl;















	return 0;
}