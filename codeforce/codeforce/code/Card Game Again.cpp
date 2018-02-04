#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <set>
using namespace std;
#define MMAX ((int)1e5+10)


vector<int> prime;
bool vis[MMAX];
int N, K, a[100010];
unordered_map<int, int> temp;
unordered_map<int, int> px;
void cale_prime(){
	for (int i = 2; i < MMAX; ++i){
		if (!vis[i]){
			prime.push_back(i);
			for (int j = i; j < MMAX; j += i)
				vis[j] = 1;
		}
	}
}



bool judge(){
	for (pair<int, int> p : temp){
		if (px[p.first] < p.second)
			return 0;

	}
	return 1;
}



void update(int x, int val){
	for (pair<int, int> p : temp){
		while (x % p.first == 0){
			px[p.first] += val;
			x /= p.first;
		}
	}
}

int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;

	cale_prime();
	temp.clear();
	px.clear();


	in >> N >> K;
	for (int i = 1; i <= N; ++i)
		in >> a[i];
	


	for (int i = 0; i < prime.size() && K != 1; ++i){
		while (K % prime[i] == 0){
			temp[prime[i]]++;
			K /= prime[i];
		}
	}
	if (K != 1){
		temp[K]++;
	}

	

	long long ans = 0;
	int R = 1;
	for (int L = 1; L <= N; ++L){
		while (R <= L || (R <= N && !judge())){
			update(a[R], 1);
			R++;
		}
		if (judge()){
			ans += N - R + 2;
		}
		update(a[L], -1);
	}


	cout << ans << endl;



	return 0;
}