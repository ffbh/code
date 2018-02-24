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
const long long mod = 1e9 + 7;
long long N, data[100010];
long long sum[100010], dp[100010],sumdp[100010];
int h[20000000 + 5];
vector<int> vsum;
vector<int> V[100010];
void getInput(int n){
	ofstream out("C:\\input.txt");
	out << n << endl;
	srand(time(0));
	for (int i = 0; i < n; ++i){
		out << rand() % 200 - 100 <<" ";
	}
	out << endl;
}


int main(){
	ifstream in("C:\\input.txt");
//	getInput(1e5);
	//return 0;
	cin >> N;
	sum[0] = 0;
	vsum.push_back(0);
	for (int i = 1; i <= N; ++i){
		cin >> data[i];
		sum[i] = data[i] + sum[i - 1];
		vsum.push_back(sum[i]);
	}
	sort(vsum.begin(), vsum.end());
	vsum.erase(unique(vsum.begin(), vsum.end()), vsum.end());
	for (int i = 0; i < vsum.size(); ++i){
		h[vsum[i] + 10000000] = i;
	}
	for (int i = 0; i <= N; ++i){
		V[h[sum[i] + 10000000]].push_back(i);
	}
	dp[0] = 1;
	sumdp[0] = 1;
	for (int i = 1; i <= N; ++i){
		int hash = h[sum[i] + 10000000];
		if (hash > 1e5){
			cout << "big";
			cout << hash << " " << i << " "<<sum[i];
		}
		dp[i] = sumdp[i - 1];
		for (int j = 0; j < V[hash].size() && V[hash][j] < i; ++j){
			dp[i] = (dp[i] + mod - dp[V[hash][j]]) % mod;
		}
		sumdp[i] = (sumdp[i - 1] + dp[i]) % mod;
	}
	cout << dp[N] << endl;

	return 0;
}