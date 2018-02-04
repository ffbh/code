#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool vis[30];
int ans[14];

int main(){
	ifstream in("C:\\temp.txt");
	for (int K = 1; K<14; ++K){
		int M;
		for (M = K + 1;; ++M){
			int num = 2 * K;
			int nn = 0;
			memset(vis, 0, sizeof(vis));
			for (int i = 1; num > K; ++i){
				if (i == 2 * K + 1)
					i = 1;
				if (!vis[i]){
					nn++;
					if (nn == M){
						if (i > K){
							vis[i] = 1;
							num--;
						}
						else
							break;
						nn = 0;
					}
				}
			}
			if (num <= K)
				break;
		}
		ans[K] = M;
	}
	int N;
	while (cin >> N&&N)
		cout << ans[N] << endl;

	return 0;
}