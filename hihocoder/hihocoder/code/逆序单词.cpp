#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
string s1[50010], s2[50010];


int main(){
	ifstream in("C:\\input.txt");
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i){
		cin >> s1[i];
		s2[i] = string(s1[i].rbegin(), s1[i].rend());
	}
	sort(s2, s2 + N);
	int ans = 0;
	for (int i = 0; i < N; ++i){
		int p = lower_bound(s2, s2 + N, s1[i]) - s2;
		if (s2[p] == s1[i])
			ans++;
	}
	cout << ans/2 << endl;














	return 0;
}