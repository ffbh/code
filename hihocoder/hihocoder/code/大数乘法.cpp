#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
using namespace std;
int A[110];
int B[110];
char data[110];
int ans[210];
int t[210][210];
int ll[210];
int main(){
	ifstream in("C:\\input.txt");
	cin >> data;
	int al, bl;
	al = bl = 0;
	al = strlen(data);
	al--;
	for (int i = 0; i <= al; ++i)
		A[i] = data[al - i] - '0';
	cin >> data;
	bl = strlen(data);
	bl--;
	for (int i = 0; i <= bl; ++i)
		B[i] = data[bl - i] - '0';

	int f = 0;
	for (int i = 0; i <= bl; ++i){
		ll[i] = al + 1;
		for (int j = 0; j <= ll[i]; ++j){
			t[i][j] = (B[i] * A[j] + f) % 10;
			f = (B[i] * A[j] + f) / 10;
		}
		while (ll[i] && t[i][ll[i]] == 0) ll[i]--;
		for (int j = 0; j <= ll[i]; ++j)
			ans[i + j] += t[i][j];

	}
	int ansl = (al + 1) + (bl + 1);
	f = 0;
	for (int i = 0; i <= ansl; ++i){
		int tmp = (ans[i] + f) / 10;
		ans[i] = (ans[i] + f) % 10;
		f = tmp;
	}
	while (ansl && ans[ansl] == 0) ansl--;
	for (int i = ansl; i >= 0; --i)
		cout << ans[i];
	cout << endl;













	return 0;
}