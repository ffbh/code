#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int f[20];//15

int dp[2001];
void Init(){
	bool vis[2000];
	for (int i = 1; i <= 1000;++i){
		memset(vis, 0, sizeof(vis));
		for (int k = 1; i - f[k] >= 0; ++k)
			vis[dp[i-f[k]]] = 1;
		for (int j = 0;;++j)
		if (!vis[j]){
			dp[i] = j;
			break;
		}
	}
}

int main(){
	ifstream in("C:\\temp.txt");
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i < 20; ++i)
		f[i] = f[i - 1] + f[i - 2];
	Init();

	int m, n, p;
	while (cin >> m >> n >> p&&m + n + p){
		int sum = 0;
		sum ^= dp[m];
		sum ^= dp[n];
		sum ^= dp[p];
		if (sum)
			cout << "Fibo" << endl;
		else
			cout << "Nacci" << endl;
	}
	return 0;
}