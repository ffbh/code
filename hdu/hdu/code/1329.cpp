#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;
set<int> si;
int data[51];
int dp[51];
void Init(){
	int count = 0;
	data[1] = 1;
	dp[count++] = 1;
	for (int i = 2; i < 1350; ++i){
		int u;
		for (u = 0; u < count;++u)
		if (si.count(dp[u] + i)){
			dp[u] = i;
			break;
		}
		if (u == count){
			data[count] = i - 1;
			dp[count++] = i;
		}
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	for (int i = 1; i < 1350; ++i)
		si.insert(i*i);
	Init();
	int T;
	cin >> T;
	while (T--){
		int N;
		cin >> N;
		cout << data[N] << endl;
	}
	return 0;
}