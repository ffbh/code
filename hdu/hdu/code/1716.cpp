#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
int num[4];
int ans[30];
int cnt;
void Add(){
	int k = 0;
	for (int i = 0; i < 4; ++i)
		k = k * 10 + num[i];
	ans[cnt++] = k;
}

int main(){
	ifstream in("C:\\temp.txt");
	int ok = 0;
	while (cin >> num[0] >> num[1] >> num[2] >> num[3]){
		int sum = 0;
		for (int i = 0; i < 4; ++i)
			sum += num[i];
		if (sum == 0)
			break;
		if (ok)cout << endl;
		ok = 1;
		cnt = 0;
		sort(num, num + 4);
		Add();
		while (next_permutation(num, num + 4))
			Add();
		sort(ans, ans + cnt);
		cnt = unique(ans, ans + cnt) - ans;
		int m;
		int s = 0;
		while (s < cnt){
			while (ans[s] < 1000)s++;
			m = ans[s] / 1000;
			cout << ans[s];
			s++;
			while (s < cnt&&m == ans[s] / 1000)
				printf(" %d", ans[s++]);
			cout << endl;
		}
	}
	return 0;
}