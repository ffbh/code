#include <iostream>
#include <fstream>
using namespace std;
bool vis[10010];
int main(){
	ifstream in("C:\\temp.txt");
	int N;
	while (cin >> N){
		memset(vis, 0, sizeof(vis));
		if (N % 2 == 0){
			printf("2^? mod %d = 1\n", N);
			continue;
		}
		int ans = -1;
		int kk = 1;
		for (int i = 1;; ++i){
			kk *= 2;
			kk %= N;
			if (kk == 1){
				ans = i;
				break;
			}
			if (vis[kk])break;
			vis[kk] = 1;
		}
		if (ans==-1)
			printf("2^? mod %d = 1\n", N);
		else
			printf("2^%d mod %d = 1\n", ans,N);
	
	}

	return 0;
}