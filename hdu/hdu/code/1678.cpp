#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int num[20010];
bool cmp(int a, int b){
	return a > b;
}
int main(){
	//ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		int K;
		cin >> K;
		for (int i = 1; i <= K; ++i)
			//	in >> num[i];
			scanf("%d", &num[i]);
		sort(num + 1, num + 1 + K,cmp);
		int ans = 0;
		int p = 3;
		while (p <= K){
			ans += num[p];
			p += 3;
		}
		cout << ans << endl;
	}

	return 0;
}