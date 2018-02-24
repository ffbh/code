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

char ans[100];

int n, L, now;
char E;

bool match(int a,int b,int len){
	while (len-- > 0){
		if (ans[a] != ans[b])
			return 0;
		a++;
		b++;
	}
	return 1;
}

bool judge(int k){
	int len = (k + 1) / 2;
	int start = k - len + 1;
	for (int i = start; i <= k; ++i){
		if (match(2*i-k-1, i, k-i+1))
			return 0;
	}
	return 1;
}

bool dfs(int dept){
	if (now == n){
		for (int i = 0; i < dept; ++i){
			if (i == 64)
				cout << endl;
			else if (i&&i % 4 == 0){
				cout << " ";
			}
			cout << ans[i];
		}
		cout << endl;
		cout << dept << endl;
		return 1;
	}
	if (dept == 3){
		int t = 0;
	}

	for (char p = 'A'; p <= E; ++p){
		ans[dept] = p;
		if (judge(dept)){
			now++;
			if (dfs(dept + 1))
				return 1;
		}
	}
	return 0;
}

int main(){
	ifstream in("C:\\input.txt");
	//istream& in = cin;
	while (cin >> n >> L&&n + L){
		E = 'A' + L - 1;
		now = 0;
		dfs(0);
	}
















	return 0;
}