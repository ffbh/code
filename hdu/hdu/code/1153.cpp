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
using namespace std;

vector<int> vi;
int N, ans;
bool mark[100010];
int h[100010];

void Init(){
	ans = 0;
	memset(mark, 0, sizeof(mark));
}

void bfs(int m){
	queue<int> qi;
	for (int i = 1; i <= N; ++i){
		h[i*m % (N + 1)] = i;
	}
	for (int i = 1; i <= N;++i)
	if (mark[i])
		qi.push(i);
	while (!qi.empty()){
		int u = qi.front();
		qi.pop();
		if (!mark[h[u]]){
			ans++;
			mark[h[u]] = 1;
			qi.push(h[u]);
		}
	}
}

bool judgeP(int n){
	for (int i = 2; i <= sqrt(n);++i)
	if (n%i == 0)
		return 0;
	return 1;
}

int main(){
	ifstream in("C:\\input.txt");
	for (int i = 1; i*i <= 100000; ++i)
		vi.push_back(i*i);
	/*for (int k = 99859; k <= 100000; ++k){
		if (!judgeP(k))
			continue;
		N = k;
		cout << k << endl;*/
	while (cin >> N && N){
		if (N == 2){
			cout << "Impossible" << endl;
			continue;
		}
		N--;
		Init();
		for (int i = 0;i<vi.size()&& vi[i] <= N; ++i){
			mark[vi[i]] = 1;
			ans++;
		}
		int pos = 1;
		while (ans < N / 2 && pos < vi.size()){
			bfs(vi[pos]);
			pos++;
		}
	
		if (ans == N / 2){
			
		//	cout << k ;

			for (int i = 1; i <= N; ++i){
				if (mark[i]){
					putchar('0');
				}
				else
					putchar('1');
			}
			cout << endl;
		}
		else{
			cout << "Impossible"<<endl;
		}

	}
	return 0;
}