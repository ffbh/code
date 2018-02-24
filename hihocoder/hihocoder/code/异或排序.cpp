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
using namespace std;
struct Node{
	int val, num;
	Node(int a, int b){
		val = a;
		num = b;
	}
};
long long data[60];
int bit[70][70];
int N;
long long ans;
int dp[70][2];

void dfs(int l, int r, int pos){
	if (pos < 0)
		return;
	if (pos == 1){
		int t = 0;
	}

	vector<Node> vn;
	int p = l;
	while (p <= r){
		int now = bit[p][pos];
		int num = 0;
		while (p <= r&&bit[p][pos] == now){
			num++;
			p++;
		}
		vn.push_back(Node(now, num));
	}
	if (vn.size() == 1){
		dfs(l, r, pos - 1);
	}
	else if (vn.size() == 2){
		dp[pos][vn[0].val] = 1;
		dfs(l, l + vn[0].num - 1, pos - 1);
		dfs(l + vn[0].num, r, pos - 1);
	}
	else{
		ans = 0;
	}
}


int main(){
	//ifstream in("C:\\input.txt");
	istream& in = cin;
	memset(dp, 0, sizeof(dp));
	in >> N;
	for (int i = 0; i < N; ++i)
		in >> data[i];
	

	for (int i = 0; i < N; ++i){
		for (int j = 59; j >=0; --j){
			if (((long long)1 << j)&data[i]){
				bit[i][j] = 1;
			}
			else{
				bit[i][j] = 0;
			}
		}
	}

	ans = 1;
	dfs(0, N - 1, 59);
	if (ans == 0)
		cout << 0 << endl;
	else{
		for (int i = 59; i >= 0; --i){
			if (!dp[i][0] && !dp[i][1]){
				ans *= 2;
			}
			else if (dp[i][0] && dp[i][1]){
				ans = 0;
				break;
			}
		}
		cout << ans << endl;
	}


	return 0;
}





