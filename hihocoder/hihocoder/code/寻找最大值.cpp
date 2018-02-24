#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
long long data[100010];



int main(){
	ifstream in("C:\\input.txt");
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> data[i];
		sort(data, data + N);
		long long ans = 0;
		for (int i = 0; i < N - 1; ++i)
			ans = max(ans, data[i] * data[i + 1] * (data[i] & data[i + 1]));
		cout << ans << endl;
	}
















	return 0;
}