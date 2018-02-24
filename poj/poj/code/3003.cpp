#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
#define MMAX (1000000)
vector<char> ans, tmp;
int data[50];
int vis[50][1010];
int T, N, mmax;
void DFS(int index, int d,int maxlen){
	if (vis[index][d] <= maxlen)
		return;
	vis[index][d] = maxlen;
	if (index == N){
		if (d == 0 && mmax > maxlen){
			ans = tmp;
			mmax = maxlen;
		}
		return;
	}
	if (d - data[index] >= 0){
		tmp.push_back('D');
		DFS(index + 1, d - data[index],maxlen);
		tmp.pop_back();
	}
	tmp.push_back('U');
	DFS(index + 1, d + data[index],max(maxlen,d+data[index]));
	tmp.pop_back();
}

int main(){
	ifstream in("C:\\input.txt");
	cin >> T;
	while (T--){
		cin >> N;
		mmax = MMAX;
		int sum = 0;
		for (int i = 0; i < N; ++i){
			cin >> data[i];
			sum += data[i];
		}
		if (sum % 2)
			cout << "IMPOSSIBLE" << endl;
		else{
			for (int i = 0; i <= N;++i)
			for (int j = 0; j <= sum; ++j)
				vis[i][j] = MMAX;
			DFS(0, 0, 0);
			if (mmax != MMAX){
				for (int i = 0; i < N; ++i)
					putchar(ans[i]);
				cout << endl;
			}
			else
				cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}