#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> mi, ans;
int num[200010], size;
int tmp[2000010];
int ansnum[200010];
int data[200010];
int T, N,K;
int sum;
void Init(){
	mi.clear();
	ans.clear();
	size = 0;
	sum = 0;
	memset(num, 0, sizeof(num));
	ans[sum] = size++;
	ansnum[0] = 0;
}

int  dfs(int l, int r){
	if (l == r){
		num[0]++;
		return 0;
	}
	else{
		int m = (l + r) / 2;
		int tl = dfs(l, m);
		int tr = dfs(m + 1, r);
		memset(tmp, 0, sizeof(tmp));
		for (int i = l; i <= m; ++i)
			tmp[data[i]]++;
		int lsum = tl;
		for (int i = m + 1; i <= r; ++i){
			lsum += tmp[data[i]];
			tmp[data[i]]++;
			num[ans[lsum]]++;
		}
		int rsum = tr;
		if (l == m && m + 1 == r){

			
		}
		else{
			memset(tmp, 0, sizeof(tmp));
			for (int i = m + 1; i <= r; ++i)
				tmp[data[i]]++;
			
			for (int i = m; i >= l+1; --i){
				rsum += tmp[data[i]];
				tmp[data[i]]++;
				num[ans[rsum]]++;
			}
		}

		return tl + tr + lsum + rsum;
	}
}

int main(){
	ifstream in("C:\\input.txt");

	in >> T;
	//scanf("%d", &T);
	while (T--){
		in >> N >> K;
		//scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; ++i)
				in >> data[i];
		//	scanf("%d", &data[i]);
		unordered_map<int, int> h;
		int hnum = 0;
		for (int i = 1; i <= N; ++i){
			if (!h.count(data[i])){
				h[data[i]] = hnum++;
			}
		}

		for (int i = 1; i <= N; ++i){
			data[i] = h[data[i]];
		}

		Init();
		for (int i = 1; i <= N; ++i){
			if (mi.count(data[i])){
				sum += mi[data[i]];
				ansnum[size] = sum;
				ans[sum] = size++;
			}
			mi[data[i]]++;
		}
		dfs(1, N);
		sum = 0;
		for (int i = 0; i < size; ++i){
			sum += num[i];
			if (sum >= K){
				cout << ansnum[i] << endl;
				break;
			}

		}
		

	}

	return 0;
}