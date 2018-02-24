#include <iostream>
#include <string>
#include <fstream>
#include <queue>
using namespace std;

int data[101];
int num[10];


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	int N, M;
	cin >> T;
	while (T--){
		cin >> N >> M;
		memset(num, 0, sizeof(num));
		for (int i = 0; i < N; ++i){
			cin >> data[i];
			num[data[i]]++;
		}
		int K = data[M];
		int ans = 0;
		int end = 0;
		for (int k = 9; k>K;--k)
		if (num[k]){
			ans += num[k];
			int temp = 0;
			for (int i = end;temp<num[k]; ++i){
				if (i == N)
					i = 0;
				if (data[i] == k){
					temp++;
					end = i;
				}
			}
		}
		for (int i = end;; ++i){
			if (i == N)
				i = 0;
			if (data[i] == K)
				ans++;
			if (i == M)
				break;
		}
		cout << ans << endl;
	}
	return 0;
}