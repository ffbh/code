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
int N, root;
vector<int> vi[100010];
int data[100010];
int aim;
long long num[100010], vals[100010];
void Init(){
	for (int i = 0; i < 100010; ++i)
		vi[i].clear();
	memset(vals, 0, sizeof(vals));
	memset(num, 0, sizeof(num));
}

long long dfs(int p){
	if (vi[p].size() == 0){
		int t = 0;
	}
	long long ans = 0;
	vals[p] = data[p];
	long long sum = 0, del = 0;
	for (int i = 0; i < vi[p].size(); ++i){
		int v = vi[p][i];
		ans += dfs(v);
		vals[p] += vals[v];
		num[p] += num[v];
		sum += num[v];
		if (num[v] >= 2){
			del += num[v] * (num[v] - 1) / 2;
		}
	}
	if (vals[p] == aim)
		num[p]++;
	if (vals[p] == 2 * aim && p != root){
		ans += sum;
	}
	ans += sum * (sum - 1) / 2;
	ans -= del;
//	cout << p << " " << ans << endl;
	return ans;
}

void getInput(int n){
	ofstream out("C:\\input.txt");
	out << 1 << endl;
	out << n << endl;
	srand(time(0));
	for (int i = 0; i < n; ++i){
		out << 0 <<" "<< i << endl;
	}
}

int main(){
	ifstream in("C:\\input.txt");

	int T;
	cin >> T;
	while (T-- > 0){
		Init();
		cin >> N;
		int sum = 0;
		for (int i = 1; i <= N; ++i){
			int a, b;
			cin >> data[i] >> b;
			if (b == 0)
				root = i;
			else{
				vi[b].push_back(i);
			}
			sum += data[i];
		}

		if (sum % 3 == 0){
			aim = sum / 3;
			cout << dfs(root) << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	return 0;
}