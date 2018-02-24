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
#define MMAX (60)
bool vis[MMAX];
vector<long long> P[60];
vector<int> prime;
#define INF (1e18+10)

int calelen(long long k){
	int ret = 0;
	while (k){
		ret++;
		k /= 10;
	}
	return ret;
}
void Init(){
	for (int i = 2; i < MMAX;++i)
	if (!vis[i]){
		prime.push_back(i);
		for (int j = i + i; j < MMAX; j += i)
			vis[j] = 1;
	}
	for (int i = 0; i < prime.size(); ++i){
		int p = prime[i];
		P[i].push_back(1);
		for (int j = 1; P[i][j - 1]*p < INF; ++j){
			P[i].push_back(P[i].back() * p);
		}
	}
}
unsigned long long ans,N;
vector<int> tmp, pace;
int num, T;
int maxlen = 0;
void dfs(int pos,int t_num,unsigned long long t_ans,int pre){
	if (log10(t_ans) > maxlen){
		maxlen = log10(t_ans);
	}
	if (pos == prime.size())
		return;
	if (t_num > num || t_num == num && t_ans < ans){
		ans = t_ans;
		num = t_num;
		pace = tmp;
	}
	for (int i = 1; i<P[i].size()&&i<=pre&&(log10(P[pos][i])+log10(t_ans))<=19 &&t_ans * P[pos][i] <= N ; ++i){
		tmp.push_back(i);
		dfs(pos + 1, t_num*(i + 1), t_ans*P[pos][i],i);
		tmp.pop_back();
	}
}

int main(){
	ifstream in("C:\\input.txt");
	ofstream out("C:\\input2.txt");
	Init();
	cin >> T;	
	while (T-- > 0){
		cin >> N;
		num = -1;
		dfs(0, 1, 1,64);
		cout << ans << " " << num << endl;
	}
/*	cout << "maxlen: " << maxlen << endl;
	unsigned long long k = 1;
	for (int i = 0; i < pace.size(); ++i){
		k *= P[i][pace[i]];
		cout << k << endl;
	}*/
	return 0;
}