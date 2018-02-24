#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int vis[10010];
int main(){
	ifstream in("C:\\temp.txt");
	int Z, I, M, L;
	int CASE = 1;
	while (cin >> Z >> I >> M >> L&&Z + I + M + L){
		memset(vis, 0, sizeof(vis));
		int ans = 1;
		vis[L] = ans;
		while (1){
			L = (Z*L + I) % M;
			ans++;
			if (vis[L])
				break;
			vis[L] = ans;
		
		}
		printf("Case %d: %d\n", CASE++, ans-vis[L]);
	}

	return 0;
}