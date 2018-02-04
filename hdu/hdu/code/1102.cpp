//kruskalÀ„∑®
/*#include <iostream>
//#include <fstream>
#include <queue>
using namespace std;
int village[101][101];
int vis[101];
struct line {
	int x, y;
	int value;
	bool operator<(const line& ll)const{
		return value > ll.value;
	}
};
priority_queue<line> pl;
int N,Q;
int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N){
		memset(vis, 0, sizeof(vis));
		memset(village, 0, sizeof(village));
		for (int i = 1; i <= N;++i)
		for (int j = 1; j <= N; ++j)
			//in >> village[i][j];
			scanf("%d", &village[i][j]);
		cin >> Q;
		int index,r;
		for (int i = 0; i < Q; ++i){
			//in >> index >> r;
			scanf("%d%d", &index, &r);
			village[index][r] = 0;
			village[r][index] = 0;
		}
		line ll;
		for (int i = 1; i <= N;++i)
		for (int j = i + 1; j <= N; ++j){
			ll.value = village[i][j];
			ll.x = i;
			ll.y = j;
			pl.push(ll);
		}
		int ans=0;
		int ff = 1;
		while (!pl.empty()){
			ll = pl.top();
			pl.pop();
			int a = vis[ll.x];
			int b = vis[ll.y];
			if (a == b&&a!=0)
				continue;
			else if (a != 0 && b != 0){
				for (int kk = 1; kk <= N;++kk)
				if (vis[kk] == b)
					vis[kk] = a;
			}
			else if (a == 0 && b == 0){
				vis[ll.x] = ff;
				vis[ll.y] = ff;
				ff++;
			}
			else{
				int nn = a > b ? a : b;
				vis[ll.x] = nn;
				vis[ll.y] = nn;
			}
			ans += ll.value;
		}
		cout << ans << endl;
	
	}

	return 0;
}*/
//primÀ„∑®
#include <iostream>
//#include <fstream>
using namespace std;
int village[101][101];
bool vis[101];


int N,Q;
int main(){
	//ifstream in("C:\\temp.txt");
	while (cin >> N){
		memset(vis, 0, sizeof(vis));
		memset(village, 0, sizeof(village));
		for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			//cin >> village[i][j];
			scanf("%d", &village[i][j]);
		cin >> Q;
		int index, r;
		for (int i = 0; i < Q; ++i){
			//in >> index >> r;
			scanf("%d%d", &index, &r);
			village[index][r] = 0;
			village[r][index] = 0;
		}
		for (int i = 0; i < 101; ++i)
			village[i][i] = INT_MAX;
		int low[101] , pos, ans = 0;
		memset(low, INT_MAX , sizeof(low));
		pos = 1;
		vis[pos] = 1;
		int min = INT_MIN;
		for (int i = 1; i <= N;++i)
		if (i != pos)
			low[i] = village[pos][i];
		for (int i = 1; i < N; ++i){
			min = INT_MAX;
			for (int j = 1; j <= N;++j)
			if (min>low[j] && !vis[j]){
				min = low[j];
				pos = j;
			}
			vis[pos] = 1;
			ans += low[pos];
			for (int j = 1; j <= N;++j)
			if (low[j] > village[pos][j])
				low[j] = village[pos][j];
		}
		cout << ans << endl;

		
		
		

	}

	return 0;
}