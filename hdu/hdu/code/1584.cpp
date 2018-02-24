#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Link{
	int next;
	int pre;
};
Link link[15];
int num[15];
bool vis[15];
int ans;

void DFS(int n, int res){

	for (int i = 1; i <= 10; ++i)
	if (!vis[i] && num[i] != 10){
		vis[i] = 1;
		int tnext = link[i].next;
		int tpre = link[i].pre;
		int w = abs(tnext - i);
		int temp1 = link[tpre].next;
		int temp2 = link[tnext].pre;
		link[tpre].next = tnext;
		link[tnext].pre = tpre;
		if (res + w >= ans){
			link[tpre].next = temp1;
			link[tnext].pre = temp2;
			vis[i] = 0;
			continue;
		}
		if (n == 9) ans = res + w;
		else
			DFS(n + 1, res + w);
		link[tpre].next = temp1;
		link[tnext].pre = temp2;;
		vis[i] = 0;
	}
}


int main(){
	ifstream in("C:\\temp.txt");
	int T;
	cin >> T;
	while (T--){
		for (int i = 1; i <= 10; ++i)
			cin >> num[i];
		ans = INT_MAX;
		memset(vis, 0, sizeof(vis));
		memset(link, 0, sizeof(link));
		for (int i = 1; i <= 10; ++i)
		for (int j = 1; j <= 10; ++j)
		if (num[i] + 1 == num[j]){
			link[i].next = j;
			link[j].pre = i;
		}

		DFS(1, 0);
		cout << ans << endl;
	}





	return 0;
}